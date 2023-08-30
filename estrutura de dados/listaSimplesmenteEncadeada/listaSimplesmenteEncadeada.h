#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T> *proximo;
};

template<typename T>
struct ListaSimplesmenteEncadeada{
    int cardinalidade;
    Nodo<T> *inicio;
};

template<typename T>
void crialista(ListaSimplesmenteEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template<typename T>
void destroilista(ListaSimplesmenteEncadeada<T> &lista){
    Nodo<T> *p;
    while(lista.inicio!=NULL){
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}

template<typename T>
bool estaVazia(ListaSimplesmenteEncadeada<T> lista){
    if(lista.inicio==NULL)
        return true;
    return false;
}

template<typename T>
int qtdElementos(ListaSimplesmenteEncadeada<T> lista){
    return lista.cardinalidade;
}

template<typename T>
bool elementoEstaNaLista(ListaSimplesmenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    while(p.proximo!=NULL){
        if (p.elemento==elemento)
            return true;
        p = p -> proximo;
    }
    return false;
}

template<typename T>
bool posicaoValida(ListaSimplesmenteEncadeada<T> lista){
    if(posicao>lista.cardinalidade)
        return false;
    return true;
}

T recuperaElemento(ListaSimplesmenteEncadeada<T> lista, int posicao){

}


#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
