#include "PasseioDoCavalo.h"
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>

using namespace std;

PasseioDoCavalo::PasseioDoCavalo(int tamanho_tabuleiro, int temp_delay, bool exibir, bool heuristica) {
    n = tamanho_tabuleiro;
    delay = temp_delay;
    mostrar = exibir;
    usarHeuristica = heuristica;

    tabuleiro = vector<vector<int>>(n, vector<int>(n, -1));

    movimentos = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
}

void PasseioDoCavalo::imprimirTabuleiro() {
    if (!mostrar) return;
        system("clear");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int celula = tabuleiro[i][j];

            if (celula == -1) {
                cout << "  . ";
            } else {
                if (celula < 10) {
                    cout << "  " << celula << " ";
                } else if (celula < 100) {
                    cout << " " << celula << " ";
                } else {
                    cout << celula << " ";
                }
            }            
        }
        cout << endl;
    }
    if (delay > 0)
        usleep(delay);
}

bool PasseioDoCavalo::movimentoValido(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && tabuleiro[x][y] == -1;
}

int PasseioDoCavalo::contarMovimentos(int x, int y) {
    int contador = 0;

    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i].first;
        int novoY = y + movimentos[i].second;

        if (movimentoValido(novoX, novoY)) 
            contador++;
    }
    return contador;
}

bool PasseioDoCavalo::resolver(int x, int y, int passo) {
    if (passo == n * n)
        return true;

    vector<int> ordem;

    // gerar movimentos válidos
    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i].first;
        int novoY = y + movimentos[i].second;

        if (movimentoValido(novoX, novoY))
            ordem.push_back(i);
    }

    // ordenar pela heurística de warnsdorff (menos movimentos primeiro)
    if(usarHeuristica){
        for (int i = 0; i < ordem.size(); i++) {
            for (int j = i + 1; j < ordem.size(); j++) {

                int ax = x + movimentos[ordem[i]].first;
                int ay = y + movimentos[ordem[i]].second;

                int bx = x + movimentos[ordem[j]].first;
                int by = y + movimentos[ordem[j]].second;

                if (contarMovimentos(ax, ay) > contarMovimentos(bx, by)) {
                    int temp = ordem[i];
                    ordem[i] = ordem[j];
                    ordem[j] = temp;
                }
            }
        }
    }

    // testar movimentos
    for (int i = 0; i < ordem.size(); i++) {
        int indiceMovimento = ordem[i];

        int novoX = x + movimentos[indiceMovimento].first;
        int novoY = y + movimentos[indiceMovimento].second;

        tabuleiro[novoX][novoY] = passo;
        imprimirTabuleiro();

        if (resolver(novoX, novoY, passo + 1))
            return true;

        // backtracking
        tabuleiro[novoX][novoY] = -1;
        imprimirTabuleiro();
    }

    return false;
}

bool PasseioDoCavalo::iniciar(int x, int y) {
    tabuleiro[x][y] = 0;
    imprimirTabuleiro();
    return resolver(x, y, 1);
}

bool temSolucao(int n) {
    if (n == 1) return true;
    if (n == 2 || n == 3) return false;
    return true;
}