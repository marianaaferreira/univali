#include <iostream>
#include "FilaDePrioridade.h"

using namespace std;

int main(){
    char prioridade, op='1';
    FilaDePrioridade<int> fila;
    int elemento;

    cria(fila);
    while(op!=4){
        cout << "Menu" << endl;
        cout << "1. Verificar se um elemento existe na fila" << endl;
        cout << "2. Inserir elemento" << endl;
        cout << "3. Retirar elemento" << endl;
        cout << "4. Mostrar fila" << endl;
        cout << "5. Sair" << endl;
        cin.get(op); cin.ignore();

        switch(op){
            case '1':
                cout << "Informe o elemento: "; cin >> elemento;
                if (existeElemento(fila, elemento))
                    cout << "O elemento esta na fila" << endl;
                else
                    cout << "O elemento nao esta na fila" << endl;
                break;
            case '2':
                cout << "Informe o elemento: "; cin >> elemento;
                cout << "\nInforme a prioridade: "; cin.get(prioridade);
                insere(fila, elemento, prioridade);
                break;
            case '3':
                retira(fila);
                break;
            case '4':
                mostra(fila);
        }
    }

    destroi(fila);
    return 0;
}
