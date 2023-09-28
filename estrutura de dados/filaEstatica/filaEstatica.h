#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
using namespace std;

template<typename T, int MAX>
struct FilaEstatica{
    int cardinalidade;
    int inicio;
    int fim;
    T elemento[MAX];
};

template<typename T, int MAX>
void cria(FilaEstatica<T, MAX> &fila){
    fila.cardinalidade = 0;
    fila.inicio = 0;
    fila.fim = 0;
}

template<typename T, int MAX>
bool estaVazia(FilaEstatica<T, MAX> fila){
    return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco(FilaEstatica<T, MAX> fila){
    return fila.inicio == fila.fim and fila.inicio == fila.cardinalidade;
}

template<typename T, int MAX>
int qtdElementos(FilaEstatica<T, MAX> fila){
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool elementoExiste(FilaEstatica<T, MAX> fila, T elemento){
    int i=fila.inicio;
    do{
        if (i==fila.cardinalidade) i=0;
        if (elemento[i]==elemento) return true;
        i++;
    }while(i!=fila.fim);
    return false;
}

template<typename T, int MAX>
bool posicaoValida(FilaEstatica<T, MAX> fila, int posicao){
    posicao = posicao-1;
    if(temEspaco(fila))
        if (fila.inicio> fila.fim){
            if (posicao>fila.fim and posicao<fila.inicio)
                return true;
        }else
            if(posicao>fila.fim and posicao<fila.cardinalidade)
                return true;
    return false;
}

template<typename T, int MAX>
T recuperaElemento(FilaEstatica<T, MAX> fila, int posicao){
    return fila.elemento[posicao-1];
}

template<typename T, int MAX>
int recuperaPosicao(FilaEstatica<T, MAX> fila, T elemento){
    int i=fila.inicio;
    do{
        if(i==fila.cardinalidade) i=0;
        if(fila.elemento[i]==elemento) return i+1;
        i++;
    }while(i!=fila.fim);
}

template<typename T, int MAX>
T primeiroElemento(FilaEstatica<T, MAX> fila){
    return fila.elemento[fila.inicio];
}

template<typename T, int MAX>
T ultimoElemento(FilaEstatica<T, MAX> fila){
    return fila.elemento[fila.fim-1];
}

template<typename T, int MAX>
void insere(FilaEstatica<T, MAX> &fila, T elemento){
    if(fila.cardinalidade!=MAX){
        if(fila.fim==MAX-1)
            fila.fim=1;
        else
            fila.fim=fila.fim+1;
        fila.elemento[fila.fim-1] = elemento;
        fila.cardinalidade++;
    }else
        throw "OVERFLOW";
}

template<typename T, int MAX>
void retira(FilaEstatica<T, MAX> &fila){
    if(fila.cardinalidade!=0){
        if(fila.inicio==MAX)
            fila.inicio=1;
        else
            fila.inicio=fila.inicio-1;
        fila.cardinalidade--;
    }else
        throw "UNDERFLOW";
}

template<typename T, int MAX>
void exibe(FilaEstatica<T, MAX> fila){
    int i = fila.inicio;
    do{
        if(i==MAX) i = 0;
        cout << "[" << fila.elemento[i] << "]";
    }while(i!=fila.fim);
}


#endif // FILAESTATICA_H_INCLUDED
