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
        b[k] = (1/h[k]) * (a[k+1] - a[k]) - (h[k]/3) * (2*c[k] + c[k+1])
        d[k] = (c[k+1] - c[k]) / (3*h[k])

    s = {}
    for k in range(n-1):
        eq = f'{a[k]} + {b[k]} * (x - {x[k]}) + {c[k]} * (x - {x[k]})**2 + {d[k]:+} * (x - {x[k]})**3'
        s[k] = {'eq': eq, 'dominio': [x[k], x[k+1]]}

    return s

x = []
y = []

x.append([0.53, 3.04, 5.43, 7.85, 9.56]) # xA
y.append([0.48, 1.45, 2.59, 2.74, 3.78]) # yA

x.append([0.44, 2.43, 4.45, 6.87, 8.67, 9.65]) # xB
y.append([3.14, 3.23, 4.27, 4.42, 4.82, 5]) # yB

x.append([0.47, 3.1, 4.82, 6.96, 8.55, 9.74]) # xC
y.append([5.92, 5.59, 5.8, 6.38, 6.29, 6.72]) # yC

x.append([0.35, 2.61, 5.06, 7.33, 9.65]) # xD
y.append([6.93, 7.79, 8.68, 9.63, 9.78]) # yD

fig = plt.figure(figsize=(17, 6))
ax = fig.add_subplot(121, projection='3d')

Se = []
for i in range(0, 4):
    Se.append(spline(x[i], y[i]))

for i in range(len(Se)):
    for key, value in Se[i].items():
        def p(x):
            return eval(value['eq'])
        t = np.linspace(*value['dominio'], 100)
        z = np.full_like(t, i)  # Adding cota as the z-value
        if key == 0:
            ax.plot(t, p(t), z, label=f"S{i}")
        else:
            ax.plot(t, p(t), z)
    ax.scatter(x[i], y[i], zs=i, zdir='z')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Cota')

# Subplot 3D Surface
ax2 = fig.add_subplot(122, projection='3d')
new_x = np.linspace(0, 10, 100)
new_y = np.linspace(0, 10, 100)
new_x, new_y = np.meshgrid(new_x, new_y)
new_z = np.sin(new_x) + np.cos(new_y)
ax2.plot_surface(new_x, new_y, new_z, cmap='viridis')
ax2.set_title('Modelo Digital de Terreno Interpolado')

plt.tight_layout()
plt.savefig('spline_3d.png')
plt.show()
