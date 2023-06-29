#include <iostream>
#include <string>
#define TMAX 10
using namespace std;
/*8. Uma loja de departamentos tem n vendedores. As vendas são registradas
diariamente e um determinado vendedor pode efetuar várias vendas por dia. Ao final
de cada dia, é emitido um relatório (em ordem alfabética) contendo o nome,
quantidade de vendas e total de vendas de cada um dos vendedores. Faça um
algoritmo que:
• leia o nome de cada um dos n vendedores;
• leia informações sobre as vendas diárias, quais sejam, nome do vendedor e valor
de venda;
• escreva, para cada vendedor, seu nome e valor total de vendas diárias efetuadas.
As informações sobre as vendas diárias não estão em sequência. O algoritmo deve
apresentar a seguinte mensagem: “mais uma venda: s(SIM) / n(NÃO)?” antes de
prosseguir com a entrada de dados. */

typedef struct {
    string nome;
    int qtdVendas=0;
    float totalVendas=0;
}vendedor;

void leiaVendedor(vendedor&p) {
    cout << "Nome:\n";
    cin.ignore();
    getline(cin, p.nome);
}

char leiaCaracterSN() { 
    char c;
    do {
        cout << "Outro? S/N";
        c = toupper(cin.get());
        cin.ignore();
    } while (c != 'S' and c != 'N');
    return c;
}

void cadastroVendedores(int&i, vendedor loja[]) {
    char resp;
    do {
        cout << "Cadastro de vendeores\n";
        leiaVendedor(loja[i]);
        i++;
        resp = leiaCaracterSN();
    } while (toupper(resp) == 'S' or i >= TMAX);
}

void registroVendas(int i, vendedor loja[]) {
    string nomePesq;
    float valorVenda;
    cout << "Nome do vendedor:\n";
    getline(cin, nomePesq);
    cin.ignore();
    for (int j = 0; j < i; j++) {
        if (loja[j].nome == nomePesq) {
            loja[j].qtdVendas++;
            cout << "Valor da venda:\n";
            cin >> valorVenda;
            loja[j].totalVendas += valorVenda;
        }
     }
}

void ordenaVetorAlpha(int i, vendedor loja[]) {
    for (int j = 0; j < i; j++) {
        for (int k = j; k < i; k++) {
            if (loja[j].nome > loja[k].nome) {
                swap(loja[j].nome, loja[k].nome);
            }
        }
    }
}

void relatorio(vendedor p) {
    cout << "Nome: " << p.nome << endl;
    cout << "Total de vendas efetuadas:\n";
}

int main(){
    vendedor loja[TMAX];
    int i = 0, resp;
    cadastroVendedores(i, loja);
    do {
        registroVendas(i, loja);
        resp = leiaCaracterSN();
    } while (toupper(resp) == 'S');
    cout << "Relatorio:\n";
    for (int j = 0; j < i; j++) 
        relatorio(loja[i]);
}

