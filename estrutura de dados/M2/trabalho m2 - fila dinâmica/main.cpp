#include <iostream>
#include "FilaDinamicaGenerica.h"
#include "Generica.h"

using namespace std;

int main() {
	FilaPrioridades<int> fila;
	cria(fila);

	int opcao = 0;
	int elemento, prioridade;

	do {
		mostraMenu();
		opcao = leiaNumero("Digite o numero correspondente a opcao desejada: ");

		try
		{
			switch (opcao) {
			case 1: {
				elemento = leiaNumero("Digite o elemento a ser inserido: ");
				prioridade = leiaNumero("Digite a prioridade do elemento (1-3): ");

				insere(fila, elemento, prioridade);

				break;
			}
			case 2: {
				remove(fila);
				cout << "Elemento removido com sucesso." << endl;
				break;
			}
			case 3: {
				mostra(fila);
				break;
			}
			case 4: {
				elemento = leiaNumero("Digite o elemento a ser verificado: ");

				if (existeElemento(fila, elemento)) {
					cout << "O elemento existe na fila." << endl;
				}
				else {
					cout << "O elemento nao existe na fila." << endl;
				}

				break;
			}
			case 5: {
				destroi(fila);
				cout << "Fila destruida com sucesso." << endl;
				break;
			}
			case 6: {
				destroi(fila);
				cout << "Programa encerrado." << endl;
				break;
			}
			default:
				cout << "Opcao invalida." << endl;
			}
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}
	} while (opcao != 6);

	return 0;
}
