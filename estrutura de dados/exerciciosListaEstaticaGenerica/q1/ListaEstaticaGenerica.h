#ifndef LISTAESTATICAGENERICA_H_INCLUDED
#define LISTAESTATICAGENERICA_H_INCLUDED
using namespace std;

template<typename T, int MAX>
struct ListaEstaticaGenerica{
    int cardinalidade;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(ListaEstaticaGenerica<T, MAX> &lista){
    lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia(T lista){
    if(lista.cardinalidade==0)
        return true;
    return false;
}

template<typename T, int MAX>
int qtdElementos(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(ListaEstaticaGenerica<T, MAX> lista, T elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        if(lista.elementos[i]==elemento)
            return true;
    }
    return false;
}

template<typename T, int MAX>
bool posicaoValida(ListaEstaticaGenerica<T, MAX> lista, int posicao){
    if(posicao>lista.cardinalidade)
        return false;
    return true;
}

template<typename T, int MAX>
T recuperaElemento(ListaEstaticaGenerica<T, MAX> lista, int posicao){
    return lista.elementos[posicao];
}

template<typename T, int MAX>
int recuperaPosicao(ListaEstaticaGenerica<T, MAX> lista, T elemento){
    for(int i=0; i<lista.cardinalidade; i++)
        if(lista.elementos[i]==elemento)
            return i;
}

template<typename T, int MAX>
void insere(ListaEstaticaGenerica<T, MAX> &lista, int posicao, T elemento){
    if(lista.cardinalidade!=posicao)
        for(int i=lista.cardinalidade-1; i>posicao; i--)
            lista.elementos[i+1]=lista.elementos[i];

    lista.elementos[posicao]=elemento;
}

template<typename T, int MAX>
void retiraElemento(ListaEstaticaGenerica<T, MAX> &lista, T elemento){
    if (lista.elementos[lista.cardinalidade-1]==elemento){
        lista.cardinalidade--;
        return;
    }
    for(int i=0; i<lista.cardinalidade; i++)
        if(lista.elementos[i]==elemento)
            lista.elementos[i]=lista.elementos[i+1];
    lista.cardinalidade--;
}

template<typename T, int MAX>
void retiraPelaPosicao(ListaEstaticaGenerica<T, MAX> &lista, int posicao){
    if(posicao!=lista.cardinalidade-1)
        for(int i=posicao; i<lista.cardinalidade; i++)
            lista.elementos[i]=lista.elementos[i+1];
    lista.cardinalidade--;
}

template<typename T, int MAX>
void exibeLista(ListaEstaticaGenerica<T, MAX> lista){
    for(int i=0; i<lista.cardinalidade; i++)
        cout << "[" << lista.elementos[i] << "]";
}

#endif // LISTAESTATICAGENERICA_H_INCLUDED
