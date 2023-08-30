import numpy as np
from gaussPivot import*
import math

def newtonRaphson2(f,x,tol=1.0e-9):#방정식, 변수, 오차
    def jacobian(f,x): #자코비안 행렬 계산
        h = 1.0e-4
        n = len(x)
        jac = np.zeros((n,n))
        f0 = f(x)
        for i in range(n):
            temp = x[i]
            x[i] = temp+h
            f1 = f(x)
            x[i] = temp
            jac[:,i] = (f1-f0)/h
        return jac, f0

    for i in range(3):#반복횟수
        jac, f0 = jacobian(f,x)
        if(i<3):
            print(i,"번째 자코비안",jac)
        if math.sqrt(np.dot(f0,f0)/len(x)) < tol: return x
        dx = gaussPivot(jac,-f0)#델타 x,y
        x = x + dx #개선된 교차점
        if math.sqrt(np.dot(dx,dx))< tol*max(max(abs(x)),1.0): # 개선된 교차점이 범위 내에 들어오면
            return x
    return x

    print("too mant iterations")