#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
/*7. Fa�a um algoritmo que leia c�digo, nome, pre�o unit�rio e quantidade em estoque de um n�mero
indeterminado de produtos e armazene esses dados em um arquivo de acesso direto PRODUTOS, que
al�m desses dados dever� armazenar tamb�m o valor do estoque. Ap�s, que leia o arquivo anterior e
escreva o c�digo e o nome dos produtos com valor de estoque superior a R$ 1.000,00.
*/

typedef struct{
    char nome[51];
    int cod, qtd;
    float precoUni, valorEstoque;
}Produto;

int main(){
    Produto p;
    bool continuar = true;
    ofstream fout("PRODUTOS.BIN", ios::binary);
    string info;
    while(continuar){
        cout << "nome:\n"; cin.ignore(); getline(cin, info); strcpy(p.nome, info.c_str());
        cout << "codigo:\n"; cin >> p.cod;
        cout << "qtd:\n"; cin >> p.qtd;
        cout << "preco unitario:\n"; cin >> p.precoUni;
        p.valorEstoque = p.qtd*p.precoUni;
        fout.write((const char*)(&p), sizeof(Produto));
        cout << "continuar? S[1], N[0]" << endl;
        cin >> continuar;
    }
    fout.close();
    ifstream fin("PRODUTOS.BIN", ios::binary);
    cout << "Produtos com valor de estoque acima de 1000" << endl;
    while(fin.read((char*)(&p), sizeof(Produto))){
        if(p.valorEstoque>1000){
            fin.seekg(-sizeof(Produto), ios::cur);
            cout << "codigo: " << p.cod << endl;
            cout << "nome: "<< p.nome << endl;
            cout << "preco unitario: "<< p.precoUni << endl;
            cout << "qtd: " << p.qtd << endl;
            cout << "valor do estoque: " << p.valorEstoque << endl;
        }
    }
    fin.close();

    return 0;
}
