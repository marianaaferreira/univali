#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;
//1. Desenvolva uma rotina para verificar se todos os elementos de uma fila se encontram em outra fila (não
//necessariamente na mesma posição).


int main(){
    FilaEstaticaGenerica<int, 15> filaA;
    FilaEstaticaGenerica<int, 15> filaB;
    bool existe = false, elementosIguais=true;

    srand(time(NULL));
    cria(filaA);
    cria(filaB);

    for(int i=0; i<10; i++){
        insere(filaA, rand()%10);
        insere(filaB, rand()%10);
    }

    mostra(filaA);
    mostra(filaB);

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(existeElemento(filaB, umElemento(filaA, j)))
                existe = true;
        }
        if(not existe){
            elementosIguais=false; break;
        }
    }

    if(elementosIguais)
        cout << "As duas filas possuem os mesmos elementos";
    else
        cout << "As filas possuem elementos diferentes";

    return 0;
}
