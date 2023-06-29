import calculaDistanciaEntreDoisPontos as m1
p1 = [0, 0]
p2 = [0, 0]

def leiaCoordenada(p):
    p[0] = float(input("x:"))
    p[1] = float(input("y:"))
print("Ponto 1:\n")
leiaCoordenada(p1)
print("Ponto 2:\n")
leiaCoordenada(p2)

d = m1.calculaDistancia(p1[0], p1[1], p2[0], p2[1])

print("distancia:\n", d)