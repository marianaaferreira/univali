#ifndef GENERICAS_H_INCLUDED
#define GENERICAS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

void mostraMenu() {
    cout << "1. Inserir no fim\n";
    cout << "2. Inserir no inicio\n";
    cout << "3. Remover do inicio\n";
    cout << "4. Remover do fim\n";
    cout << "5. Mostrar fila\n";
    cout << "6. Mostrar primeiro elemento\n";
    cout << "7. Mostrar ultimo elemento\n";
    cout << "8. Mostrar posicao de um elemento\n";
    cout << "9. Mostrar um elemento em uma posicao\n";
    cout << "10. Sair\n";
}

bool validaNumeroIntPositivo(string num) {
    if (num != "") {
        for (int i = 0; i < num.size(); i++)
            if (not isdigit(num[i]))
                return false;
    }
    else
        return false;
    return true;
}

int leiaNumero(string mensagem) {
    string num;
    cout << mensagem;
    getline(cin, num);
    while (not validaNumeroIntPositivo(num)) {
        cout << "Dado invalido. Informe novamente: ";
        getline(cin, num);
    }
    return atoi(num.c_str());
}

#endif // GENERICAS_H_INCLUDED
