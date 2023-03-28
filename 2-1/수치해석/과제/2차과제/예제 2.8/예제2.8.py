import numpy as np
from choleski import *
from choleski import *
a = np.array([[ 1.44, -0.36, 5.52, 0.0], [-0.36, 10.33, -7.78, 0.0], [ 5.52, -7.78, 28.40, 9.0], [ 0.0, 0.0, 9.0, 61.0]])
b = np.array([0.04, -2.15, 0.0, 0.88])
aOrig = a.copy()
L = choleski(a)
x=choleskiSol(L,b)
print("x = ", x)
print('\nCheck: A*x=\n', np.dot(aOrig,x))