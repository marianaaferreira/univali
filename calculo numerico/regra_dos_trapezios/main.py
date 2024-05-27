import math

def trapz(f, a, b, n):
    h=(b-a)/n
    soma = 0
    for k in range(1, n):
        soma +=(f(a+k*h))
    soma *= 2
    soma += (f(a)+f(b))
    return (h/2)*soma

def f(x):
    return math.exp(-x**2)

a, b = 0, 1
n= 100000 #numero de pontos na partição

r = trapz(f, a, b, n)
print(r)

def g(x):
    return math.cos(x**2)

a=0
b=math.pi/2

n=100000

r=trapz(g, a, b, n)
print(r)