#include <iostream>
#include "listaEstatica.h"

using namespace std;

void menu(){
    cout << "O que deseja fazer?" << endl;
    cout << "A. Inserir elemento no inicio da lista" << endl;
    cout << "B. Inserir elemento no final da lista" << endl;
    cout << "C. Inserir elemento na posicao informada" << endl;
    cout << "D. Retirar elemento da lista" << endl;
    cout << "E. Visualizar lista" << endl;
    cout << "F. Sair" << endl;
}

int main(){
    Lista l;
    char op;
    int elemento, posicao;
    do{
        cin.ignore(); menu(); cin.get(op); op = toupper(op);
        switch(op){
            case 'A':
                cout << "Informe o elemento:\n"; cin >> elemento;
                insereNoIncio(l, elemento); break;
            case 'B':
                cout << "Informe o elemento:\n"; cin >> elemento;
                insereNoFinal(l, elemento); break;
            case 'C':
                cout << "Informe a posicao(0 a " << qtdElementosLista(l) << "):\n"; cin >> posicao;
                if(not verificaPosicaoValida(l, posicao))
                    cout << "Posicao invalida" << endl;
                else{
                    cout << "Informe o elemento:\n"; cin >> elemento;
                    insereNaPosicao(l, elemento, posicao);
                }break;
            case 'D':
                cout << "Informe o elemento:\n"; cin >> elemento;
                if(verificaElementoLista(l, elemento))
                    retiraElementoLista(l, elemento);
                else
                    cout << "Elemento nao encontrado. Impossivel excluir";
                break;
            case 'E':
                cout << exibeLista(l) << endl;
        }
    }while(op!='F');
    return 0;
}
