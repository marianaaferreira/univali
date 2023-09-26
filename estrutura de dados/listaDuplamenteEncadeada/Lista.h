#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T> *proximo;
};

template<typename T>
struct Lista{
    int cardinalidade;
    Nodo<T> *inicio;
};

template<typename T>
void cria(Lista &l){
    l.cardinalidade=0;
    l.inicio=NULL;
}

template<typename T>
void destroi(Lista&l){
    Nodo<T> *p;
    while(l.inicio!=NULL){
        p=l.inicio;
        l.inicio = l.inicio->proximo;
        delete p;
    }
    lista.cardinalidade=0;
}

template<typename T>
bool estaVazia(Lista l){
    return(l.cardinalidade==0);
}

template <typename T>
int qtdElementos(Lista l){
    return l.cardinalidade;
}

template <typename T>
bool elementoEstaNaLista(Lista l, T elemento){
    Nodo<T> *p=l.inicio;
    while(p!=NULL){
        if(elemento == p->elemento)
            return true
        p=p->proximo;
    }
    return false;
}

template<typename T>
T recuperaElemento(Lista l, int posicao){
    int i=0;
    while(p!=NULL){
        if posicao ==i
            return p->elemento
        p=p->proximo;
        i++;
    }
}

recuperaPosicao

insere


#endif // LISTA_H_INCLUDED
