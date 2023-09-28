#ifndef VOO_H_INCLUDED
#define VOO_H_INCLUDED
#include <fstream>
#include <string>
#include "trabalho.h"

using namespace std;

struct Voo
{
    int numeroVoo;
    string origem, destino;
    int acentosDisponiveis;
};

void preencheVoo(ListaDuplamenteEncadeada<Voo> &lista)
{
    ifstream arquivo;
    string linha;

    arquivo.open("ENTRADA.txt");

    if (!arquivo)
    {
        throw("Nao foi possivel abrir o arquivo");
    }

    while (getline(arquivo, linha))
    {
        int i = 0;
        string origem, destino, numeroVoo, quantidade;
        Voo voo;

        while (linha[i] != ' ')
        {
            numeroVoo += linha[i];
            i++;
        }

        voo.numeroVoo = stoi(numeroVoo);

        i++;
        while (linha[i] != ' ')
        {
            origem += linha[i];
            i++;
        }

        voo.origem = origem;

        i++;

        while (linha[i] != ' ')
        {
            destino += linha[i];
            i++;
        }

        voo.destino = destino;

        i++;
        while (i < linha.length())
        {
            quantidade += linha[i];
            i++;
        }

        voo.acentosDisponiveis = stoi(quantidade);

        insere(lista, voo, lista.cardinalidade + 1);
    }
}

void mostraVoos(ListaDuplamenteEncadeada<Voo> lista)
{
    Nodo<Voo>* atual = lista.inicio;

    cout << "\n           VOOS DISPONIVEIS" << endl;

    while (atual != NULL)
    {
        cout << "Numero do Voo: " << atual->elemento.numeroVoo << endl;
        cout << "Origem: " << atual->elemento.origem << endl;
        cout << "Destino: " << atual->elemento.destino << endl;
        cout << "Quantidade de acentos disponiveis " << atual->elemento.acentosDisponiveis << endl;
        cout << "=====================================" << endl;

        atual = atual->proximo;
    }
}

#endif // VOO_H_INCLUDED
