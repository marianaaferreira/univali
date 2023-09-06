#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED
using namespace std;

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

//nao esta conferindo o ultimo elemento da lista arrumar
template<typename T>
bool elementoEstaNaLista(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    while(p!=NULL){
        if (p->elemento==elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> lista, int posicao){
    if(posicao<1 or posicao>qtdElementos(lista)+1)
        throw "Posicao invalida";
    Nodo<T> *p=lista.inicio;
    for(int i=1; i<posicao; i++){
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
int recuperaPosicao(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    int i=1;
    while(p!=NULL){
        if(p->elemento==elemento)
            return i;
        p = p->proximo;
        i++;
    }
}

//verificar qnd o elemento e adicionado na ultima posicao que n tem ngm
template<typename T>
void insere(ListaDuplamenteEncadeada<T> &lista, T elemento, int posicao){
    if(posicao<1 or posicao>qtdElementos(lista)+1)
        throw "Posicao invalida";

    Nodo<T> *p = lista.inicio;
    Nodo<T> *n = new Nodo<T>;

    if(n==NULL){cout << "sem memória"; cin.get(); exit(1);}

    n->elemento = elemento;
    if(lista.inicio==NULL){ //lista vazia
        lista.inicio = n;
        lista.fim = n;
        n->anterior = NULL;
        n->proximo = NULL;
    }else if(posicao==1){ //insere no inicio
        n->proximo = lista.inicio;
        n->anterior = NULL;
        lista.inicio->anterior = n;
        lista.inicio = n;
    }else if(posicao==qtdElementos(lista)+1){ //insere no final
        lista.fim->proximo = n;
        n->anterior = lista.fim;
        n->proximo = NULL;
        lista.fim = n;
    }else{ // insere no meio
        for(int i=1; i<posicao-1; i++){
            p = p->proximo;
        }
        n->proximo = p->proximo;
        n->anterior = p;
        p->proximo = n;
        n->proximo->anterior = n;
    }
    lista.cardinalidade++;
}

template<typename T>
void excluiElemento(ListaDuplamenteEncadeada<T> &lista, int posicao){
    if(posicao<1 or posicao>qtdElementos(lista)+1)
        throw "Posicao invalida";
    Nodo<T> *p;
    if(qtdElementos(lista)==1){ //exclui o unico elemento da lista
        p = lista.inicio;
        lista.inicio=NULL;
        lista.fim=NULL;
    }else if(posicao==1){ // exclui o primeiro elemento
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior=NULL;
    }else if(posicao==qtdElementos(lista)){ // exclui o ultimo elemento
        p = lista.fim;
        lista.fim = lista.fim->anterior;
        lista.fim->proximo=NULL;
    }else{ // exclui elemento no meio
        p=lista.inicio;
        for(int i=1; i<posicao; i++)
            p = p->proximo;
        p->anterior ->proximo = p->proximo;
        p->proximo->anterior = p->anterior;
    }
    delete p;
    lista.cardinalidade--;
}

template<typename T>
void mostralista(ListaDuplamenteEncadeada<T> lista){
    Nodo<T> *p = lista.inicio;
    for(int i=0; i<lista.cardinalidade; i++){
        cout << "[" << p->elemento << "]";
        p = p->proximo;
    }
}


#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
