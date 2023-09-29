#include <iostream>
#include "ListaEstaticaGenerica.h"

using namespace std;

int main(){
    ListaEstaticaGenerica<int, 18> lista;

    cria(lista);

    for (int i=1; i<18; i++){
        insereNoIncio(lista, i);
    }
    cout << exibeLista(lista);

    return 0;
}
