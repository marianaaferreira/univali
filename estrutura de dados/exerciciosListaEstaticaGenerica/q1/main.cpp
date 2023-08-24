#include <iostream>
#include "ListaEstaticaGenerica.h"

using namespace std;
/*1. Elabore um programa para exibir a evolução observada no preço (inteiro) da ação de uma determinada
empresa com cotação inicial aleatória entre [5, 7].
A variação no preço da ação ocorre aleatoriamente no intervalo de [-3, +3].
Considere o tempo decorrido entre 09h às 15h para realizar a simulação.
A cada 20 minutos, exiba a evolução do preço da ação.
Utilize a estrutura de dados ListaEstaticaGenerica para representar o preço da ação.*/
int main(){
    ListaEstaticaGenerica<int, 18> lista;

    cria(lista);
    insere(lista, 0, rand()%3+5);

    for (int i=1; i<18; i++){
        insere(lista, qtdElementos(lista), recuperaElemento(lista, qtdElementos(lista)-1)+rand()%7-3);
    }

    exibeLista(lista);
}
