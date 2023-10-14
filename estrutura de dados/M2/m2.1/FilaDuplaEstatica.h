#ifndef FILADUPLAESTATICA_H_INCLUDED
#define FILADUPLAESTATICA_H_INCLUDED
using namespace std;

template<typename T, int MAX>
struct Deque{
    int cardinalidade;
    int inicio;
    int fim;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(Deque<T, MAX> &d){
    d.cardinalidade = 0;
    d.inicio = MAX - 1;
    d.fim = MAX - 1;
}

template<typename T, int MAX>
void insereNoInicio(Deque<T, MAX> &d, T elemento){
    if(d.cardinalidade==MAX)
        throw "OVERFLOW";
    //if(d.cardinalidade==0) d.inicio=0;
    d.elementos[d.inicio]=elemento;
    if(d.inicio==0)
        d.inicio=MAX-1;
    else
        d.inicio=d.inicio-1;
    d.cardinalidade++;
}

template<typename T, int MAX>
void insereNoFim(Deque<T, MAX> &d, T elemento){
    if(d.cardinalidade==MAX)
        throw "OVERFLOW";
    d.fim++;
    if(d.fim==MAX) d.fim=0;
    d.elementos[d.fim]=elemento;
    d.cardinalidade++;
}

template<typename T, int MAX>
void retiraDoInicio(Deque<T, MAX> &d){
    if(d.cardinalidade==0)
        throw "UNDERFLOW";
    if(d.inicio==MAX-1)
        d.inicio=0;
    else
        d.inicio++;
    d.cardinalidade--;
}

template<typename T, int MAX>
void retiraDoFim(Deque<T, MAX> &d){
    if(d.cardinalidade==0)
        throw "UNDERFLOW";
    if(d.fim==0)
        d.fim=MAX-1;
    else
        d.fim--;
    d.cardinalidade--;
}

template<typename T, int MAX>
void mostra(Deque<T, MAX> d){
    int i = 1;
    int posicao = d.inicio;
    while (i <= d.cardinalidade)
    {
        posicao++;
        if (posicao > MAX - 1)
            posicao = 0;
        cout << d.elementos[posicao] << " ";
        i++;
    }
    cout << endl;
}

#endif // FILADUPLAESTATICA_H_INCLUDED
