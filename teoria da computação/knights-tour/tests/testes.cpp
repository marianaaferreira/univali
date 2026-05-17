#include <iostream>
#include <vector>
#include <utility>
#include <chrono>
#include "../src/PasseioDoCavalo.h"

using namespace std;
using namespace chrono;

void testarTabuleiro(int n) {
    cout << "\n====================================" << endl;
    cout << "TABULEIRO " << n << "x" << n << endl;
    cout << "====================================" << endl;

    if (!temSolucao(n)) {
        cout << "Sem solucao teorica para tabuleiro " << n << "x" << n << ".\n";
        return;
    }

    vector<pair<int, int>> posicoes = {
        {0, 0},           // canto
        {0, n / 2},       // borda
        {n / 2, n / 2},   // centro
        {n - 1, n - 1},   // canto oposto
        {n - 1, 0},       // outro canto
        {n / 2, 0},       // borda lateral
        {1, 1}            // posição interna
    };

    for (auto pos : posicoes) {
        int x = pos.first;
        int y = pos.second;

        if (x < 0 || x >= n || y < 0 || y >= n)
            continue;

        cout << "\nPosicao inicial: (" << x << ", " << y << ")\n";

        // COM HEURÍSTICA
        {
            PasseioDoCavalo p(n, 0, false, true);

            auto inicio = high_resolution_clock::now();
            bool ok = p.iniciar(x, y);
            auto fim = high_resolution_clock::now();

            cout << "Com heuristica: "
                 << (ok ? "OK" : "Falhou")
                 << " | Tempo: "
                 << duration_cast<microseconds>(fim - inicio).count()
                 << " us\n";
        }

        // SEM HEURÍSTICA
        // Para evitar travamento, limita aos menores tabuleiros
        if (n <= 5) {
            PasseioDoCavalo p(n, 0, false, false);

            auto inicio = high_resolution_clock::now();
            bool ok = p.iniciar(x, y);
            auto fim = high_resolution_clock::now();

            cout << "Sem heuristica: "
                 << (ok ? "OK" : "Falhou")
                 << " | Tempo: "
                 << duration_cast<microseconds>(fim - inicio).count()
                 << " us\n";
        } else {
            cout << "Sem heuristica: SKIPPED (muito lento)\n";
        }
    }
}

int main() {
    // Casos sem solução teórica
    vector<int> semSolucao = {2, 3};

    // Casos com solução
    vector<int> comSolucao = {5, 8, 10};

    cout << "====================================" << endl;
    cout << "TESTES SEM SOLUCAO" << endl;
    cout << "====================================" << endl;

    for (int n : semSolucao) {
        cout << "\nTabuleiro " << n << "x" << n << ":\n";
        cout << (temSolucao(n) ? "ERRO" : "OK: corretamente identificado como sem solucao") << endl;
    }

    cout << "\n====================================" << endl;
    cout << "TESTES COM SOLUCAO" << endl;
    cout << "====================================" << endl;

    for (int n : comSolucao) {
        testarTabuleiro(n);
    }

    return 0;
}