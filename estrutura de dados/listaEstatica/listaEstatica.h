#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED
#define TMAX 10

typedef struct{
    int v[TMAX];
    int cardinalidade;
}Lista;

bool verificaListaVazia(Lista l){
    if(l.cardinalidade==0)
        return true;
    return false;
}

bool verificaEspacoDisponivel(Lista l){
    if(l.cardinalidade==TMAX)
        return false;
    return true;
}

int qtdElementosLista(Lista l){
    return l.cardinalidade;
}

bool verificaElementoLista(Lista l, int elemento){
    for(int i=0; i<l.cardinalidade; i++){
        if(l.v[i]==elemento)
            return true;
    }
    return false;
}

bool verificaPosicaoValida(Lista l, int posicao){
    if(l.cardinalidade<=posicao)
        return false;
    return true;
}

int recuperaElementoLista(Lista l, int posicao){
    return l.v[posicao];
}

int recuperaPosicao(Lista l, int elemento){
    for(int i=0; i<l.cardinalidade; i++){
        if(l.v[i]==elemento)
            return i;
    }
    return -1;
}

void insereNoIncio(Lista &l, int elemento){
    for(int i=l.cardinalidade; i>0; i--){
        l.v[i] = l.v[i-1];
    }
    l.v[0] = elemento;
    l.cardinalidade++;
}

void insereNoFinal(Lista &l, int elemento){
    l.v[l.cardinalidade] = elemento;
    l.cardinalidade++;
}

void insereNaPosicao(Lista &l, int elemento, int posicao){
    if(posicao==l.cardinalidade){
        l.v[l.cardinalidade]=elemento;
        l.cardinalidade++;
    }else
        l.v[posicao]=elemento;
}

void retiraElementoLista(Lista &l, int elemento){
    int p = recuperaPosicao(l, elemento);
    if(p==l.cardinalidade-1)
        l.cardinalidade--;
    for(int i=p; i>l.cardinalidade; i++){
        l.v[i]=l.v[i+1];
    }
    l.cardinalidade--;
}

std::string exibeLista(Lista l){
    std::string s;
    for(int i=0; i<l.cardinalidade; i++)
        s+= "[" + std::to_string(l.v[i]) + "]";
    return s;
}

#endif // LISTAESTATICA_H_INCLUDED
