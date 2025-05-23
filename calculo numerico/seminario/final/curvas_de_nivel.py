import numpy as np
import matplotlib.pyplot as plt

def spline(x, y):
    n = len(x)
    a = {k: v for k, v in enumerate(y)}
    h = {k: x[k + 1] - x[k] for k in range(n - 1)}

    A = [[1] + [0] * (n - 1)]
    for i in range(1, n - 1):
        linha = [0] * n
        linha[i - 1] = h[i - 1]
        linha[i] = 2 * (h[i - 1] + h[i])
        linha[i + 1] = h[i]
        A.append(linha)
    A.append([0] * (n - 1) + [1])

    B = [0]
    for k in range(1, n - 1):
        linha = 3 * (a[k + 1] - a[k]) / h[k] - 3 * (a[k] - a[k - 1]) / h[k - 1]
        B.append(linha)
    B.append(0)

    c = dict(zip(range(n), np.linalg.solve(A, B)))

    b = {}
    d = {}
    for k in range(n-1):
        b[k] = (1 / h[k]) * (a[k + 1] - a[k]) - (h[k] / 3) * (2 * c[k] + c[k + 1])
        d[k] = (c[k + 1] - c[k]) / (3 * h[k])

    s = {}
    for k in range(n - 1):
        eq = f'{a[k]}+{b[k]}*(x-{x[k]})+{c[k]}*(x-{x[k]})**2{d[k]:+}*(x-{x[k]})**3'
        s[k] = {'eq': eq, 'dominio': [x[k], x[k + 1]]}

    return s

x = []
y = []

#cota 96
x.append([3.15, 4, 5, 6, 7, 8])  # xA
y.append([0, 1, 1.5, 2, 2.2, 2.42])  # yA

#cota 97
x.append([0, 1, 2.7, 3.5, 5.12, 6.5, 7.89])  # xB
y.append([2, 2.5, 3.19, 3.25, 3.35, 4, 4.45])  # yB

#cota 98
x.append([0, 1.5, 2.64, 4, 6.37, 7.2, 7.92])  # xC
y.append([4.48, 5, 5.38, 5.5, 5.8, 6, 6.57])  # yC

#cota 99
x.append([0, 1, 2.74, 3.5, 4.44])  # xD
y.append([6.28, 6.5, 7.12, 7.5, 7.86])  # yD

Se = []
for i in range(4):
    Se.append(spline(x[i], y[i]))

plt.figure(figsize=(10, 8))
colors = ['blue', 'orange', 'green', 'red']
labels = ['Cota 96', 'Cota 97', 'Cota 98', 'Cota 99']

for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x):
            return eval(value['eq'])
        t = np.linspace(*value['dominio'], 100)
        plt.plot(t, p(t), color=colors[i])
    plt.scatter(x[i], y[i], color=colors[i], label=labels[i])

plt.legend()
plt.title('Curvas de Nível')
plt.grid(True)
plt.savefig('spline.png')
plt.show()