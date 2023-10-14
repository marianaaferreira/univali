#ifndef FILADINAMICAGENERICA_H_INCLUDED
#define FILADINAMICAGENERICA_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo
{
    T elemento;
    Nodo<T>* proximo;
};

template<typename T>
struct FilaDinamicaGenerica
{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(FilaDinamicaGenerica<T> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = fila.fim = NULL;
}

template<typename T>
void destroi(FilaDinamicaGenerica<T> &fila)
{
    Nodo<T> *p;
    while (fila.inicio != NULL)
    {
        p = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete p;
    }
    fila.fim = NULL;
    fila.cardinalidade = 0;
}

template<typename T>
bool ehVazia(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade;
}

template<typename T>
bool existeElemento(FilaDinamicaGenerica<T> fila, T elemento)
{
    for (Nodo<T> *p = fila.inicio; p != NULL; p = p->proximo)
        if (p->elemento == elemento)
            return true;
    return false;
}

template<typename T>
bool existePosicao (FilaDinamicaGenerica<T> fila, int posicao)
{
    return ((posicao >= 1) && (posicao <= fila.cardinalidade));
}

template<typename T>
T umElemento(FilaDinamicaGenerica<T> fila, int posicao)
{
    if(posicao < 1 || posicao > fila.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    int contador = 1;
    Nodo<T>* p = fila.inicio;
    while (contador < posicao)
    {
        contador++;
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
T primeiro(FilaDinamicaGenerica<T> fila)
{
    if(fila.cardinalidade == 0)
    {
        throw "FILA VAZIA";
    }
    return fila.inicio->elemento;
}

template<typename T>
T ultimo(FilaDinamicaGenerica<T> fila)
 {
 if(fila.cardinalidade == 0)
 {
 throw "FILA VAZIA";
 }
 return fila.fim->elemento;
 }

 template<typename T>
 int posicao(FilaDinamicaGenerica<T> fila, T elemento)
 {
 if (!existeElemento(fila, elemento))
 {
 throw "ELEMENTO NAO ESTA NA fila";
 }
 int contador = 1;
 Nodo<T>* p = fila.inicio;
 while (p->elemento != elemento)
 {
 contador++;
 p = p->proximo;
 }
 return contador;
 }

 template<typename T>
 void insere(FilaDinamicaGenerica<T> &fila, T elemento)
 {
 Nodo<T>* q = new Nodo<T>;
 q->elemento = elemento;
 q->proximo = NULL;
 if (fila.inicio == NULL)
 fila.inicio = q;
 else
 fila.fim->proximo = q;
 fila.fim = q;
 fila.cardinalidade++;
 }

 template<typename T>
 void retira (FilaDinamicaGenerica<T> &fila)
 {
 if(fila.cardinalidade == 0)
 {
 throw "UNDERFLOW";
 }
 Nodo<T>* q = fila.inicio;
 fila.inicio = fila.inicio->proximo;
 if (fila.cardinalidade == 1)
 fila.fim = NULL;
 delete q;
 fila.cardinalidade--;
 }

 template<typename T>
 void mostra(FilaDinamicaGenerica<T> fila)
 {
 for (Nodo<T>* p = fila.inicio; p != NULL; p = p->proximo)
 cout << p->elemento << " ";
 cout << endl;
 }


#endif // FILADINAMICAGENERICA_H_INCLUDED
