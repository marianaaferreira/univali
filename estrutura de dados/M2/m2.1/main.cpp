#include <iostream>
#include "FilaDuplaEstatica.h"

using namespace std;

int main(){
    Deque<int, 10> d;
    int op=0, elemento;

    cria(d);
    while(op!=6){
        cout << "O que deseja fazer?" << endl;
        cout << "1. Inserir no inicio" << endl;
        cout << "2. Inserir no fim" << endl;
        cout << "3. Retirar do inicio" << endl;
        cout << "4. Retirar do fim" << endl;
        cout << "5. Mostrar deque" << endl;
        cout << "6. Sair" << endl;
        cin >> op;

        try{
            switch(op){
                case 1:
                    cout << "Informe o elemento: "; cin >> elemento;
                    insereNoInicio(d, elemento);
                    break;
                case 2:
                    cout << "Informe o elemento: "; cin >> elemento;
                    insereNoFim(d, elemento);
                    break;
                case 3:
                    retiraDoInicio(d);
                    break;
                case 4:
                    retiraDoFim(d);
                    break;
                case 5:
                    mostra(d);
            }
        }catch(const char* e){
            cerr << "ERRO: " << e << endl;
        }

    }

    return 0;
}
