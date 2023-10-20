#include <iostream>
#include "FilaDePrioridade.h"

using namespace std;

int main(){
    FilaDePrioridade<int> fila;
    char prioridade[3]={'A', 'B', 'M'};
    cria(fila);
    int n=0;

    cout << "insere 1 p=A" << endl;
    insere(fila, 1, 'A');
    mostra(fila);

    cout << "insere 3 p=B" << endl;
    insere(fila, 3, 'B');
    mostra(fila);

    cout << "insere 2 p=M" << endl;
    insere(fila, 2, 'M');
    mostra(fila);

    cout << "insere 4 p=A" << endl;
    insere(fila, 4, 'A');
    mostra(fila);

    cout << "retira 1 elementos" << endl;
    retira(fila);
    mostra(fila);

    cout << "retira 1 elemento" << endl;
    retira(fila);
    mostra(fila);

    destroi(fila);

    /*
    for(int i=2; i<6; i++){
        insere(fila, i, prioridade[n]);
        n++;
        if(n>2)n=0;
    }*/
    mostra(fila);

    return 0;
}
