#include <iostream>
#include "ListaEstaticaGenerica.h"

using namespace std;
//2. Elabore uma rotina para ordenar os elementos de uma lista ListaEstaticaGenerica

void ordenaLista(ListaEstaticaGenerica<int, 10> lista){
    for(int i=0; i<qtdElementos()-1, i++)
        for(int j=i; j<qtdElementos(), j++)
            if(recuperaElemento(lista, i)>recuperaElemento(lista, j)){
                    temp = recuperaElemento(lista, i);
                    retiraPelaPosicao(lista, i); insere(lista, i, recuperaElemento(lista, j));
                    retiraPelaPosicao(lista, j); isere(lista, j, temp);
            }
}

int main(){
    ListaEstaticaGenerica<int, 10> lista;

    for(int i=0; i<10; i++){
        insere(lista, i, rand()%10);
    }
    exibeLista(lista);
    ordenaLista(lista);
    //ordena(lista);
    exibeLista(lista);

    return 0;
}
