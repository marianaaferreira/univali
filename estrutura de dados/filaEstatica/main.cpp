#include <iostream>
#include "filaEstatica.h"

using namespace std;

int main(){

    FilaEstatica<int, 10> fila;

    for(int i=0; i<6; i++)
        insere(fila, i+1);

    exibe(fila);

    return 0;
}
