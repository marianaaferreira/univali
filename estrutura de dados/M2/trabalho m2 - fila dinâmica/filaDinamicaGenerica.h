#ifndef FILADINAMICAGENERICA_H_INCLUDED
#define FILADINAMICAGENERICA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct Nodo {
	T elemento;
	int prioridade;
	Nodo<T>* anterior;
	Nodo<T>* proximo;
};

template<typename T>
struct FilaPrioridades {
	int cardinalidade;
	Nodo<T>* inicio;
	Nodo<T>* fim;
};

template<typename T>
void cria(FilaPrioridades<T>& fila) {
	fila.cardinalidade = 0;
	fila.inicio = NULL;
	fila.fim = NULL;
}

template<typename T>
void destroi(FilaPrioridades<T>& fila) {
	while (fila.inicio != NULL) {
		Nodo<T>* p = fila.inicio;
		fila.inicio = fila.inicio->proximo;
		delete p;
	}
	fila.cardinalidade = 0;
}

template<typename T>
bool existeElemento(FilaPrioridades<T>& fila, T elemento) {
	Nodo<T>* atual = fila.inicio;
	while (atual != NULL) {
		if (atual->elemento == elemento) {
			return true;
		}

		atual = atual->proximo;
	}

	return false;
}

template<typename T>
void insere(FilaPrioridades<T>& fila, T elemento, int prioridade) {

	Nodo<T>* novo = new Nodo<T>;

	novo->elemento = elemento;
	novo->prioridade = prioridade;

	if (fila.fim == NULL) {
		novo->anterior = NULL;
		novo->proximo = NULL;
		fila.inicio = novo;
		fila.fim = novo;
	}
	else {
		novo->anterior = fila.fim;
		fila.fim->proximo = novo;
		fila.fim = novo;
		novo->proximo = NULL;
	}

	fila.cardinalidade++;
}

template<typename T>
void remove(FilaPrioridades<T>& fila) {
	if (fila.inicio == NULL) {
		throw "UNDERFLOW";
	}

	Nodo<T>* atual = fila.inicio;
	Nodo<T>* max = atual;

	while (atual != NULL) {
		if (atual->prioridade > max->prioridade) {
			max = atual;

			if (max->prioridade == 3) {
				break;
			}
		}

		atual = atual->proximo;
	}

	if (max->anterior != NULL) {
		max->anterior->proximo = max->proximo;
	}
	if (max->proximo != NULL) {
		max->proximo->anterior = max->anterior;
	}
	if (max == fila.inicio) {
		fila.inicio = max->proximo;
	}
	if (max == fila.fim) {
		fila.fim = max->anterior;
	}

	fila.cardinalidade--;
	delete max;
}

template<typename T>
void mostra(FilaPrioridades<T> fila) {
	if (fila.cardinalidade == 0) {
		throw "FILA VAZIA";
	}

	for (int i = 3; i > 0; i--) {
		Nodo<T>* atual = fila.inicio;
		while (atual != NULL) {
			if (atual->prioridade == i) {
				cout << "Valor elemento: " << atual->elemento << endl;
				cout << "Prioridade: " << atual->prioridade << endl;
				cout << "-------------------" << endl;
			}
			atual = atual->proximo;
		}
	}
}

#endif // FILADINAMICAGENERICA_H_INCLUDED
