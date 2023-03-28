import numpy as np
import math
def choleski(a):
    n = len(a)
    for k in range(n):
        try:
            a[k, k] = math.sqrt(a[k, k]  - np.dot(a[k, 0:k], a[k, 0:k]))
        except ValueError:
            print('Matrix is not positive definitve')
        for i in range(k+1,n):
            a[i,k] = (a[i,k] - np.dot(a[i,0:k],a[k,0:k]))/a[k,k]
        for k in range(1,n):
            a[0:k,k] = 0.0
    return a

def choleskiSol(L,b):
    n = len(b)
    for k in range(n):
        b[k] = (b[k] - np.dot(L[k,0:k],b[0:k]))/L[k,k]

    for k in range(n-1,-1,-1):
        b[k] = b[k] = (b[k] - np.dot(L[k+1:n,k],b[k+1:n]))/L[k,k]
    return b

a = np.array([[ 1.44, -0.36, 5.52, 0.0], [-0.36, 10.33, -7.78, 0.0],  [ 5.52, -7.78, 28.40, 9.0], [ 0.0, 0.0, 9.0, 61.0]])
b = np.array([0.04, -2.15, 0.0, 0.88])
L = choleski(a)
x = choleskiSol(L,b)