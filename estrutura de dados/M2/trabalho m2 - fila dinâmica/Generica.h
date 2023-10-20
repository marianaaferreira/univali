#include <iostream>
#include <string>

using namespace std;

void mostraMenu() {
    cout << "Menu de opcoes:" << endl;
    cout << "1. Inserir elemento na fila" << endl;
    cout << "2. Remover elemento da fila" << endl;
    cout << "3. Mostrar fila" << endl;
    cout << "4. Verificar se um elemento existe" << endl;
    cout << "5. Destruir a fila" << endl;
    cout << "6. Sair" << endl;
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
