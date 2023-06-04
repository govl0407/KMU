import numpy as np
from fractions import Fraction

def LUdecomp3(c, d, e):
    n = len(d)
    for k in range(1, n):
        lam = c[k - 1] / d[k - 1]
        d[k] = d[k] - lam * e[k - 1]
        c[k - 1] = lam
    return c, d, e

def LUsolve3(c, d, e, b):
    n = len(d)
    for k in range(1, n):
        b[k] = b[k] - c[k-1]*b[k-1]
    b[n-1] = b[n-1]/d[n-1]
    for k in range(n-2, -1, -1):
        b[k] = (b[k] - e[k]*b[k+1])/d[k]
    return b

n = 6
d = np.ones(n) * 2
e = np.ones(n - 1) * (-1)
c = e.copy()
d[-1] = 5

# aInv 는 분수형식으로 계산할 것이므로, np.identity 대신 Fraction으로 새로운 n x n 행렬을 만듭니다.
aInv = np.array([[Fraction(int(i == j), 1) for j in range(n)] for i in range(n)])

A = np.array([
    [2, -1, 0, 0, 0, 0],
    [-1, 2, -1, 0, 0, 0],
    [0, -1, 2, -1, 0, 0],
    [0, 0, -1, 2, -1, 0],
    [0, 0, 0, -1, 2, -1],
    [0, 0, 0, 0, -1, 5]
], dtype=float)

c, d, e = LUdecomp3(c, d, e)

for i in range(n):
    aInv[:, i] = LUsolve3(c, d, e, aInv[:, i])

print("\nThe inverse matrix is:\n", aInv)
I = np.dot(A, aInv)
print("\n A*X :\n", I)
