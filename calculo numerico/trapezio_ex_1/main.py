import math

def f(x):
    return math.exp(x)

def trapz(f, a, b, n):
    h = (b - a) / n
    soma = 0
    for k in range(1, n):
        soma += f(a + k * h)
    soma *= 2
    soma += (f(a) + f(b))
    return (h / 2) * soma

# Parte (a): Calcule uma aproximação utilizando 10 subintervalos
a, b = 0, 1
n = 10
aproximacao = trapz(f, a, b, n)
valor_exato = math.exp(1) - 1  # Integral de e^x de 0 a 1
erro = abs(valor_exato - aproximacao)

print(f"Aproximação com 10 subintervalos: {aproximacao}")
print(f"Erro estimado: {erro}")

# Parte (b): Determinar o número mínimo de subdivisões para que o erro seja inferior a 10^-3
tolerancia = 1e-3
n = 10  # Começamos com 10 subintervalos e aumentamos conforme necessário

while True:
    aproximacao = trapz(f, a, b, n)
    erro = abs(valor_exato - aproximacao)
    if erro < tolerancia:
        break
    n += 1

print(f"Número mínimo de subintervalos para erro inferior a 10^-3: {n}")

