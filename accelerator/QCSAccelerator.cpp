/***********************************************************************************
 * Copyright (c) 2018, UT-Battelle
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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
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
#include "QCSAccelerator.hpp"
#include <algorithm>
#include <pybind11/embed.h>
#include "CountGatesOfTypeVisitor.hpp"
#include <pybind11/numpy.h>

#include <chrono>

using namespace std;
using namespace std::chrono;

namespace py = pybind11;
using namespace py::literals;

namespace xacc {
namespace quantum {

std::shared_ptr<AcceleratorBuffer>
QCSAccelerator::createBuffer(const std::string &varId) {
  auto buffer = std::make_shared<AcceleratorBuffer>(varId, 30);
  storeBuffer(varId, buffer);
  return buffer;
}

std::shared_ptr<AcceleratorBuffer>
QCSAccelerator::createBuffer(const std::string &varId, const int size) {
  std::shared_ptr<AcceleratorBuffer> buffer;
  buffer = std::make_shared<AcceleratorBuffer>(varId, size);
  storeBuffer(varId, buffer);
  return buffer;
}

bool QCSAccelerator::isValidBufferSize(const int NBits) {
  return NBits > 0;
}

void QCSAccelerator::execute(
    std::shared_ptr<AcceleratorBuffer> buffer,
    const std::shared_ptr<Function> function) {
  auto visitor = std::make_shared<QuilVisitor>(true);

  auto backend = xacc::optionExists("qcs-backend") ? xacc::getOption("qcs-backend") : "9q-generic-qvm";
  auto shots = xacc::optionExists("qcs-shots") ? std::stoi(xacc::getOption("qcs-shots")) : 1000;

  std::map<int,int> bitToQubit;
  InstructionIterator it(function);
  while (it.hasNext()) {
    // Get the next node in the tree
    auto nextInst = it.next();
    if (nextInst->isEnabled()) {
      nextInst->accept(visitor);
      if (nextInst->name() == "Measure") {
        bitToQubit.insert({boost::get<int>(nextInst->getParameter(0)), nextInst->bits()[0]});
      }
    }
  }

  // Create our usual old Quil string, but
  // then hack it to fit the new DECLARE stuff
  CountGatesOfTypeVisitor<Measure> count(function);
  int nMeasures = count.countGates();
  auto quilStr = visitor->getQuilString();
  boost::replace_all(quilStr, "[", "ro[");
  quilStr = "DECLARE ro BIT[" + std::to_string(nMeasures) + "]\n" + quilStr;

  std::shared_ptr<py::scoped_interpreter> guard;
  if (!xacc::isPyApi) {
     guard = std::make_shared<py::scoped_interpreter>();
  }

//   py::print("quil:\n", quilStr);
  auto pyquil = py::module::import("pyquil");
  py::object get_qc = pyquil.attr("get_qc");
  auto program = pyquil.attr("Program")();
  program.attr("inst")(quilStr);
  program.attr("wrap_in_numshots_loop")(shots);

  auto qc = get_qc(backend);

  auto compiled = qc.attr("compile")(program);
  py::array_t<int> results = qc.attr("run")(compiled);

//   py::print(results);
  std::string zeroString = "";
  for (int i = 0; i < buffer->size(); i++) zeroString += "0";

   for (int i = 0; i < shots; i++) {
       std::string bitString = zeroString;
       for (int j = 0; j < nMeasures; j++) {
          auto qbit = bitToQubit[j];
          std::stringstream s;
          s << *results.data(i,j);
          bitString[buffer->size()-1-qbit] = s.str()[0];
       }
       buffer->appendMeasurement(bitString);
   }

    return;
}

std::vector<std::shared_ptr<AcceleratorBuffer>> QCSAccelerator::execute(
    std::shared_ptr<AcceleratorBuffer> buffer,
    const std::vector<std::shared_ptr<Function>> functions) {

    std::vector<std::shared_ptr<AcceleratorBuffer>> tmpBuffers;
    for (auto f : functions) {
      auto tmpBuffer = createBuffer(f->name(),
                                    buffer->size());

      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      execute(tmpBuffer, f);
      high_resolution_clock::time_point t2 = high_resolution_clock::now();

      auto duration = duration_cast<microseconds>( t2 - t1 ).count();
      tmpBuffer->addExtraInfo("exec-time", ExtraInfo(duration*1e-6));
      tmpBuffers.push_back(tmpBuffer);
    }

    return tmpBuffers;
}

} // namespace quantum
} // namespace xacc
