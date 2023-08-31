#include <iostream>
#include "listaSimplesmenteEncadeada.h"

using namespace std;

int main(){
    ListaSimplesmenteEncadeada<int> lista;
    cout << "inserindo 9\n";
    insere(lista, 9, 0);
    exibeLista(lista);
    cout << "inserindo 8 no inicio\n";
    insere(lista, 8, 0);
    exibeLista(lista);
    cout << "inserindo 5 no final\n";
    insere(lista, 5, qtdElementos(lista));
    exibeLista(lista);

    destroilista(lista);

    return 0;
}
