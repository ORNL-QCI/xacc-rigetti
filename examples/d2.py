import sys
import numpy as np
import pyxacc as xacc
from pyxacc import InstructionParameter
import pyxaccvqe as vqe
from pyxaccvqe import PauliOperator

xacc.Initialize(['--compiler','quil'])

ham = PauliOperator(5.906709445) + PauliOperator({0:'X',1:'X'}, -2.1433) + PauliOperator({0:'Y',1:'Y'}, -2.1433) + PauliOperator({0:'Z'}, .21829) + PauliOperator({1:'Z'}, -6.125)

print('\nH_{2x2} = ', ham)

src = """__qpu__ f(AcceleratorBuffer ab, double t0) {
X 0
RY(t0) 1
CNOT 1 0
}"""
p = xacc.Program(xacc.getAccelerator('tnqvm'),src)
print('Program built python')
k = p.getKernel('f')
print('Got Kernel')
ansatz = k.getIRFunction()
print('Ansztz = ', ansatz.name())
print('Ansatz = \n', ansatz.toString('q'))

angle_range = np.linspace(-np.pi,np.pi,50)

vqeResult = vqe.execute(ham, **{'task':'vqe', 'ansatz':ansatz})
print('(Optimal Angle, Energy) = (', vqeResult.angles, ',', vqeResult.energy, ')')
print('Number of QPU Calls = ', vqeResult.nQpuCalls)
print('Number of VQE Iterations = ', vqeResult.vqeIterations)

