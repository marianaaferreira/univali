#ifndef FILADEPRIORIDADE_H_INCLUDED
#define FILADEPRIORIDADE_H_INCLUDED

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
    fila.fim = NULL:
}

template<typename T>
void existeElemento(FilaDePrioridade<T> fila){

}

#endif // FILADEPRIORIDADE_H_INCLUDED
