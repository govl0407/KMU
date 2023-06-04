import numpy as np
def LUdecomp(a):# doolittle분해
    n = len(a)
    for k in range(0,n-1):
        for i in range(k+1,n):
            if a[i,k] != 0.0:
                lam = a [i,k]/a[k,k]
                a[i,k+1:n] = a[i,k+1:n] - lam*a[k,k+1:n] #상 삼각행렬
                a[i,k] = lam #승수값으로 하 삼각행렬 만들기
    return a
def LUsolve(a,b): #해를 구하는 과정
    n = len(a)
    for k in range(1,n):
        b[k] = b[k] - np.dot(a[k,0:k],b[0:k])
    b[n - 1] = b[n-1]/a[n-1,n-1]
    for k in range(n-2,-1,-1):
        b[k] = (b[k]- np.dot(a[k,k+1:n],b[k+1:n]))/a[k,k]
    return b
