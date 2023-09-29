#include <iostream>
#include "trabalho.h"
#include "voo.h"
#include <fstream>
#include <string>
#include "validacoes.h"
#include "passageiro.h"

using namespace std;

int main()
{
    ListaDuplamenteEncadeada<Voo> listaVoos;
    ListaDuplamenteEncadeada<Passageiro> listaPassageiros;

    cria(listaVoos);
    cria(listaPassageiros);

    Passageiro passageiro;

    preencheVoo(listaVoos);

    int opcao;

    do {
        leiaMenu();
        opcao = leiaOpcao();

        switch(opcao){
            case 1:
                passageiro = leiaPassageiro(true);
                insere(listaPassageiros, passageiro, quantidadeElementos(listaPassageiros) + 1);
                break;
            case 2:
                passageiro = leiaPassageiro(false);
                insere(listaPassageiros, passageiro, quantidadeElementos(listaPassageiros) + 1);
                break;
            case 3:
                mostraVoos(listaVoos);
                break;
            case 4:
                mostraRelatorio(listaVoos, listaPassageiros);
                break;
        }

    } while (opcao != 0);

    return 0;
}
