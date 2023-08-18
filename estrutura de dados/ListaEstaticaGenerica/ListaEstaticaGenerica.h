#ifndef LISTAESTATICAGENERICA_H_INCLUDED
#define LISTAESTATICAGENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct ListaEstaticaGenerica{
    int cardinalidade;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(ListaEstaticaGenerica<T, MAX> &lista){
    lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade==0;
}

template<typename T, int MAX>
bool temEspaco(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade<MAX;
}

template<typename T, int MAX>
int qtdElementosLista(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool verificaElementoLista(ListaEstaticaGenerica<T, MAX> lista, int elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        if(lista.elementos[i]==elemento)
            return true;
    }
    return false;
}

template<typename T, int MAX>
bool verificaPosicaoValida(ListaEstaticaGenerica<T, MAX> lista, int posicao){
    if(lista.cardinalidade<posicao or posicao<0)
        return false;
    return true;
}

template<typename T, int MAX>
int recuperaElementoLista(ListaEstaticaGenerica<T, MAX> lista, int posicao){
    return lista.elementos[posicao];
}

template<typename T, int MAX>
int recuperaPosicao(ListaEstaticaGenerica<T, MAX> lista, int elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        if(lista.elementos[i]==elemento)
            return i;
    }
    return -1;
}

template<typename T, int MAX>
void insereNoIncio(ListaEstaticaGenerica<T, MAX> &lista, int elemento){
    for(int i=lista.cardinalidade; i>0; i--){
        lista.elementos[i] = lista.elementos[i-1];
    }
    lista.elementos[0] = elemento;
    lista.cardinalidade++;
}

template<typename T, int MAX>
void insereNoFinal(ListaEstaticaGenerica<T, MAX> &lista, int elemento){
    lista.elementos[lista.cardinalidade] = elemento;
    lista.cardinalidade++;
}

template<typename T, int MAX>
void insereNaPosicao(ListaEstaticaGenerica<T, MAX> &lista, int elemento, int posicao){
    if(posicao==lista.cardinalidade){
        lista.elementos[lista.cardinalidade]=elemento;
        lista.cardinalidade++;
    }else
    for(int i=lista.cardinalidade-1; i>posicao; i--){
        lista.elementos[i+1]=lista.elementos[i];
    }
    lista.elementos[posicao]=elemento;
}

template<typename T, int MAX>
void retiraElementoLista(ListaEstaticaGenerica<T, MAX> &lista, int elemento){
    int p = recuperaPosicao(lista, elemento);
    if(p==lista.cardinalidade-1)
        lista.cardinalidade--;
    for(int i=p; i<lista.cardinalidade-1; i++){
        lista.elementos[i]=lista.elementos[i+1];
    }
    lista.cardinalidade--;
}

template<typename T, int MAX>
string exibeLista(ListaEstaticaGenerica<T, MAX> &lista){
    string s;
    for(int i=0; i<lista.cardinalidade; i++)
        s+= "[" + to_string(lista.elementos[i]) + "]";
    return s;
}


#endif // LISTAESTATICAGENERICA_H_INCLUDED
