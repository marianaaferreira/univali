#ifndef FILADEPRIORIDADE_H_INCLUDED
#define FILADEPRIORIDADE_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    char prioridade;
    Nodo<T> *anterior;
    Nodo<T> *proximo;
};

template<typename T>
struct FilaDePrioridade{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(FilaDePrioridade<T> &fila){
    fila.cardinalidade = 0;
    fila.inicio = NULL;
    fila.fim = NULL;
}

template<typename T>
void destroi(FilaDePrioridade<T> &fila){
    Nodo<T> *p;
    while(fila.inicio!=NULL){
        p = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete p;
    }
    fila.cardinalidade = 0;
    fila.fim = NULL;
}

template<typename T>
bool existeElemento(FilaDePrioridade<T> fila, T elemento){
    Nodo<T> *p = fila.inicio;
    while(p!=NULL){
        if(p->elemento==elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
void insere(FilaDePrioridade<T> &fila, T elemento, char prioridade){
    Nodo<T> *n = new Nodo<T>;

    prioridade = toupper(prioridade);
    if(prioridade!='B' and prioridade!='M' and prioridade!='A')
        throw "CARACTER INVALIDO";

    n->elemento = elemento;
    n->prioridade = prioridade;
    if(fila.inicio==NULL){
        fila.inicio = n;
        fila.fim = n;
        n->anterior=NULL;
        n->proximo=NULL;
    }else{
        fila.fim->proximo = n;
        n->anterior = fila.fim;
        n->proximo = NULL;
        fila.fim = n;
    }
    fila.cardinalidade++;
}

template<typename T>
void retira(FilaDePrioridade<T> &fila){
    if(fila.cardinalidade==0)
        throw "UNDERFLOW";
    Nodo<T> *p = fila.inicio;
    bool achou=false;
    while(p!=NULL and not achou){
        if(p->prioridade=='A') achou = true;
        p = p-> proximo;
    }
    if(not achou){
        p = fila.inicio;
        while(p!=NULL or not achou){
            if(p->prioridade=='M') achou = true;
            p = p->proximo;
        }
    }
    if(not achou) p = fila.inicio;
    if(p==fila.inicio){
        fila.inicio = p->proximo;
        p->proximo->anterior=NULL;
    }
    else if(p==fila.fim){
        fila.fim = p->anterior;
        p->anterior->proximo = NULL;
    }
    else{
        p->anterior->proximo = p->proximo;
        p->proximo->anterior = p->anterior;
    }
    delete p;
    fila.cardinalidade--;
}
/*
template<typename T>
void retira(FilaDePrioridade<T> &fila) {
    Nodo<T> *p = fila.inicio;

    while (p != NULL) {
        if (p->prioridade == 'A') {
            if (p == fila.inicio) {
                fila.inicio = p->proximo;
                if (p->proximo != NULL) {
                    p->proximo->anterior = NULL;
                }
            } else if (p == fila.fim) {
                fila.fim = p->anterior;
                if (p->anterior != NULL) {
                    p->anterior->proximo = NULL;
                }
            } else {
                p->anterior->proximo = p->proximo;
                p->proximo->anterior = p->anterior;
            }
            delete p;
            fila.cardinalidade--;
            return; // Saia da função após encontrar e remover um elemento com prioridade 'A'
        }
        p = p->proximo;
    }

    // Se não encontrou elemento com prioridade 'A', procure elementos com prioridade 'M' e 'B' aqui.
    // Adicione lógica adicional conforme necessário.
}*/

template<typename T>
void mostra(FilaDePrioridade<T> fila){
    Nodo<T> *p;
    for(p=fila.inicio; p!=NULL; p=p->proximo)
        if(p->prioridade=='A')
            cout << p->elemento << " ";
    for(p=fila.inicio; p!=NULL; p=p->proximo)
        if(p->prioridade=='M')
            cout << p->elemento << " ";
    for(p=fila.inicio; p!=NULL; p=p->proximo)
        if(p->prioridade=='B')
            cout << p->elemento << " ";
    cout << endl;
}

#endif // FILADEPRIORIDADE_H_INCLUDED
