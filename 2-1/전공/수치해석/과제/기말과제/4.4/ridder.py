import error
import math
from numpy import sign
def ridder(f,a,b,tol=1.0e-9):
    fa = f(a)
    if fa==0.0: return a
    fb = f(b)
    if fb == 0.0: return b
    for i in range(30):
        c = 0.5*(a+b);fc = f(c)
        s = math.sqrt(fc**2 - fa*fb)
        if s==0.0: return None
        dx = (c-a)*fc/s
        if(fa-fb) <0.0: dx = -dx
        x = c+dx; fx=f(x)
        if i>0:
            if abs(x-xOld) < tol*max(abs(x),1.0):
                print("반복:",i+1)
                return x
        xOld = x
        if sign(fc) == sign(fx):
            if sign(fa)!=sign(fx): b= x; fb = fx
            else : a=x;fa=fx
        else :
            a=c;b=x;fa=fc;fb=fx
    return None
    print('too many iterations')