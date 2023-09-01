#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED
using namespace std;

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
    while(p->proximo!=NULL){
        if (p->elemento==elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
bool posicaoValida(ListaSimplesmenteEncadeada<T> lista, int posicao){
    if(posicao>lista.cardinalidade)
        return false;
    return true;
}

template<typename T>
T recuperaElemento(ListaSimplesmenteEncadeada<T> lista, int posicao){
    int cont=0;
    Nodo<T> *p = lista.inicio;
    for(int i=0; i<posicao; i++){
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
int recuperaPosicao(ListaSimplesmenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio;
    int i=0;
    while(p->proximo!=NULL){
        if(p->elemento==elemento)
            return i;
        p = p->proximo;
        i++;
    }
}

template<typename T>
void insere(ListaSimplesmenteEncadeada<T> &lista, T elemento, int posicao){
    Nodo<T> *p = lista.inicio;
    Nodo<T> *n = new Nodo<T>;
    Nodo<T> *temp;
    n->elemento= elemento;
    if(posicao==0){
        if(lista.inicio==NULL){
            lista.inicio= n;
            n->proximo=NULL;
        }else{
            n->proximo = lista.inicio;
            lista.inicio = n;
        }
    }else{
        for(int i=0; i<posicao; i++){
            p = p->proximo;
        }
        if(p->proximo==NULL){
            p->proximo = n;
            n->proximo = NULL;
        }else{
            n->proximo = p->proximo;
            p->proximo = n;
        }
    }
}

//arrumar pra quando o elemento que for retirado for o ultimo
template<typename T>
void retiraElemento(ListaSimplesmenteEncadeada<T> &lista, int posicao){
    Nodo<T> *p=lista.inicio;
    for(int i=0; i<posicao; i++){
        p = p->proximo;
    }
    /*Nodo *conteudo = p->proximo
    p->proximo = conteudo->proximo;*/
    p->proximo = *(p->proximo);
}

template <typename T>
void exibeLista(ListaSimplesmenteEncadeada<T> lista){
    Nodo<T> *p=lista.inicio;
    while(p->proximo!=NULL){
        cout << "[" << p->elemento << "]";
        p = p->proximo;
    }
}


#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
