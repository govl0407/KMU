import numpy as np
from LUdecomp3 import*

n=6
d = np.ones(n)*2.0
e = np.ones(n-1)*(-1.0)
c = e.copy()
d[n-1] = 5.0
aInv = np.identity(n)

A = [[2,-1,0,0,0,0],[-1,2,-1,0,0,0],[0,-1,2,-1,0,0],[0,0,-1,2,-1,0],[0,0,0,-1,2,-1],[0,0,0,0,-1,5]]
I = np.identity(n) #원래 행렬과 역행렬의 곱을 저장할 배열

c,d,e = LUdecomp3(c,d,e)

print(aInv[:,0])
for i in range(n):
    aInv[:,i] = LUsolve3(c,d,e,aInv[:,i])

print("\nThe inverse matrix is:\n",aInv)
I = np.dot(A,aInv)
print("\n A*X :\n",I)

