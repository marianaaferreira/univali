#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct Nodo{
    int valor;
    struct Nodo *proximo;
} Tipolista;

void destroilista(Tipolista **ptr_lista);
void excluiElemento(Tipolista **ptr_lista, int elemento);
void exibelista(Tipolista *lista);
void inserenofinal(Tipolista **ptr_lista, int valor);
void inserenoinicio(Tipolista **ptr_lista, int valor);

int calculaIdadeMedia(Tipolista *list1){
    Tipolista *p=list1; int soma=0, cont=0;
    while(p!=NULL){
        if (p->valor>=60){
            soma+=p->valor;
            cont++;
        }
        p = p->proximo;
    }
    return soma/cont;
}

int main(){
    Tipolista *umalista = NULL;
    int valor;
    do{
        cout <<"Valor (-1 para sair) = ";
        cin >> valor;
        if(valor!=-1)
            inserenoinicio(&umalista, valor);
    }
    while(valor != -1);
    exibelista(umalista);
    cout << "idade media: " << calculaIdadeMedia(umalista) << endl;
    destroilista(&umalista);
    cin.get();
    return 1;
}
void destroilista(Tipolista **ptr_lista)
{
    Tipolista *p;
    while(*ptr_lista != NULL)
    {
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}
void exibelista(Tipolista *lista)
{
    Tipolista *p = lista;
    while(p != NULL)
    {
        cout << "\n Nodo "<< p << " Valor " << p->valor << endl;
        p = p->proximo;
    }
}

void inserenoinicio(Tipolista **ptr_lista, int valor)
{
    Tipolista *p;
    p = new Tipolista;
    if(p==NULL)
    {
        cout << "Sem memoria";
        cin.get();
        exit(1);
    }
    p->valor = valor;
    p->proximo = *ptr_lista;
    *ptr_lista = p;
}
