#include "XACC.hpp"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(pyxaccrigetti, m) {
  m.doc() =
      "Python bindings for XACC. XACC provides a plugin infrastructure for "
      "programming, compiling, and executing quantum kernels in a language and "
      "hardware agnostic manner.";
}
