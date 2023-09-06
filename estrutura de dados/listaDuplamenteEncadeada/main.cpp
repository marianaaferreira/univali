#include <iostream>
#include "listaDuplamenteEncadeada.h"

using namespace std;

int main(){
    ListaDuplamenteEncadeada<int> lista;
    crialista(lista);
    /*
    for(int i=0; i<3; i++){
        try{
            insere(lista, i, i+1);
        }catch(const char* e){
            cout << "ERRO " << e << endl;
        }

    }
    mostralista(lista);*/
    insere(lista, 1, 1);
    mostralista(lista);
    //erro ao adicionar na segunda posicao
    insere(lista, 2, 2);
    mostralista(lista);

    return 0;
}
