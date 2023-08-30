from ridder import*
def f(x):
    a = x**3
    b = 10*(x**2)
    return a - b + 5
t = ridder(f,0.6,0.8)
print(t)
print("f(x)=",f(t))