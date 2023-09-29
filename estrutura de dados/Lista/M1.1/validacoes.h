#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

string converteUpper(string palavra)
{
    string resultado;

    for (int i = 0; i < palavra.length(); i++)
    {
        resultado += toupper(palavra[i]);
    }

    return resultado;
}

void leiaMenu() {
    cout << "Menu de Voos" << endl;
    cout << "1 - Marcar novo acento" << endl;
    cout << "2 - Desmarcar acento" << endl;
    cout << "3 - Mostrar voos disponiveis" << endl;
    cout << "4 - Mostrar relatorio de marcacoes" << endl;
    cout << "0 - Sair" << endl;
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

int leiaOpcao() {
    string nums;
    cout << "Digite o numero correspondente a opcao desejada: ";
    getline(cin, nums);
    while (not validaNumeroIntPositivo(nums)) {
        cout << "Dado invalido. Informe novamente" << endl;
        getline(cin, nums);
    }
    return atoi(nums.c_str());
}

#endif // VALIDACOES_H_INCLUDED
