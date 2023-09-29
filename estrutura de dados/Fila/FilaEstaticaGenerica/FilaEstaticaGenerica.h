#ifndef FILAESTATICAGENERICA_H_INCLUDED
#define FILAESTATICAGENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct FilaEstaticaGenerica
{
    int cardinalidade;
    int inicio;
    int fim;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(FilaEstaticaGenerica<T, MAX> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = MAX - 1;
    fila.fim = MAX - 1;
}

template<typename T, int MAX>
bool ehVazia (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroDeElementos (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (FilaEstaticaGenerica<T, MAX> fila, T elemento)
{
    int i = 1;
    int posicao = fila.inicio;
    while (i <= fila.cardinalidade)
    {
        posicao++;
        if (posicao > (MAX - 1))
            posicao = 0;
        if (fila.elementos[posicao] == elemento)
            return true;
        i++;
    }
    return false;
}

template<typename T, int MAX>
int existePosicao (FilaEstaticaGenerica<T, MAX> fila, int posicao)
{
    return (posicao >= 1) && (posicao <= fila.cardinalidade);
}

template<typename T, int MAX>
T umElemento (FilaEstaticaGenerica<T, MAX> fila, int posicao)
{
    if(posicao < 1 || posicao > fila.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    if ((fila.inicio + posicao) <= MAX - 1)
        return fila.elementos[fila.inicio + posicao];
    else
        return fila.elementos[posicao - MAX + fila.inicio];
}

template<typename T, int MAX>
int posicao (FilaEstaticaGenerica<T, MAX> fila, T elemento)
{
    if (!existeElemento(fila, elemento))
    {
        throw "ELEMENTO NAO ESTA NA fila";
    }
    int i = 1;
    int posicao = fila.inicio;
    while (i <= fila.cardinalidade)
    {
        posicao++;
        if (posicao > MAX - 1)
            posicao = 0;
        if (fila.elementos[posicao] == elemento)
            return i;
        i++;
    }
}

template<typename T, int MAX>
T primeiro (FilaEstaticaGenerica<T, MAX> fila)
{
    if (fila.inicio < MAX - 1)
        return fila.elementos[fila.inicio + 1];
    else
        return fila.elementos[0];
}

template<typename T, int MAX>
T ultimo (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.elementos[fila.fim];
}

template<typename T, int MAX>
void insere (FilaEstaticaGenerica<T, MAX> &fila, T elemento)
{
    if(fila.cardinalidade == MAX)
    {
        throw "OVERFLOW";
    }
    fila.fim++;
    if (fila.fim > MAX - 1)
        fila.fim = 0;
    fila.elementos[fila.fim] = elemento;
    fila.cardinalidade++;
}

template<typename T, int MAX>
void retira (FilaEstaticaGenerica<T, MAX> &fila)
{
    if(fila.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    fila.inicio++;
    if (fila.inicio > MAX - 1)
        fila.inicio = 0;
    fila.cardinalidade--;
}

template<typename T, int MAX>
void mostra (FilaEstaticaGenerica<T, MAX> fila)
{
    int i = 1;
    int posicao = fila.inicio;
    while (i <= fila.cardinalidade)
    {
        posicao++;
        if (posicao > MAX - 1)
            posicao = 0;
        cout << fila.elementos[posicao] << " ";
        i++;
    }
    cout << endl;
}

#endif // FILAESTATICAGENERICA_H_INCLUDED
