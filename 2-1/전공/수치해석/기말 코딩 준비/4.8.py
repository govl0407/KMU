import numpy as np
import math
from newtonRaphson import*
def f(x):
    f = np.zeros(len(x))
    f[0] = x[0]**2 -x[0]*x[1] + x[0]**2 -4 #방정식 x^2 -xy +y^2 -4
    f[1] = x[0]*x[1] -1 #방정식 x*y -1
    return f
x = np.array([1.0,1.0])# x,y의 초기값
print("초기값: ",x)
print("교점의 좌표: ",newtonRaphson2(f,x))