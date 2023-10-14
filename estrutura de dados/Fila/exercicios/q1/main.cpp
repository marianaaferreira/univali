#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;
//1. Desenvolva uma rotina para verificar se todos os elementos de uma fila se encontram em outra fila (não
//necessariamente na mesma posição).


int main(){
    FilaEstaticaGenerica<int, 15> filaA;
    FilaEstaticaGenerica<int, 15> filaB;
    bool existeA, existeB, elementosIguais=true;

    srand(time(NULL));
    cria(filaA);
    cria(filaB);

    for(int i=0; i<10; i++){
        insere(filaA, rand()%10);
        insere(filaB, rand()%10);
    }

    mostra(filaA);
    mostra(filaB);

    for(int i=1; i<=10; i++){
        existeA = false;
        for(int j=1; j<=10; j++)
            if(existeElemento(filaB, umElemento(filaA, j)))
                existeA = true;
        existeB = false;
        for(int j=1; j<=10; j++)
            if(existeElemento(filaA, umElemento(filaB, j)))
                existeB = true;

        if(not existeA or not existeB){
            elementosIguais=false; break;
        }
    }

    if(elementosIguais)
        cout << "As duas filas possuem os mesmos elementos";
    else
        cout << "As filas possuem elementos diferentes";

    return 0;
}
