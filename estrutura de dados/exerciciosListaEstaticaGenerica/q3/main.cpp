#include <iostream>
#include "ListaEstaticaGenerica.h"

using namespace std;
//3. Faça uma rotina para retornar o menor e o maior elemento de uma lista ListaEstaticaGenerica.

string maiorEMenorElemento(ListaEstaticaGenerica<int, 10> lista, int tam){
    int maior=recuperaElemento(lista, 0), menor=recuperaElemento(lista, 0);
    for(int i=1; i<tam; i++){
        if (recuperaElemento(lista, i)>maior)
            maior = recuperaElemento(lista, i);
        if(recuperaElemento(lista, i)<menor)
            menor = recuperaElemento(lista, i);
    }
    return "Maior: " + to_string(maior) + "\nMenor: " + to_string(menor);
}

int main(){
    ListaEstaticaGenerica<int, 10> l;
    int n=10;

    for(int i=0; i<n; i++){
        insere(l, i, rand()%10);
    }

    exibeLista(l);
    cout << maiorEMenorElemento(l, n);

    return 0;
}
