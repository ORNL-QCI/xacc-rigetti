/***********************************************************************************
 * Copyright (c) 2017, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include "RigettiAccelerator.hpp"
#include <boost/filesystem.hpp>
#include <algorithm>

namespace xacc {
namespace quantum {

std::shared_ptr<AcceleratorBuffer> RigettiAccelerator::createBuffer(
			const std::string& varId) {
	auto buffer = std::make_shared<AcceleratorBuffer>(varId, 30);
	storeBuffer(varId, buffer);
	return buffer;

}

std::shared_ptr<AcceleratorBuffer> RigettiAccelerator::createBuffer(
		const std::string& varId, const int size) {
	std::shared_ptr<AcceleratorBuffer> buffer;
	buffer = std::make_shared<AcceleratorBuffer>(varId, size);
	storeBuffer(varId, buffer);
	return buffer;
}

bool RigettiAccelerator::isValidBufferSize(const int NBits) {
	return NBits > 0;
}
const std::string RigettiAccelerator::processInput(
                std::shared_ptr<AcceleratorBuffer> buffer,
                std::vector<std::shared_ptr<Function>> functions) {
	// Get the runtime options map, and initialize
	// some basic variables we are going to need
	std::string type = "multishot-measure";
	std::string jsonStr = "", apiKey = "", userId = "";
	std::string trials = "100", backend = "QVM";

	// Search for the API key
	searchAPIKey(apiKey, userId);

	// Create the Instruction Visitor that is going
	// to map our IR to Quil.
	auto visitor = std::make_shared<QuilVisitor>(false);

	headers.insert(std::make_pair("Content-type", "application/json; charset=utf-8"));
	headers.insert(std::make_pair("X-Api-Key", apiKey));
	headers.insert(std::make_pair("X-User-Id", userId));
	headers.insert(std::make_pair("Connection", "keep-alive"));
	headers.insert(std::make_pair("Accept-Encoding", "gzip, deflate"));
	headers.insert(std::make_pair("Accept", "application/octet-stream"));

	remoteUrl = "https://job.rigetti.com";
	postPath = "/beta/job";

	if (xacc::optionExists("rigetti-backend")) {
		backend = xacc::getOption("rigetti-backend");
	}

	if (xacc::optionExists("rigetti-trials")) {
		trials = xacc::getOption("rigetti-trials");
	}

	if (functions.size() > 1)
		xacc::error("RigettiAccelerator can only launch one job at a time.");


	InstructionIterator it(functions[0]);
	while (it.hasNext()) {
		// Get the next node in the tree
		auto nextInst = it.next();
		if (nextInst->isEnabled()) {
			nextInst->accept(visitor);
			if (nextInst->name() == "Measure") {
				currentMeasurementSupports.push_back(nextInst->bits()[0]);
			}
		}
	}

	std::string measuredQubitsString = "[";
	for (auto m : visitor->getMeasuredQubits()) {
		measuredQubitsString += std::to_string(m) + ",";
	}
	measuredQubitsString = measuredQubitsString.substr(0,measuredQubitsString.length()-1) + "]";

	auto quilStr = visitor->getQuilString();
	boost::replace_all(quilStr, "\n", "\\n");

	// Create the Json String
	jsonStr += "{ \"type\" : \"" + type + "\", \"qubits\" : "
			+ measuredQubitsString + ", \"trials\" : " + trials + ", \"quil-instructions\" : \""
			+ quilStr
			+ "\"}";

	if (backend != "QVM") {
		jsonStr = "{\"machine\": \"QPU\", \"program\": " + jsonStr
				+ ", \"device\": \"" + backend + "\"}";
	} else {
		jsonStr = "{\"machine\": \""+backend+"\", \"program\": " + jsonStr
						+ "}";
	}

	// Check that the qpu is online
	if (backend != "QVM") {
		std::string deviceResponse = handleExceptionRestClientGet(remoteUrl, "/beta/devices", headers);
		Document d;
		d.Parse(deviceResponse);
		bool is_online = d["devices"][backend]["is_online"].GetBool();
		bool is_retuning = d["devices"][backend]["is_retuning"].GetBool();
		while(!is_online && !is_retuning) {
			xacc::info(backend + " is retuning or offline. Please wait");
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			deviceResponse = handleExceptionRestClientGet(remoteUrl, "/beta/devices", headers);
			d.Parse(deviceResponse);
			is_online = d["devices"][backend]["is_online"].GetBool();
			is_retuning = d["devices"][backend]["is_retuning"].GetBool();
		}
	}
	return jsonStr;
}

std::vector<std::shared_ptr<AcceleratorBuffer>> RigettiAccelerator::processResponse(
                std::shared_ptr<AcceleratorBuffer> buffer,
                const std::string& response) {
	Document document;
	document.Parse(response);

	auto jobId = std::string(document["jobId"].GetString());

	std::string getPath = "/beta/job/" + jobId;
	std::string getResponse = handleExceptionRestClientGet(remoteUrl, getPath, headers);

	// Loop until the job is complete,
	// get the JSON response
	std::string msg;
	bool jobCompleted = false;
	while (!jobCompleted) {

		if (boost::contains(getResponse, "FINISHED")) {
			jobCompleted = true;
		}

		// Execute HTTP Get
		getResponse = handleExceptionRestClientGet(remoteUrl, getPath, headers);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	document.Parse(getResponse);

	const Value& results = document["result"];

	std::map<std::string, int> counts;
	for (SizeType i = 0; i < results.Size(); i++) {
		// Here we are mapping rigetti bit strings 
		// to ibm-like bit strings - msb and nQubits bits
		std::string bitString = "";
		for (int i = 0; i < buffer->size(); ++i) bitString += "0";

		for (SizeType j = 0; j < results[i].Size(); ++j) {
			bitString.replace(buffer->size() - currentMeasurementSupports[j] - 1, 1, std::to_string(results[i][j].GetInt()));
		}

		if (counts.find(bitString) != counts.end()) {
			counts[bitString]++;
		} else {
			counts.insert(std::make_pair(bitString,1));
		}
	}

	for (auto& kv : counts) {
		boost::dynamic_bitset<> b(kv.first);
		buffer->appendMeasurement(b, kv.second);
	}

	currentMeasurementSupports.clear();

	return std::vector<std::shared_ptr<AcceleratorBuffer>> {buffer};
}

void RigettiAccelerator::searchAPIKey(std::string& key, std::string& userid) {

	// Search for the API Key in $HOME/.pyquil_config,
	// $PYQUIL_CONFIG, or in the command line argument --api-key
	auto options = RuntimeOptions::instance();
	boost::filesystem::path pyquilConfig(
			std::string(getenv("HOME")) + "/.pyquil_config");
	if (boost::filesystem::exists(pyquilConfig)) {
		findApiKeyInFile(key, userid, pyquilConfig);
	} else if (const char * nonStandardPath = getenv("PYQUIL_CONFIG")) {
		boost::filesystem::path nonStandardPyquilConfig(
						nonStandardPath);
		findApiKeyInFile(key, userid, nonStandardPyquilConfig);
	} else {

		// Ensure that the user has provided an api-key
		if (!options->exists("rigetti-api-key")) {
			xacc::error("Cannot execute kernel on Rigetti chip without API Key.");
		}

		// Set the API Key
		key = (*options)["rigetti-api-key"];

		if (options->exists("rigetti-user-id")) {
			userid = (*options)["rigetti-user-id"];
		}
	}

	// If its still empty, then we have a problem
	if (key.empty()) {
		xacc::error("Error. The API Key is empty. Please place it "
				"in your $HOME/.pyquil_config file, $PYQUIL_CONFIG env var, "
				"or provide --api-key argument.");
	}
}

void RigettiAccelerator::findApiKeyInFile(std::string& apiKey, std::string& id,
		boost::filesystem::path &p) {
	std::ifstream stream(p.string());
	std::string contents(
			(std::istreambuf_iterator<char>(stream)),
			std::istreambuf_iterator<char>());

	std::vector<std::string> lines;
	boost::split(lines, contents, boost::is_any_of("\n"));
	for (auto l : lines) {
		if (boost::contains(l, "key")) {
			std::vector<std::string> split;
			boost::split(split, l, boost::is_any_of(":"));
			auto key = split[1];
			boost::trim(key);
			apiKey = key;
		} else if (boost::contains(l, "user_id")) {
			std::vector<std::string> split;
			boost::split(split, l, boost::is_any_of(":"));
			auto userId = split[1];
			boost::trim(userId);
			id = userId;
		}
	}
}
}
}

