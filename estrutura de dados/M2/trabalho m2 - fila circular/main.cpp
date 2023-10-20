#include <iostream>
#include "FilaEstaticaCircular.h"
#include "Genericas.h"

int main() {
	FilaEstaticaGenerica<int, 10> fila;
	cria(fila);
	int opcao = 0;
	int elemento;

	do {
		mostraMenu();
		opcao = leiaNumero("Digite o numero correspondente a opcao desejada: ");
		try {
			switch (opcao) {
			case 1:
				elemento = leiaNumero("Digite o elemento a ser inserido no fim: ");
				insereFim(fila, elemento);
				break;
			case 2:
				elemento = leiaNumero("Digite o elemento a ser inserido no inicio: ");
				insereInicio(fila, elemento);
				break;
			case 3:
				retiraInicio(fila);
				break;
			case 4:
				retiraFim(fila);
				break;
			case 5:
				mostra(fila);
				break;
			case 6:
				cout << "Primeiro elemento: " << primeiro(fila) << endl;
				break;
			case 7:
				cout << "Ultimo elemento: " << ultimo(fila) << endl;
				break;
			case 8:
				elemento = leiaNumero("Digite o elemento para encontrar a posicao: ");
				cout << "Posicao do elemento: " << posicao(fila, elemento) << endl;
				break;
			case 9:
				elemento = leiaNumero("Digite a posicao para encontrar o elemento: ");
				cout << "Elemento na posicao: " << umElemento(fila, elemento) << endl;
				break;
			case 10:
				cout << "Saindo...\n";
				break;
			default:
				cout << "Opcao invalida!\n";
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	} while (opcao != 10);

	return 0;
}
