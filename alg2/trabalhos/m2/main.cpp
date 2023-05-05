#include <iostream>
#define TMAX 50;

using namespace std;

typedef struct {
    string titulo;
    string autor;
    string isbn;
    int qtdAcervo;
    int qtdDisponivel;
} Livro;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    string matricula;
    string isbn;
    Data data;
} Emprestimo;

char validaCaracter(){
    char op;
    do {
        cout << "O que deseja fazer?" << endl;
        cin.get(op);
    } while(op<'A' or op>'G');

    return toupper(op);
}

void lerMenu(){
    cout << "Menu de Biblioteca" << endl;
    cout << "Opcoes: " << endl;
    cout << "A - Inclusao de um novo livro" << endl;
    cout << "B - Consulta a um livro" << endl;
    cout << "C - Exclusao de um livro" << endl;
    cout << "D - Emprestimo de um exemplar" << endl;
    cout << "E - Devolucao" << endl;
    cout << "F - Relatorio: Livros do Acervo" << endl;
    cout << "G - Relatorio: Emprestimos" << endl;
}

void inclusaoNovoLivro(int &n, Livro &l, Emprestimo &e){
    cout << "Informe o título do livro a ser adicionado: " << endl;
    getline(cin, l.titulo);
    cout << "Informe o nome do autor do livro: " << endl;
    getline(cin, l.autor);
    cout << "Informe a quantidade do acervo: " << endl;
    cin >> l.qtdAcervo;
    e.qtdDisponivel = l.qtdAcervo;
    n++;
}

void ordenacaoRec(int i, int n){
    int i = n-1;
    if(n<0)
        return;
    if(v[n]>v[i])
        swap(v[n], v[i]);
    ordenacaoRec(i-1, n);
    ordenaRec(i, n-1);
}

void pesquisaRecBinaria(){

}

int main()
{
    char op;
    int n = 0;

    Livro acervo[TMAX];
    Emprestimo emprestimos[TMAX];

    lerMenu();
    op = validaCaracter();

    switch (op) {
        case 'A':
            cout << "Informe o código do ISBN do livro: " << endl;
            getline(cin, l.isbn);
            int iPesq = pesquisaRecBinaria();
            if (iPesq<0)
                inclusaoNovoLivro();
            else
                cout << "Livro ja cadastrado" << endl;

            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'F':
            break;
        case 'G':
            break;
    }
}
