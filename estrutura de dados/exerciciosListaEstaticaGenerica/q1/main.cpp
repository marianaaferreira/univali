#include <iostream>
#include "ListaEstaticaGenerica.h"

using namespace std;
/*1. Elabore um programa para exibir a evolu��o observada no pre�o (inteiro) da a��o de uma determinada
empresa com cota��o inicial aleat�ria entre [5, 7].
A varia��o no pre�o da a��o ocorre aleatoriamente no intervalo de [-3, +3].
Considere o tempo decorrido entre 09h �s 15h para realizar a simula��o.
A cada 20 minutos, exiba a evolu��o do pre�o da a��o.
Utilize a estrutura de dados ListaEstaticaGenerica para representar o pre�o da a��o.*/
int main(){
    ListaEstaticaGenerica<int, 18> lista;

    cria(lista);
    insere(lista, 0, rand()%3+5);

    for (int i=1; i<18; i++){
        insere(lista, qtdElementos(lista), recuperaElemento(lista, qtdElementos(lista)-1)+rand()%7-3);
    }

    exibeLista(lista);
}
