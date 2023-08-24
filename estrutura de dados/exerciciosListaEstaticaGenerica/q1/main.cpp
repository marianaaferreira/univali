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
