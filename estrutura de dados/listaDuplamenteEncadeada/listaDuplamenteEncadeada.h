#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T> *proximo;
    Nodo<T> *anterior;
};

template<typename T>
struct ListaDuplamenteEncadeada{
    int cardinalidade;
    Nodo<T> *inicio;
    Nodo<T> *fim;
};

template<typename T>
void crialista(ListaDuplamenteEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}

template<typename T>
void destroilista(ListaDuplamenteEncadeada<T> &lista){
    Nodo<T> *p;
    while(lista.inicio!=NULL){
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}

template<typename T>
bool estaVazia(ListaDuplamenteEncadeada<T> lista){
    if(lista.inicio==NULL)
        return true;
    return false;
}

template<typename T>
int qtdElementos(ListaDuplamenteEncadeada<T> lista){
    return lista.cardinalidade;
}

template<typename T>
bool elementoEstaNaLista(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    while(p->proximo!=NULL){
        if (p->elemento==elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

/*recuperar um elemento da lista, recuperar uma posição da lista, inserir um elemento na lista, retirar um
elemento da lista e mostrar uma lista.*/

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> lista, int posicao){
    Nodo<T> *p;
    for(int i=0; i<posicao; i++){
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
int recuperaPosicao(ListaSimplesmenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    int i=1;
    while(p->proximo!=NULL){
        if(p->elemento==elemento)
            return i;
        p = p->proximo;
        i++;
    }
}

template<typename T>
void insere(ListaDuplamenteEncadeada<T> lista, T elemento, int posicao){
    Nodo<T> *p = lista.inicio;
    Nodo<T> *n = new Nodo<T>;
    if(lista.inicio==NULL){
        lista.inicio = n;
        lista.anterior = NULL;
        lista.proximo = NULL;
    }else{
        for(int i=0; i<posicao; i++){
            p = p->proximo;
        }
        n->proximo = p->proximo;
        n->anterior = p;
        p->proximo = n;
        p = p->proximo;
        p->anterior = n;
    }
}



#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
