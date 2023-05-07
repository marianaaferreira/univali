#include <iostream>
#include <cstring>
#define TMAX 5

using namespace std;

typedef struct {
    string titulo, autor, isbn;
    int qtdAcervo, qtdDisponivel;
} Livro;

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    string matricula, isbn;
    Data data;
} Emprestimo;

char validaCaracter(){
    char op;
    do {
        cout << "O que deseja fazer?" << endl;
        cin.get(op);
        op = toupper(op);
    } while(op<'A' or op>'G');
    return op;
}

char leiaCaracterSN(){
    char resp;
    cout << "Deseja continuar? S/N ";
    cin.get(resp);
    cin.ignore();
    return resp;
}

bool validaTitulo(string l){
    if(l=="")
        return false;
    return true;
}

bool validaNome(string nome){
    for(int i=0; i<nome.size(); i++)
        if(not isalpha(nome[i]) and nome[i]!=' ')
            return false;
    return true;
}

bool validaNumeroIntPositivo(string num){
    if (num!=""){
        for(int i=0; i<num.size(); i++)
            if (not isdigit(num[i]))
                return false;
    }else
        return false;
    return true;
}

void inclusaoNovoLivro(int&n, Livro&l){
    string num;
    do{
        cout << "Informe o titulo do livro a ser adicionado: " << endl;
        getline(cin, l.titulo);
    }while(not validaTitulo(l.titulo));
    do{
        cout << "Informe o nome do autor do livro: " << endl;
        getline(cin, l.autor);
    }while(not validaNome(l.autor));
    do{
        cout << "Informe a quantidade de exemplares: " << endl;
        getline(cin, num);
    }while(not validaNumeroIntPositivo(num));
    l.qtdAcervo=atoi(num.c_str());
    l.qtdDisponivel = l.qtdAcervo;
    cout << "Inclusao de titulo confirmada" << endl;
    n++;
}

void mostraInfoLivro(Livro l){
    cout << "titulo: " << l.titulo << endl;
    cout << "autor: " << l.autor << endl;
    cout << "isbn: " << l.isbn << endl;
    cout << "qtd de exemplares no acervo: " << l.qtdAcervo << endl;
    cout << "qtd disponivel pra emprestimo: " << l.qtdDisponivel << endl;
}

void excluiLivroFisicamente(int n, int iPesq, Livro v[]){
    for(int i=iPesq; i<n-1; i++)
        swap(v[i], v[i+1]);
}

int pesquisaRecBinaria(Livro acervo[], string chave, int inicio, int fim){
    int meio = (inicio + fim) /2;
    if(fim>=inicio){
        if(chave==acervo[meio].isbn)
            return meio;
        else if (chave>acervo[meio].isbn)
            return pesquisaRecBinaria(acervo, chave, meio+1, fim);
        else
            return pesquisaRecBinaria(acervo, chave, inicio, meio-1);
    }
    return -1;
}

void ordenaVetor(int n, Livro v[]){
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(v[i].isbn>v[j].isbn)
                swap(v[i], v[j]);
}

bool validaISBN(string chave){
    if(chave.size() == 13){
        for(int i=0;i<13;i++)
            if (not isdigit(chave[i]))
                return false;
    }else
        return false;
    return true;
}

void lerMenu(){
    cout << "Menu de Biblioteca" << endl;
    cout << "A - Inclusao de um novo livro" << endl;
    cout << "B - Consulta a um livro" << endl;
    cout << "C - Exclusao de um livro" << endl;
    cout << "D - Emprestimo de um exemplar" << endl;
    cout << "E - Devolucao" << endl;
    cout << "F - Relatorio: Livros do Acervo" << endl;
    cout << "G - Relatorio: Emprestimos" << endl;
}

int buscaISBN(int n, Livro acervo[]){
    string chave;
    int inicio=0, fim=n-1;
    do{
        cout << "Informe o ISBN: " << endl;
        getline(cin, chave);
    }while(not validaISBN(chave));
    int i = pesquisaRecBinaria(acervo, chave, inicio, fim);
    if (i>=0){
        acervo[n].isbn = chave;
        return i;
    }
    else
        return -1;
}


int main(){
    char resp;
    int n = 0, iPesq;
    Livro acervo[TMAX];
    Emprestimo emprestimos[TMAX];
    string chave;

    do{
        lerMenu();
        char op = validaCaracter();
        cin.ignore();
        switch (op) {
            case 'A':
                if (buscaISBN(n, acervo)<0)
                    inclusaoNovoLivro(n, acervo[n]);
                else
                    cout << "Livro ja cadastrado" << endl;
                break;
            case 'B':
                iPesq = buscaISBN(n, acervo);
                if(iPesq>=0)
                    mostraInfoLivro(acervo[iPesq]);
                else
                   cout << "Livro inexistente" << endl;
                break;
            case 'C':
                iPesq = buscaISBN(n, acervo);
                if (iPesq>=0)
                    excluiLivroFisicamente(n, iPesq, acervo);
                else
                    cout << "Titulo inexistente, impossivel excluir";
                break;
        }
        resp = leiaCaracterSN();
        cout << "=======================" << endl;
    }while(toupper(resp)=='S');
    return 0;
}
