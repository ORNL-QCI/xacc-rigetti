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
#include "SimulatedQubits.hpp"
#include <boost/filesystem.hpp>
#include <fstream>
#include <iomanip>
#include <codecvt>
#include <memory>
#include "GateQIR.hpp"
#include "XACC.hpp"

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

#define RAPIDJSON_HAS_STDSTRING 1

#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"

using namespace rapidjson;

namespace xacc {
namespace quantum {

std::shared_ptr<AcceleratorBuffer> RigettiAccelerator::createBuffer(
			const std::string& varId) {
	if (!isValidBufferSize(30)) {
		XACCError("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer;
	if ((*RuntimeOptions::instance())["rigetti-type"] == "wavefunction") {
		buffer = std::make_shared<SimulatedQubits>(varId, 30);
	} else {
		buffer = std::make_shared<AcceleratorBuffer>(varId, 30);
	}

	storeBuffer(varId, buffer);
	return buffer;

}

std::shared_ptr<AcceleratorBuffer> RigettiAccelerator::createBuffer(
		const std::string& varId, const int size) {
	if (!isValidBufferSize(size)) {
		XACCError("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer;
	if ((*RuntimeOptions::instance())["rigetti-type"] == "wavefunction") {
		buffer = std::make_shared<SimulatedQubits>(varId, size);
	} else {
		buffer = std::make_shared<AcceleratorBuffer>(varId, size);
	}

	storeBuffer(varId, buffer);
	return buffer;
}

bool RigettiAccelerator::isValidBufferSize(const int NBits) {
	return NBits > 0 && NBits < 31;
}

void RigettiAccelerator::execute(std::shared_ptr<AcceleratorBuffer> buffer,
		const std::shared_ptr<xacc::Function> kernel) {

	// Get the runtime options map, and initialize
	// some basic variables we are going to need
	auto options = RuntimeOptions::instance();
	std::string type = "multishot";
	std::string jsonStr = "", apiKey = "", userId = "";
	std::string trials = "10";
	std::map<std::string, std::string> headers;

	// Create the Instruction Visitor that is going
	// to map our IR to Quil.
	auto visitor = std::make_shared<QuilVisitor>();

	// Our QIR is really a tree structure
	// so create a pre-order tree traversal
	// InstructionIterator to walk it
	InstructionIterator it(kernel);
	while (it.hasNext()) {
		// Get the next node in the tree
		auto nextInst = it.next();
		if (nextInst->isEnabled()) nextInst->accept(visitor);
	}

	// Search for the API key
	searchAPIKey(apiKey, userId);

	// Set the execution type if the user provided it
	if (options->exists("rigetti-type")) {
		type = (*options)["rigetti-type"];
	}

	// Set the trials number if user provided it
	if (options->exists("rigetti-trials")) {
		trials = (*options)["rigetti-trials"];
	}

	if (type.empty()) {
		type = "multishot";
	}

	// Construct the JSON payload string
	if (type == "ping") {
		jsonStr += "{ \"type\" : \"ping\" }";
	} else if (type == "version") {
		jsonStr += "{ \"type\" : \"version\" }";
	} else if (type == "pyquillow") {

		// Gotta do a post, then a get for this one
		jsonStr = "{\"machine\": \"QPU\", \"program\": {\"qcid\": 5, "
				"\"stop\": 1.0, \"start\": 0.0, \"step\": 0.04, "
				"\"experiment\": \"rabi\", \"time\": 100.0, \"type\": "
				"\"pyquillow\", \"device_id\": \"Z12-13-C4a2\"}, "
				"\"userId\": \""+userId+"\", \"results\": \"\", "
						"\"jobId\": \"\"}";

	} else {

		// Get the quil instructions
		auto quilStr = visitor->getQuilString();
		boost::replace_all(quilStr, "\n", "\\n");

		// Create the Json String
		jsonStr += "{ \"type\" : \"" + type + "\", \"addresses\" : "
				+ visitor->getClassicalAddresses()
				+ ", \"quil-instructions\" : \"" + quilStr
				+ (type == "wavefunction" ? "\"" : "\", \"trials\" : " + trials)
				+ " }";

	}

	// Set up the extra HTTP headers we are going to need
	headers.insert(std::make_pair("Content-type", "application/json"));
	headers.insert(std::make_pair("Accept", "application/octet-stream"));
	headers.insert(std::make_pair("x-api-key", apiKey));
	headers.insert(std::make_pair("x-user-id", userId));

	XACCInfo("Rigetti Json Payload = " + jsonStr);

//	std::cout << "JSON:\n" << jsonStr << "\n";

	// Execute the HTTP Post!
	auto relativePath = type == "pyquillow" ? "/beta/job" : "/qvm";

	// Create the URI, HTTP Client and Post and Get request
	// add our headers to it - this contains the API key
	std::string url = "https://api.rigetti.com";
	auto runtimeOptions = RuntimeOptions::instance();
	if (xacc::optionExists("rigetti-type")
			&& xacc::getOption("rigetti-type") == "pyquillow") {
		url = "https://job.rigetti.com";
	}

	http::uri uri = http::uri(url);
	http_client postClient(
			http::uri_builder(uri).append_path(U(relativePath)).to_uri());
	http_request postRequest(methods::POST), getRequest(methods::GET);
	for (auto& kv : headers) {
		postRequest.headers().add(kv.first, kv.second);
		getRequest.headers().add(kv.first, kv.second);
	}
	postRequest.set_body(jsonStr);

	// Post the problem, get the response as json
	auto postResponse = postClient.request(postRequest);
	auto respJson = postResponse.get().extract_string().get();//.extract_json().get();

	// Map that response to a string
	std::stringstream ss;
	ss << respJson;


	if (type == "wavefunction") {
		XACCError("Wavefunction execution not supported.");
	} else if (type == "pyquillow") {

		std::string message = ss.str();

		Document document;
		document.Parse(message.c_str());

		auto jobId = std::string(document["jobId"].GetString());

		// Create a client to execute HTTP Get requests
		http_client getClient(
				http::uri_builder(uri).append_path(U("/beta/job/" + jobId)).to_uri());

		bool finished = false;
		while(!finished) {

			// Execute HTTP Get
			auto getResponse = getClient.request(getRequest);

			std::stringstream ss2;
			ss2 << getResponse.get().extract_json().get();
			message = ss.str();

			if (boost::contains(message, "result")) {
				finished = true;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		document.Parse(message.c_str());

		auto results = std::string(document["result"].GetString());

		auto first = results.find_first_of("]");
		auto xAxisStr = results.substr(1, first);
		auto yAxisStr = results.substr(first+2, results.length());

		boost::replace_all(xAxisStr, "]", "");
		boost::replace_all(xAxisStr, "[", "");
		boost::replace_all(yAxisStr, "]", "");
		boost::replace_all(yAxisStr, "[", "");

		std::vector<std::string> splitX, splitY;
		boost::split(splitX, xAxisStr, boost::is_any_of(","));
		boost::split(splitY, yAxisStr, boost::is_any_of(","));

		std::ofstream csvFile("rabiOscillation.csv");
		csvFile << "# ResponseAmplitude, PulseAmplitude\n";
		for (int i = 0; i < splitX.size(); i++) {
			boost::trim(splitX[i]);
			boost::trim(splitY[i]);
			csvFile << std::stod(splitX[i]) << ", " << std::stod(splitY[i]) << "\n";
		}

		csvFile.close();

	} else if (type == "multishot") {
	       
		  std::stringstream oss;
		  
		  std::string resp_str = ss.str();
		  XACCInfo("Rigetti Response Str:\n" + resp_str + "\n");

		  int i_qbit = -1;
		  boost::dynamic_bitset<> outcome(visitor->getNumberOfAddresses());
		  for(int i=0; i<resp_str.size(); ++i){
		    char c = resp_str[i];
		    if (c=='['){ // begin of a measurement
		      i_qbit = 0;
		      outcome.reset();
		      continue;
		    }

		    if (i_qbit>0 && c==']'){ // end of a measurement
		      // i_qbit>0 assure some results collected outcome
		      oss<<outcome<<std::endl; // debug
		      buffer->appendMeasurement(outcome);
		      i_qbit = -1; 
		      continue;
		    }

		    if(c=='1'||c=='0'){
		      outcome[i_qbit] = (c=='1');
		      i_qbit++;
		    }
		  }

		  
		  oss<<">>>>>>>>>>>>>"<<std::endl;
		  for(std::string tmp; std::getline(ss,tmp,','); ){
		    oss<<tmp<<std::endl;
		  }

	} else if (type == "ping" || type == "version") {
		XACCInfo("Rigetti QVM Response:\n\t" + ss.str());
	} else {
		// do nothing
	}

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
			XACCError("Cannot execute kernel on Rigetti chip without API Key.");
		}

		// Set the API Key
		key = (*options)["rigetti-api-key"];

		if (options->exists("rigetti-user-id")) {
			userid = (*options)["rigetti-user-id"];
		}
	}

	// If its still empty, then we have a problem
	if (key.empty()) {
		XACCError("Error. The API Key is empty. Please place it "
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
//
//
//// What to do with this???
//auto roundToNextMultiple = [](int n, int m) -> int {
//	return ((n + m - 1) / m) * m;
//};
//
//auto getBits = [](auto o) -> std::bitset<8> {
//    if  (!(0 <= o <= 255)) XACCError("invalid byte");
//    std::bitset<8> bits;
//    for (int i = 0; i < 8; i++) {
//        if (1 == o & 1) {
//            bits[i] = 1;
//        }
//        o = o >> 1;
//    }
//    return bits;
//};
//
//int numOctets = postResponse.contentLength;
//int numAddresses = visitor->getNumberOfAddresses();
//int numMemoryOctets = roundToNextMultiple(numAddresses, 8) / 8;
//int numWFOctets = numOctets - numMemoryOctets;
//
//assert(numWFOctets / 16 == std::pow(2, buffer->size()));
//
//std::cout << "NUM MEM OCT: " << numMemoryOctets << ", " << numAddresses << ", " << numWFOctets << "\n";
//std::vector<int> temp;
//for (int i = 0; i < numMemoryOctets; i++) {
//	auto bits = getBits(buf[i]);
//	for (int j = 0; j < 8; j++) {
//		temp.push_back(bits[j]);
//	}
//}
//
//std::vector<int> mem(temp.begin(), temp.begin() + numAddresses);
//
//std::cout << "Classical Measurements: ";
//for (auto i : mem) {
//	std::cout << i << " ";
//}
//std::cout << "\n";
//
//union Converter { uint64_t i; double d; };
//
//auto getDouble = [&] (std::bitset<64> const& bs) -> double{
//    Converter c;
//    c.i = bs.to_ullong();
//    return c.d;
//};
//
//int p = numMemoryOctets;
//while (p < numOctets) {
//
//	// Get subset of the binary buffer
//	char re_be[8], im_be[8];
//	std::memcpy(re_be, &buf[p], sizeof(double));
//	std::memcpy(im_be, &buf[p+8], sizeof(double));
//
//	auto re = *reinterpret_cast<double*>(re_be);
//	auto im = *reinterpret_cast<double*>(im_be);
//
//	std::cout << p << ": " << "(" << re << ", " << im << ")\n";
//
//	p+=16;
//
//}

/*
 * def recover_complexes(coef_string):
    num_octets = len(coef_string)
    num_addresses = len(classical_addresses)
    num_memory_octets = _round_to_next_multiple(num_addresses, 8) // 8
    num_wavefunction_octets = num_octets - num_memory_octets

    # Parse the classical memory
    mem = []
    for i in range(num_memory_octets):
        # Python 3 oddity: indexing coef_string with a single
        # index returns an int. If you request a slice it keeps
        # it as a bytestring.
        octet = struct.unpack('B', coef_string[i:i+1])[0]
        mem.extend(_octet_bits(octet))

    mem = mem[0:num_addresses]

    # Parse the wavefunction
    wf = np.zeros(num_wavefunction_octets // OCTETS_PER_COMPLEX_DOUBLE, dtype=np.cfloat)
    for i, p in enumerate(range(num_memory_octets, num_octets, OCTETS_PER_COMPLEX_DOUBLE)):
        re_be = coef_string[p: p + OCTETS_PER_DOUBLE_FLOAT]
        im_be = coef_string[p + OCTETS_PER_DOUBLE_FLOAT: p + OCTETS_PER_COMPLEX_DOUBLE]
        re = struct.unpack('>d', re_be)[0]
        im = struct.unpack('>d', im_be)[0]
        wf[i] = complex(re, im)
 */
