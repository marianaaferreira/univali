#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "validacoes.h"

using namespace std;

struct Simulacoes
{
    string metodo;
    int qtdDados;
    float comparacoesRelativas;
    float movimentacoesRelativas;
};

int dividir(int &c, int &m, int esq, int dir, int v[])
{
    int cont=esq;
    for(int i=esq+1; i<=dir; i++)
    {
        if(v[i]>v[esq])
        {
            c++;
            cont++;
            swap(v[i], v[cont]);
            m++;
        }
    }
    swap(v[esq], v[cont]);
    m++;
    return cont;
}

void quickSort(int &c, int &m, int esq, int dir, int v[])
{
    int pos;
    if(esq<dir)
    {
        c++;
        pos=dividir(c, m, esq, dir, v);
        quickSort(c, m, esq, pos-1, v);
        quickSort(c, m, pos+1, dir, v);
    }
}

bool pesquisa(int valor, int qtd, int v[])
{
    for(int i=0; i<qtd; i++)
        if(v[i]==valor)
            return true;
    return false;
}

void ajustarValoresRelativos(float &a, float &b, float &c)
{
    int maior;
    if(a>b and a>c)
        maior = a;
    else if(b>a and b>c)
        maior = b;
    else
        maior = c;
    if(maior!=0)
    {
        a = a/maior*100;
        b = b/maior*100;
        c = c/maior*100;
    }
    else
    {
        a=0;
        b=0;
        c=0;
    }
}

void valoresRelativos(Simulacoes &x, Simulacoes &y, Simulacoes &z)
{
    ajustarValoresRelativos(x.comparacoesRelativas, y.comparacoesRelativas, z.comparacoesRelativas);
    ajustarValoresRelativos(x.movimentacoesRelativas, y.movimentacoesRelativas, z.movimentacoesRelativas);
}

void preencheDadosSimulacao(Simulacoes s[], int &k, int qtd, string metodo, int c, int m)
{
    s[k].qtdDados = qtd;
    s[k].metodo = metodo;
    s[k].comparacoesRelativas = c;
    s[k].movimentacoesRelativas = m;
    k++;
}

void mostraVetor(int v[], int qtd)
{
    for(int i=0; i<qtd; i++)
    {
        cout << v[i] << " ";
    }
}

void relatorio(int k, Simulacoes s[])
{
    for(int i=0; i<k; i++)
    {
        cout << "Metodo: " << s[i].metodo << endl;
        cout << "Quantidade de dados: " << s[i].qtdDados << endl;
        cout << "Comparacoes relativas: " << s[i].comparacoesRelativas << endl;
        cout << "Movimentacoes relativas: " << s[i].movimentacoesRelativas << endl;
        cout << endl;
    }
}

int main()
{
    char ch, resp, op;
    int v[10000], va[10000], vaux[10000], qtd, i, k=0;
    int c, m;
    Simulacoes s[100];
    string nomearq, valor="", input;
    srand(time(NULL));

    do
    {
        cout << "Digite o nome do arquivo:\n";
        getline(cin, nomearq);
        ifstream fin(nomearq);
        if(fin.fail())
        {
            cout << "Nao foi possivel abrir o arquivo";
            exit(0);
        }

        do
        {
            cout << "Quantidade de dados a serem ordenados: " << endl;
            getline(cin, input);
        }
        while(not validaNumeroIntPositivo(input));
        qtd = stoi(input);

        do
        {
            cout << "Qual vai ser o tipo de organizacao dos dados? Crescente(1), Descrescente(2), Aleatorio(3)" << endl;
            cin >> op;
        }
        while(op!='1' and op!='2' and op!='3');

        switch(op)
        {
        case '1':
            i=0;
            while(i<qtd)
            {
                fin.get(ch);
                if(ch!=';')
                    valor += ch;
                else
                {
                    v[i] = stoi(valor);
                    valor = "";
                    i++;
                }
            }
            fin.close();
            break;
        case '2':
            i=qtd-1;
            while(i>=0)
            {
                fin.get(ch);
                if(ch!=';')
                    valor += ch;
                else
                {
                    v[i] = stoi(valor);
                    valor = "";
                    i--;
                }
            }
            fin.close();
            break;
        case '3':
            i=0;
            int j;
            while(i<qtd)
            {
                fin.get(ch);
                if(ch!=';')
                    valor += ch;
                else
                {
                    do
                    {
                        j = rand()%qtd;
                    }
                    while(pesquisa(j, i, va));
                    v[j] = stoi(valor);
                    va[i]=j;
                    valor = "";
                    i++;
                }
            }
            fin.close();
        }

        cout << "\nOrganizacao inicial\n";
        mostraVetor(v, qtd);

        //vaux = v;
        for(int i=0; i<qtd; i++)
        {
            vaux[i]=v[i];
        }

        insertionSort(c, m, qtd, v);
        preencheDadosSimulacao(s, k, qtd, "Insertion Sort", c, m);
        cout << "\n\nVetor ordenado com o metodo Insertion Sort\n";
        mostraVetor(v, qtd);
        cout << "\nComparacoes: " << c << endl;
        cout << "Movimentacoes: " << m << endl;

        //v = vaux;
        for(int i=0; i<qtd; i++)
        {
            v[i]=vaux[i];
        }
        c=0;
        m=0;
        shellSort(c, m, qtd, v);
        preencheDadosSimulacao(s, k, qtd, "Shell Sort", c, m);
        cout << "\nVetor ordenado com o metodo Shell Sort\n";
        mostraVetor(v, qtd);
        cout << "\nComparacoes: " << c << endl;
        cout << "Movimentacoes: " << m << endl;

        //v = vaux;
        for(int i=0; i<qtd; i++)
        {
            v[i]=vaux[i];
        }
        c=0;
        m=0;
        quickSort(c, m, 0, qtd, v);
        preencheDadosSimulacao(s, k, qtd, "Quick Sort", c, m);
        cout << "\nVetor ordenado com o metodo Quick Sort\n";
        mostraVetor(v, qtd);
        cout << "\nComparacoes: " << c << endl;
        cout << "Movimentacoes: " << m << endl;

        valoresRelativos(s[k-3], s[k-2], s[k-1]);

        do
        {
            cout << "\nDeseja fazer mais uma simulacao? S/N";
            cin.ignore();
            cin.get(resp);
            cin.ignore();
            resp = toupper(resp);
        }
        while(resp != 'S' and resp != 'N');
    }
    while(resp == 'S');

    cout << "\n\nRelatorio\n\n";
    relatorio(k, s);

    return 0;
}
