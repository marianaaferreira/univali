#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct Nodo
{
    int valor;
    struct Nodo *proximo;
} Tipolista;
void destroilista(Tipolista **ptr_lista);
void excluiElemento(Tipolista **ptr_lista, int elemento);
void exibelista(Tipolista *lista);
void inserenofinal(Tipolista **ptr_lista, int valor);
void inserenoinicio(Tipolista **ptr_lista, int valor);
int main()
{
    Tipolista *umalista = NULL;
    int valor;
    do
    {
        cout <<"Valor (-1 para sair) = ";
        cin >> valor;
        if(valor!=-1)
            inserenoinicio(&umalista, valor); // OU inserenofinal(...);
    }
    while(valor != -1);
    exibelista(umalista);
    excluiElemento(&umalista, 5); //ex.: excluindo nodo com valor 5
    destroilista(&umalista);
    cin.get();
    return 1;
}
void destroilista(Tipolista **ptr_lista)   // ponteiro de ponteiro
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
void inserenofinal(Tipolista **ptr_lista, int valor)
{
    Tipolista *p, *pant;
    p =new Tipolista; // aloca memoria p/ novo nodo
    if(p==NULL)
    {
        cout << "sem memória";
        cin.get();
        exit(1);
    }
    p->valor = valor;
    p->proximo = NULL;
    if(*ptr_lista==NULL)   // se lista vazia, atualiza e retorna
    {
        *ptr_lista = p;
        return;
    }
// lista nao vazia, segue adiante
    pant = *ptr_lista;
    while(pant->proximo != NULL)
    {
        pant = pant->proximo;
    }
    pant->proximo = p;
// inclui novo nodo, sem necessidade alterar ptr_lista
}
void inserenoinicio(Tipolista **ptr_lista, int valor)
{
    Tipolista *p;
    p = new Tipolista; // aloca memoria p/ novo nodo
    if(p==NULL)
    {
        cout << "Sem memoria";
        cin.get();
        exit(1);
    }
    p->valor = valor;
    p->proximo = *ptr_lista;
    *ptr_lista = p; // conecta o novo nodo ao inicio da lista
}
void excluiElemento(Tipolista **ptr_lista, int elemento)
{
    Tipolista *p, *pant = NULL;
    p = *ptr_lista;
    if(p!=NULL)   // se lista não vazia
    {
        if(p->valor == elemento)
        {
            *ptr_lista = p->proximo; // exclusao do 1o nodo
            delete p; // libera memória do nodo excluido
            return;
        }
        pant = *ptr_lista;
        p = p->proximo;
        while(p != NULL and p->valor != elemento)
        {
            pant = p;
            p=p->proximo;
        }
        if(p!=NULL)   // achou elemento pra excluir
        {
            pant->proximo = p->proximo; //conecta nodos ant e post
            delete p; // libera memória do nodo excluido
        }
    } // fim do se lista não vazia
}
