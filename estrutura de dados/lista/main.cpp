#include <iostream>
#define TMAX 10

using namespace std;

typedef struct{
    int v[TMAX];
    int cardinalidade;
}Lista;

bool verificaListaVazia(Lista l){
    if(l.cardinalidade==0)
        return true;
    return false;
}

bool verificaEspacoLista(Lista l){
    if(l.cardinalidade==TMAX)
        return false;
    return true;
}

int NumeroElementosLista(Lista l){
    return l.cardinalidade;
}

bool verificaElementoLista(int elemento, Lista l){
    for(int i=0; i<l.cardinalidade; i++){
        if(l.v[i]==elemento)
            return true;
    }
    return false;
}

bool verificaPosicaoValida(int posicao, Lista l){
    if(l.cardinalidade<posicao)
        return false;
    return true;
}

int recuperaElementoLista(int posicao, Lista l){
    return l.v[posicao];
}

int recuperaPosicao(int elemento, Lista l){
    for(int i=0; i<l.cardinalidade; i++){
        if(l.v[i]==elemento)
            return i;
    }
    return -1;
}

bool insereElemento(int elemento, int posicao, Lista &l){
    if(posicao>l.cardinalidade)
        return false;
    if(l.cardinalidade!=TMAX)
        return false;
    if(verificaListaVazia(l))
        l.v[0]=elemento;
    else
        l.v[posicao]=elemento;
    l.cardinalidade++;
    return true;
}

void retiraElementoLista(int elemento, Lista &l){
    int p = recuperaPosicao(elemento, l);
    if(p==l.cardinalidade-1)
        l.cardinalidade--;
    for(int i=p; i>l.cardinalidade; i++){
        l.v[i]=l.v[i+1];
    }
    l.cardinalidade--;
}

void exibeLista(Lista l){
    for(int i=0; i<l.cardinalidade; i++)
        cout << "[" << l.v[i] << "]";
}

int main(){
    Lista l;
    char op;
    int elemento, posicao;
    cout << "O que deseja fazer?" << endl;
    cout << "A. Inserir elemento na lista" << endl;
    cout << "B. Retirar elemento da lista" << endl;
    cout << "C. Visualizar lista" << endl;
    cin.get(op); op = upper()

    switch(op){
        case 'A':
            cout << "Informe o elemento:\n"; cin >> elemento;
            cout << "Informe a posicao:\n"; cin >> posicao;
            if(not insereElemento(elemento, posicao, l))
                cout << "Nao foi possivel inserir o elemento\n";
        case 'B':
            cout << "Que elemento deseja retirar da lista\n";
            retiraElementoLista(elemento, l);
        case 'C':
            exibeLista(l);
    }
    return 0;
}
