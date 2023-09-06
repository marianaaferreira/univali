#include <iostream>
#include "listaDuplamenteEncadeada.h"
//testes lista duplamente encadeada
using namespace std;

int main(){
    ListaDuplamenteEncadeada<int> lista;
    crialista(lista);

    for(int i=1; i<4; i++){
        try{
            insere(lista, i, i);
        }catch(const char* e){
            cerr << "ERRO: " << e << endl;
        }

    }
    mostralista(lista);
    if(estaVazia(lista)) cout << "lista vazia"; else cout << "lista nao vazia"; cout << endl;

    cout << "qtd de elementos: " << qtdElementos(lista) << endl;

    if(elementoEstaNaLista(lista, 1)) cout << "1 esta na lista"; else cout << "1 nao esta na lista"; cout << endl;
    if(elementoEstaNaLista(lista, 5)) cout << "5 esta na lista"; else cout << "5 nao esta na lista"; cout << endl;

    cout << "recuperando elemento da posicao 7 e 2"<< endl;
    try{
        cout << "elemento posicao 7: " << recuperaElemento(lista, 7) << endl;
    }catch(const char* e){
        cerr << "ERRO: " << e << endl;
    }
    try{
        cout << "elemento posicao 2: " << recuperaElemento(lista, 2) << endl;
    }catch(const char* e){
        cerr << "ERRO: " << e << endl;
    }

    cout << "recuperando posicao do elemento 3 e 10" << endl;
    if(elementoEstaNaLista(lista, 3)) cout << "posicao do elemento 3:" << recuperaPosicao(lista, 3) << endl;
    else cout << "elemento nao esta na lista" << endl;
    if(elementoEstaNaLista(lista, 10)) cout << "posicao do elemento 10:" << recuperaPosicao(lista, 10) << endl;
    else cout << "elemento nao esta na lista" << endl;

    cout << "qtd elementos: " << qtdElementos(lista) << endl;
    cout << "-------testes insere-------" << endl;
    mostralista(lista); cout << endl;
    insere(lista, 4, qtdElementos(lista)+1); // insere no final
    mostralista(lista); cout << endl;
    insere(lista, 0, 1); //insere no inicio
    mostralista(lista); cout << endl;
    insere(lista, 555, 3); //insere no meio
    mostralista(lista); cout << endl;
    cout << "---------------------------" << endl;
    cout << "qtd elementos: " << qtdElementos(lista) << endl;

    cout << "excluindo elemento 555" << endl;
    excluiElemento(lista, recuperaPosicao(lista, 555));
    mostralista(lista); cout << endl;
    cout << "qtd elementos: " << qtdElementos(lista) << endl;
    cout << "excluindo primeira e ultima posicao" << endl;
    excluiElemento(lista, 1); excluiElemento(lista, qtdElementos(lista));
    mostralista(lista); cout << endl;
    cout << "qtd elementos: " << qtdElementos(lista) << endl;

    destroilista(lista);

    return 0;
}
