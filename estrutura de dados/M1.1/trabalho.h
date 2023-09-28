#ifndef TRABALHO_H_INCLUDED
#define TRABALHO_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo
{
	T elemento;
	Nodo<T>* anterior;
	Nodo<T>* proximo;
};

template<typename T>
struct ListaDuplamenteEncadeada
{
	int cardinalidade;
	Nodo<T>* inicio;
	Nodo<T>* fim;
};

template<typename T>
void cria(ListaDuplamenteEncadeada<T>& lista)
{
	lista.cardinalidade = 0;
	lista.inicio = NULL;
	lista.cardinalidade = NULL;
}

template<typename T>
void destroi(ListaDuplamenteEncadeada<T>& lista)
{
	while (lista.inicio != NULL)
	{
		Nodo<T>* p = lista.inicio;
		lista.inicio = lista.inicio->proximo;
		delete p;
	}
	lista.cardinalidade = 0;
}

template<typename T>
bool seVazio(ListaDuplamenteEncadeada<T> lista)
{
	return lista.inicio == NULL;
}

template<typename T>
int quantidadeElementos(ListaDuplamenteEncadeada<T> lista)
{
	return lista.cardinalidade;
}

template<typename T>
bool seExiste(ListaDuplamenteEncadeada<T> lista, T elemento)
{
	Nodo<T>* atual = lista.inicio;
	while (atual != NULL)
	{
		if (atual->elemento == elemento)
		{
			return true;
		}

		atual = atual->proximo;
	}

	return false;
}

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> lista, int posicao)
{
	Nodo<T>* atual = lista.inicio;
	int i = 1;

	if (posicao < 1 || posicao > lista.cardinalidade)
		throw "POSICAO INVALIDA";

	while (atual != NULL)
	{
		if (posicao == i)
			return atual->elemento;

		atual = atual->proximo;
		i++;
	}
}

template<typename T>
int recuperaPosicao(ListaDuplamenteEncadeada<T> lista, T elemento)
{
	Nodo<T>* atual = lista.inicio;
	int i = 1;

	while (atual != NULL)
	{
		if (atual->elemento == elemento)
			return i;
		atual = atual->proximo;
		i++;
	}

	return -1;
}

template<typename T>
void insere(ListaDuplamenteEncadeada<T>& lista, T elemento, int posicao)
{
	Nodo<T>* atual = lista.inicio;
	int i = 1;

	if (posicao < 1 || posicao - 1 > lista.cardinalidade)
		throw "POSICAO INVALIDA";

	while (i != posicao)
	{
		atual = atual->proximo;
		i++;
	}

	Nodo<T>* novo = new Nodo<T>;

	if (lista.inicio == NULL)
	{
		novo->elemento = elemento;
		novo->proximo = NULL;
		novo->anterior = NULL;
		lista.inicio = novo;
		lista.fim = novo;
	}
	else {

		if (atual == lista.inicio)
		{
			novo->elemento = elemento;
			novo->anterior = NULL;
			atual->anterior = novo;
			novo->proximo = atual;
			lista.inicio = novo;
		}
		else if (atual == NULL)
		{
			novo->elemento = elemento;
			novo->proximo = NULL;
			novo->anterior = lista.fim;
			lista.fim->proximo = novo;
			lista.fim = novo;
		}
		else
		{
			novo->elemento = elemento;
			atual->anterior->proximo = novo;
			novo->anterior = atual->anterior;
			atual->anterior = novo;
			novo->proximo = atual;
		}
	}

	lista.cardinalidade++;
}

template<typename T>
void retira(ListaDuplamenteEncadeada<T> &lista, int posicao)
{
	Nodo<T>* atual = lista.inicio;
	int i = 1;

	if (lista.inicio == NULL)
	{
		throw "LISTA VAZIA";
	}

	if (posicao < 1 || posicao - 1 > lista.cardinalidade)
		throw "POSICAO INVALIDA";

	while (i != posicao)
	{
		atual = atual->proximo;
		i++;
	}

	if (atual == lista.inicio)
	{
		lista.inicio = lista.inicio->proximo;
		lista.inicio->anterior = NULL;
		delete atual;
	}
	else if (atual == lista.fim)
	{
		lista.fim = atual->anterior;
		lista.fim->proximo = NULL;
		delete atual;
	}
	else
	{
		atual->anterior->proximo = atual->proximo;
		atual->proximo->anterior = atual->anterior;
		delete atual;
	}

	lista.cardinalidade--;
}

template<typename T>
void mostra(ListaDuplamenteEncadeada<T> lista)
{
	Nodo<T>* atual = lista.inicio;
	int i = 1;

	while (atual != NULL)
	{
		cout << atual->elemento << endl;
		atual = atual->proximo;
	}
}

#endif // TRABALHO_H_INCLUDED
