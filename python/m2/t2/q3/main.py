'''. Faça um programa em que o usuário possa inserir números em uma lista. O programa deve ter ações
para apresentar o primeiro elemento da lista; o último elemento da lista; e quantos elementos da lista
existem entre o primeiro e o último. As funções que acessam ou incluem elementos na lista devem
ser definidas em arquivo separado, e ser importado como módulo do arquivo principal do programa.
Faça os tratamentos apropriados para quando a lista estiver vazia ou contiver apenas um elemento.
(2.5pt)
'''
import funcoes as m1
lista = [1]
resp = ''
n = 0
while resp != 'E':
    print("A. Mostrar primeiro elemento da lista\n")
    print("B. Mostrar ultimo elemento da lista\n")
    print("C. Qtd elemento entre o primeiro e o ultimo\n")
    print("D. Inserir elemento novo\n")
    print("E. sair")
    resp = input("O que deseja fazer?\n")
    resp = resp.upper()

    if resp == 'A':
        if (n >= 0):
            m1.mostraElemento("Primeiro elemento da lista:\n", 0, lista)
        else:
            print("Lista vazia")

    elif resp == 'B':
        if(n>=0):
            m1.mostraElemento("Ultimo elemento da lista:\n", n-1, lista)
        else:
            print("Lista vazia")

    elif resp == 'C':
        if (n>=2):
            print("Existem ", n-2, " elementos entre o primeiro e o ultimo")
        elif(n>0):
            print("Existe apenas um elemento na lista")
        else:
            print("Lista vazia")

    elif resp == 'D':
        n = m1.incluiElemento(n, lista)