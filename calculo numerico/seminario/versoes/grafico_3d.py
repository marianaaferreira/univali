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
    for k in range(n - 1):
        b[k] = (1 / h[k]) * (a[k + 1] - a[k]) - (h[k] / 3) * (2 * c[k] + c[k + 1])
        d[k] = (c[k + 1] - c[k]) / (3 * h[k])

    s = {}
    for k in range(n - 1):
        s[k] = {
            'a': a[k],
            'b': b[k],
            'c': c[k],
            'd': d[k],
            'x_k': x[k],
            'dominio': [x[k], x[k + 1]]
        }

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
for i in range(4):
    Se.append(spline(x[i], y[i]))

fig = plt.figure(figsize=(14, 7))

# Plot 2D splines
ax1 = fig.add_subplot(121)
for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x_val, a, b, c, d, x_k):
            return a + b * (x_val - x_k) + c * (x_val - x_k)**2 + d * (x_val - x_k)**3
        t = np.linspace(*value['dominio'], 100)
        t_array = np.array(t)
        y_vals = p(t_array, value['a'], value['b'], value['c'], value['d'], value['x_k'])
        ax1.plot(t, y_vals)
    ax1.scatter(x[i], y[i])
ax1.set_title('Curvas de nível')

# Plot 3D splines
ax2 = fig.add_subplot(122, projection='3d')
for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x_val, a, b, c, d, x_k):
            return a + b * (x_val - x_k) + c * (x_val - x_k)**2 + d * (x_val - x_k)**3
        t = np.linspace(*value['dominio'], 100)
        t_array = np.array(t)
        y_vals = p(t_array, value['a'], value['b'], value['c'], value['d'], value['x_k'])
        z_vals = np.interp(t, x[i], z[i])  # Interpolando valores de z para os pontos t
        ax2.plot(t, y_vals, z_vals)
    ax2.scatter(x[i], y[i], z[i])
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_zlabel('Z')
ax2 = fig.add_subplot(122, projection='3d')
new_x = np.linspace(0, 10, 100)
new_y = np.linspace(0, 10, 100)
new_x, new_y = np.meshgrid(new_x, new_y)
new_z = np.sin(new_x) + np.cos(new_y)
ax2.plot_surface(new_x, new_y, new_z, cmap='viridis')
ax2.set_title('Modelo Digital de Terreno Interpolado')

plt.savefig('spline_3d.png')
plt.show()
