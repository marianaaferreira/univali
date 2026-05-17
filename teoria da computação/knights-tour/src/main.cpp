#include <iostream>
#include "PasseioDoCavalo.h"

using namespace std;

int main() {
    int n, x, y;

    cout << "Tamanho do tabuleiro: ";
    cin >> n;

    if (!temSolucao(n)) {
        cout << "Sem solucao.\n";
        return 0;
    }

    cout << "X inicial: ";
    cin >> x;

    cout << "Y inicial: ";
    cin >> y;

     PasseioDoCavalo passeio(n, 300000, true, true);

    if (passeio.iniciar(x, y))
        cout << "\nSolucao encontrada!\n";
    else
        cout << "\nNao foi possivel encontrar solucao.\n";

    return 0;
}