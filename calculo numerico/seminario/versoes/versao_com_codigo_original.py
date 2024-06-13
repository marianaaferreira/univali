import numpy as np
import matplotlib.pyplot as plt
def spline (x, y):
    n = len(x)
    a = {k: v for k, v, in enumerate(y)}
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

    c = dict(zip(range(n), np.linalg.solve(A,B)))

    b = {}
    d = {}
    for k in range(n-1):
        b[k] = (1/h[k])*(a[k+1]-a[k])-(h[k]/3)*(2*c[k]+c[k+1])
        d[k] = (c[k+1] -c[k])/(3*h[k])

    s = {}
    for k in range(n-1):
        eq = f'{a[k]}+{b[k]}*(x-{x[k]})+{c[k]}*(x-{x[k]})**2{d[k]:+}*(x-{x[k]})**3'
        s[k] = {'eq': eq, 'dominio': [x[k], x[k+1]]}

    return s

x = []
y = []
z = []

x.append([3.15, 6, 7.99])  # xA
y.append([0, 2, 2.42])  # yA
z.append([96, 96, 96])

x.append([0, 2.7, 5.12, 7.89])  # xB
y.append([2, 3.19, 3.35, 4.45])  # yB
z.append([97, 97, 97, 97])

x.append([0, 2.64, 6.37, 7.92])  # xC
y.append([4.48, 5.38, 5.8, 6.57])  # yC
z.append([98, 98, 98, 98])

x.append([0, 2.74, 4.44])  # xD
y.append([6.28, 7.12, 7.86])  # yD
z.append([99, 99, 99])

Se = []
for i in range(0, 4):
    Se.append(spline(x[i], y[i]))

for i in range(len(Se)):
    print(Se[i])

for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x):
            return eval(value['eq'])
        t = np.linspace(*value['dominio'], 100)
        plt.plot(t, p(t))
    plt.scatter(x[i], y[i])
plt.savefig('spline.png')