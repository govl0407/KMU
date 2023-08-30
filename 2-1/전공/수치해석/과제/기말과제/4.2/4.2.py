from bisection import*
def f(x): return x**3 - 10.0*x**2 + 5.0
x = bisection(f,0.0,1.0,tol=1.0e-4)
print('x=','{:6.4f}'.format(x))
