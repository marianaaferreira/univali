import math


def simps(f, a, b, n):
    h = (b-a)/n
    soma_odd, soma_even = 0, 0
    for k in range(1, n, 2):
        soma_odd += f(a+k*h)
    for k in range(2, n, 2):
        soma_even += f(a+k*h)
    return (h/3)*(f(a) +4*soma_odd+2*soma_even +f(b))

def f(x):
    return math.exp(-x**2)
a, b = 0, 1
n = 1000 # n é o número de subintervalos e o n /2 é o número de parábolas e o n + 1 é o número de pontos na partição

i1 = simps(f, a, b, n)

def g(x):
    return math.cos(x**2)
a, b = 0, math.pi /2
n = 200000

i2 = simps(g, a, b, n)

print(i1)
print(abs(i1 - 0.746824132812427026))

print(i2)


'''
def simps(f, a, b, n):
    if n % 2 != 0 or n < 1:
        raise ValueError("N deve ser par e maior que 1")
    h = (b-a)/n
    soma_odd, soma_even = 0, 0
    for k in range(1, n, 2):
        soma_odd += f(a+k*h)
    for k in range(2, n, 2):
        soma_even += f(a+k*h)
    return (h/3)*(f(a) +4*soma_odd+2*soma_even +f(b))
'''