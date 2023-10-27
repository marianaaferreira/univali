#ifndef PASSAGEIRO_H_INCLUDED
#define PASSAGEIRO_H_INCLUDED
#include "passageiro.h"
#include "trabalho.h"
#include <string>
#include <iostream>

using namespace std;

struct Passageiro {
	string nome;
	string origem, destino;
	bool marcar;
};

Passageiro leiaPassageiro(bool marcar)
{
	Passageiro passageiro;

	if (marcar == true)
		passageiro.marcar = true;
	else
		passageiro.marcar = false;

	cout << "Informe o nome do passageiro: ";
	getline(cin, passageiro.nome);
	passageiro.nome = converteUpper(passageiro.nome);

	cout << "Informe a origem: ";
	getline(cin, passageiro.origem);
	passageiro.origem = converteUpper(passageiro.origem);

	cout << "Informe o destino: ";
	getline(cin, passageiro.destino);
	passageiro.destino = converteUpper(passageiro.destino);

	return passageiro;
}

void verificaVooPassageiro(Nodo<Voo>* atual, Nodo<Passageiro>* atual2)
{
	if (atual2->elemento.marcar != true)
	{
		cout << "** NAO CONFIRMADO ** " << atual2->elemento.nome << " ** " << "VOO DESMARCADO" << endl;
		atual->elemento.acentosDisponiveis++;
		return;
	}

	if (atual->elemento.acentosDisponiveis <= 0)
	{
		cout << "** NAO CONFIRMADO ** " << atual2->elemento.nome << " ** " << "VOO LOTADO" << endl;
		return;
	}

	cout << "** CONFIRMADO ** " << atual2->elemento.nome << " ** " << atual->elemento.numeroVoo << endl;
	atual->elemento.acentosDisponiveis--;
}

void mostraRelatorio(ListaDuplamenteEncadeada<Voo> listaVoos, ListaDuplamenteEncadeada<Passageiro> listaPassageiros)
{
	Nodo<Passageiro>* atual2 = listaPassageiros.inicio;


	while (atual2 != NULL)
	{
		Nodo<Voo>* atual = listaVoos.inicio;
		bool achei = false;
		while (atual != NULL)
		{
			if (atual->elemento.origem == atual2->elemento.origem && atual->elemento.destino == atual2->elemento.destino)
			{
				achei = true;
				verificaVooPassageiro(atual, atual2);
			}

			atual = atual->proximo;
		}

		if(achei != true)
			cout << "** NAO CONFIRMADO ** " << atual2->elemento.nome << " ** " << "VOO INEXISTENTE" << endl;
		atual2 = atual2->proximo;
	}
}

#endif // PASSAGEIRO_H_INCLUDED
