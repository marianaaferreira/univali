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

bool validaNumLim(string chave, int lim){
    if(chave.size() == lim){
        for(int i=0;i<lim;i++)
            if (not isdigit(chave[i]))
                return false;
    }else
        return false;
    return true;
}


int validaData(string msg, int lim){
    int d; string sd;
    bool validada=true;
    do{
        do{
            cout << msg; getline(cin, sd);
            for(int i=0; i<sd.size(); i++)
                if (not isdigit(sd[i]))
                    validada = false;
        }while(not validada);
        d = atoi(sd.c_str());
    }while(d<1 or d>lim);
    return d;
}

int pesquisaRecBinaria(Livro acervo[], string chave, int inicio, int fim){
    if(fim>=inicio){
        int meio = (inicio + fim) /2;
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

string leiaISBN(){
    string chave;
    do{
        cout << "Informe o ISBN: " << endl;
        getline(cin, chave);
    }while(not validaNumLim(chave, 13));
    return chave;
}

void inclusaoNovoLivro(int&n, Livro acervo[]){
    string num, chave = leiaISBN();
    if (pesquisaRecBinaria(acervo, chave, 0, n-1)<0){
        do{
            cout << "Informe o titulo do livro a ser adicionado: " << endl;
            getline(cin, acervo[n].titulo);
        }while(not validaTitulo(acervo[n].titulo));
        do{
            cout << "Informe o nome do autor do livro: " << endl;
            getline(cin, acervo[n].autor);
        }while(not validaNome(acervo[n].autor));
        do{
            cout << "Informe a quantidade de exemplares: " << endl;
            getline(cin, num);
        }while(not validaNumeroIntPositivo(num));
        acervo[n].qtdAcervo=atoi(num.c_str());
        acervo[n].qtdDisponivel = acervo[n].qtdAcervo;
        acervo[n].isbn = chave;
        cout << "Inclusao de titulo confirmada" << endl;
        cout << endl;
        n++;
    }else
        cout << "Livro ja cadastrado" << endl;

}

void mostraInfoLivro(int n, Livro acervo[]){
    string chave = leiaISBN();
    int iPesq = pesquisaRecBinaria(acervo, chave, 0 , n-1);
    if(iPesq>=0){
        cout << "titulo: " << acervo[iPesq].titulo << endl;
        cout << "autor: " << acervo[iPesq].autor << endl;
        cout << "isbn: " << acervo[iPesq].isbn << endl;
        cout << "qtd de exemplares no acervo: " << acervo[iPesq].qtdAcervo << endl;
        cout << "qtd disponivel pra emprestimo: " << acervo[iPesq].qtdDisponivel << endl;
    }else
        cout << "Livro inexistente" << endl;
        cout << endl;
}

void excluiLivroFisicamente(int&n, Livro acervo[]){
    string chave = leiaISBN();
    int iPesq = pesquisaRecBinaria(acervo, chave, 0 , n-1);
    if(iPesq>=0){
        for(int i=iPesq; i<n-1; i++)
            acervo[i] = acervo[i+1];
        n--;
        cout << "Exclusao confirmada";
        cout << endl;
    }else
        cout << "Titulo inexistente, impossivel excluir";
        cout << endl;
}

void cadastroEmprestimo(int n, int&cod, Livro acervo[], Emprestimo e[]){
    string chave = leiaISBN();
    int iPesq = pesquisaRecBinaria(acervo, chave, 0 , n-1);
    if(iPesq>=0){
        if (acervo[iPesq].qtdDisponivel>0){
            do{
                cout << "Informe a matricula: " << endl;
                getline(cin, e[cod].matricula);
            }while(not validaNumLim(e[cod].matricula, 5));
            e[cod].isbn = chave;
            cout << "Data: " << endl;
            e[iPesq].data.dia = validaData("dia:\n", 31);
            e[iPesq].data.mes = validaData("mes:\n", 12);
            e[iPesq].data.ano = validaData("ano:\n", 2023);
            acervo[iPesq].qtdDisponivel--;
            cout << "Emprestimo realizado. Codigo: " << cod << endl;
            cod++;
            }
        else
            cout << "Exemplar indisponível para empréstimo " << endl;
    }else
        cout << "Titulo inexistente" << endl;
}

void cadastroDevolucao(int n, int cod, Livro acervo[], Emprestimo e[]){
    int codp;
    cout << "Informe o codigo: " << endl;
    cin >> codp;
    for(int i=0; i<cod; i++){
        if(i==codp){
            if(e[i].matricula=="-1"){
                cout << "Devolucao ja realizada" << endl;
                return;
            }else{
                cout << "matricula: " << e[i].matricula << endl;
                cout << "isbn do livro: " << e[i].isbn << endl;
                cout << "data: " << e[i].data.dia << "/" << e[i].data.mes << "/" << e[i].data.ano << endl;
                e[i].matricula = "-1";
                int iPesq = pesquisaRecBinaria(acervo, e[codp].isbn, 0, n-1);
                acervo[iPesq].qtdDisponivel++;
                cout << "Devolucao realizada" << endl;
                return;
            }
        }

    }
    cout << "Registro inexistente" << endl;
}

void relatorio1(int n, Livro acervo[]){
    for(int i=0; i<n; i++){
        cout << "Titulo: " << acervo[i].titulo << endl;
        cout << "Autor: " << acervo[i].autor << endl;
        cout << "ISBN: " << acervo[i].isbn << endl;
        cout << "Qtd de exemplares no acervo: " << acervo[i].qtdAcervo << endl;
        cout << "Qtd disponiivel pra emprestimo: " << acervo[i].qtdDisponivel << endl;
        cout << "========================" << endl;
    }
}

void relatorio2(int cod, Emprestimo e[]){
    for(int i=0; i<cod; i++){
        if(e[i].matricula!="-1")
            cout << "matricula: " << e[i].matricula << endl;
            cout << "isbn do livro: " << e[i].isbn << endl;
            cout << "data: " << e[i].data.dia << "/" << e[i].data.mes << "/" << e[i].data.ano << endl;
            cout << "====================" << endl;
    }
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
    cout << "H - Sair" << endl;
}

char validaCaracter(){
    char op;
    do {
        cout << "O que deseja fazer?" << endl;
        cin.get(op);
        op = toupper(op);
    } while(op<'A' or op>'H');
    return op;
}

int main(){
    int n=0, cod=0;
    char op;
    Livro acervo[TMAX];
    Emprestimo e[TMAX];
    do{
        lerMenu();
        op = validaCaracter();
        cin.ignore();
        switch (op) {
            case 'A': inclusaoNovoLivro(n, acervo); ordenaVetor(n, acervo); break;
            case 'B': mostraInfoLivro(n, acervo); break;
            case 'C': excluiLivroFisicamente(n, acervo); break;
            case 'D': cadastroEmprestimo(n, cod, acervo, e); break;
            case 'E': cadastroDevolucao(n, cod, acervo, e); break;
            case 'F': relatorio1(n, acervo); break;
            case 'G': relatorio2(cod, e); break;
        }
    }while(op!='H');
    return 0;
}
