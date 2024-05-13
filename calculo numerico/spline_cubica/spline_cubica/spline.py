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

x.append([1.67, 1.9, 2.15]) #xA
y.append([4.56, 4.74, 4.87]) #yA

x.append([2.15, 2.52, 2.35]) #xB
y.append([4.87, 5.58, 5.23]) #yB

x.append([2.35, 2.5, 2.54, 2.72, 3.2, 3.74, 4.13, 4.5, 5.01, 5.95, 6.67, 7.73, 8.77, 9.36]) #xC
y.append([5.23, 6, 6.42, 6.86, 7.32, 7.45, 7.65, 7.73, 8.2, 8.74, 9.09, 9.49, 9.67, 9.71]) #yC

x.append([9.36, 9.73, 10.42, 10.11, 11.14, 12.49, 14.5, 16.67, 18.43, 19.39, 20.03]) #xD
y.append([9.71, 10.27, 10.93, 10.71, 11.2, 11.61, 12, 11.55, 10.77, 9.54, 7.92]) #yD

x.append([20.03, 20.75, 21.22, 21.72, 21.86]) #xE
y.append([7.92, 7.57, 7.02, 5.44, 5.1]) #yE

plt.figure(figsize=(17,6))

Se = []
for i in range(0, 5):
    Se.append(spline(x[i], y[i]))

for i in range(len(Se)):
    print(Se[i])

for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x):
            return eval(value['eq'])
        t = np.linspace(*value['dominio'], 100)
        if key == 0:
            plt.plot(t, p(t), label=f"S{i}")
        else:
            plt.plot(t, p(t))
    plt.scatter(x[i], y[i])
plt.legend()
plt.savefig('spline.png')