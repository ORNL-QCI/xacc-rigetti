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
#ifndef QUANTUM_GATE_ACCELERATORS_RIGETTIACCELERATOR_HPP_
#define QUANTUM_GATE_ACCELERATORS_RIGETTIACCELERATOR_HPP_

#include "Accelerator.hpp"
#include "InstructionIterator.hpp"
#include "QuilVisitor.hpp"
#include "RuntimeOptions.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

using namespace xacc;

namespace xacc {
namespace quantum {

/**
 * The RigettiAccelerator is a QPUGate Accelerator that
 * provides an execute implementation that maps XACC IR
 * to an equivalent Quil string, and executes it on the
 * Rigetti superconducting quantum chip at api.rigetti.com/qvm
 * through Fire's HTTP Client utilities.
 *
 */
class RigettiAccelerator : virtual public Accelerator {
public:

	/**
	 * Create, store, and return an AcceleratorBuffer with the given
	 * variable id string and of the given number of bits.
	 * The string id serves as a unique identifier
	 * for future lookups and reuse of the AcceleratorBuffer.
	 *
	 * @param varId
	 * @param size
	 * @return
	 */
	std::shared_ptr<AcceleratorBuffer> createBuffer(const std::string& varId,
			const int size);

	virtual std::shared_ptr<AcceleratorBuffer> createBuffer(
				const std::string& varId);

	virtual void initialize() {

	}
	/**
	 * Return true if this Accelerator can allocated
	 * NBits number of bits.
	 * @param NBits
	 * @return
	 */
	virtual bool isValidBufferSize(const int NBits);

	/**
	 * Execute the kernel on the provided AcceleratorBuffer through a
	 * HTTP Post of Quil instructions to the Rigetti QPU at api.rigetti.com/qvm
	 *
	 * @param ir
	 */
	virtual void execute(std::shared_ptr<AcceleratorBuffer> buffer,
			const std::shared_ptr<xacc::Function> kernel);

	/**
	 * Execute a set of kernels with one remote call. Return
	 * a list of AcceleratorBuffers that provide a new view
	 * of the given one AcceleratorBuffer. The ith AcceleratorBuffer
	 * contains the results of the ith kernel execution.
	 *
	 * @param buffer The AcceleratorBuffer to execute on
	 * @param functions The list of IR Functions to execute
	 * @return tempBuffers The list of new AcceleratorBuffers
	 */
	virtual std::vector<std::shared_ptr<AcceleratorBuffer>> execute(
			std::shared_ptr<AcceleratorBuffer> buffer,
			const std::vector<std::shared_ptr<Function>> functions);

	/**
	 * This Accelerator models QPU Gate accelerators.
	 * @return
	 */
	virtual AcceleratorType getType() {
		return AcceleratorType::qpu_gate;
	}

	/**
	 * We have no need to transform the IR for this Accelerator,
	 * so return an empty list, for now.
	 * @return
	 */
	virtual std::vector<std::shared_ptr<IRTransformation>> getIRTransformations() {
		std::vector<std::shared_ptr<IRTransformation>> v;
		return v;
	}

	/**
	 * Return all relevant RigettiAccelerator runtime options.
	 * Users can set the api-key, execution type, and number of triels
	 * from the command line with these options.
	 */
	virtual std::shared_ptr<options_description> getOptions() {
		auto desc = std::make_shared<options_description>(
				"Rigetti Accelerator Options");
		desc->add_options()("rigetti-api-key", value<std::string>(),
				"Provide the Rigetti Forest API key. This is used if $HOME/.pyquil_config is not found")("rigetti-type",
				value<std::string>(),
				"Provide the execution type: multishot, wavefunction, "
				"multishot-measure, ping, or version.")
				("rigetti-trials", value<std::string>(), "Provide the number of trials to execute.");
		return desc;
	}

	RigettiAccelerator() {
	}

	virtual const std::string name() const {
		return "rigetti";
	}

	virtual const std::string description() const {
		return "The Rigetti Accelerator interacts with "
				"the Forest QVM to execute quantum IR.";
	}

	/**
	 * The destructor
	 */
	virtual ~RigettiAccelerator() {}

private:

	/**
	 * Private utility to search for the Rigetti
	 * API key in $HOME/.pyquil_config, $PYQUIL_CONFIG,
	 * or --api-key command line arg
	 */
	void searchAPIKey(std::string& key, std::string& id);

	/**
	 * Private utility to search for key in the config
	 * file.
	 */
	void findApiKeyInFile(std::string& key, std::string& id, boost::filesystem::path &p);

};

}
}




#endif
