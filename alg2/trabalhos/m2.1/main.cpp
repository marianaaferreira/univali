#include <iostream>
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

void inclusaoNovoLivro(int &n, Livro &l){
    cout << "Informe o titulo do livro a ser adicionado: " << endl;
    getline(cin, l.titulo);
    cout << "Informe o nome do autor do livro: " << endl;
    getline(cin, l.autor);
    cout << "Informe a quantidade do acervo: " << endl;
    cin >> l.qtdAcervo;
    l.qtdDisponivel = l.qtdAcervo;
    n++;
}

int pesquisaRecBinaria(Livro acervo[], string chave, int inicio, int fim){
    int meio = (inicio + fim) /2;
    if(fim>inicio){
        if(chave==acervo[meio].isbn)
            return meio;
        else if (chave>acervo[meio].isbn)
            return pesquisaRecBinaria(acervo, chave, meio+1, fim);
        else
            return pesquisaRecBinaria(acervo, chave, inicio, meio-1);
    }
    return -1;
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

void buscaISBN(){
    cout << "Informe o ISBN: " << endl;
    getline(cin, chave);
    int i = pesquisaRecBinaria(acervo, chave, inicio, fim);
    if (i>0)
        return i;
    else
        return -1;
}

void casoA(int n, Livro acervo[], string chave){
    int inicio = 0, fim = n;
    do{
        cout << "Informe o codigo do ISBN do livro: " << endl;
        getline(cin, acervo[n].isbn);
    }while(not validaISBN(acervo[n].isbn));
    cin.ignore();
    int iPesq = pesquisaRecBinaria(acervo, acervo[n].isbn, inicio, fim);
    if (iPesq<0)
            inclusaoNovoLivro(n, acervo[n]);
    else
        cout << "Livro ja cadastrado" << endl;
}

void casoB(){

}

int main(){
    char resp;
    int n = 0;
    Livro acervo[TMAX];
    Emprestimo emprestimos[TMAX];
    string chave;

    do{
        lerMenu();
        char op = validaCaracter();
        cin.ignore();
        switch (op) {
            case 'A': casoA(n, acervo, chave); break;
            //case 'B':

        }
        resp = 'S';
    }while(resp=='S');
    return 0;
}
