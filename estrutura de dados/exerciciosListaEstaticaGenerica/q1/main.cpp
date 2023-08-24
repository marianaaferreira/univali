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
    int preco, p;

    cria(lista);

    do{
        preco = rand()%10;
    }while(preco>7 or preco<5);

    insere(lista, 0, preco);

    for (int i=1; i<18; i++){
        do{
            p = rand()%10;
        }while(p>3 or p<1);
        if(i%2==0) p = p*(-1);
        insere(lista, qtdElementos(lista), preco+p);
    }
    exibeLista(lista);
}
