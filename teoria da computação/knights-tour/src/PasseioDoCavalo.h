#ifndef PASSEIO_DO_CAVALO_H
#define PASSEIO_DO_CAVALO_H

#include <vector>
using namespace std;

class PasseioDoCavalo {
private:
    int n;
    vector<vector<int>> tabuleiro;
    vector<pair<int, int>> movimentos;
    int delay;
    bool mostrar;
    bool usarHeuristica;

    bool movimentoValido(int x, int y);
    int contarMovimentos(int x, int y);
    bool resolver(int x, int y, int passo);
    void imprimirTabuleiro();

public:
    PasseioDoCavalo(int tamanho_tabuleiro, int temp_delay, bool exibir, bool heuristica);
    bool iniciar(int inicioX, int inicioY);
};

bool temSolucao(int n);

#endif