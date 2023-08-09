def mostraElemento(msg, i, lista):
    print(msg, lista[i])

def incluiElemento(n, lista):
    elemento = input("Informe o valor:\n")
    lista.append(elemento)
    n = n + 1
    return n


