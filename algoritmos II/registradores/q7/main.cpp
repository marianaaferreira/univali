#include <iostream>
#define TMAX 10

using namespace std;
/*7. Uma empresa possui vários vendedores. Para cada vendedor é conhecido o nome, a
quantidade vendida, o valor da venda e o salário fixo. Os vendedores recebem
comissão de acordo com a quantidade vendida:
• 10% do valor da venda se quantidade vendida < 15
• 22% do valor da venda se 15 <= quantidade vendida < 30
• 30% do valor da venda se quantidade vendida >= 30
Construa um algoritmo que escreva o nome do vendedor, a quantidade vendida, o
valor da venda, o salário fixo, a comissão e o total recebido. Os nomes dos
vendedores devem ser relacionados em ordem alfabética. */

typedef struct{
    string nome;
    int qtdVendida;
    float valorVenda, salarioFixo, comissao, total;
}vendedor;

void leiaVendedores(int&contv, vendedor empresa[]){
    do{
        cout << "nome:\n";
        getline(cin, empresa[i].nome);
        cout << "qtd vendida:\n";
        cin >> empresa[i].qtdVendida;
        cout << "valor da venda:\n";
        cin >> empresa[i].valorVenda;
        cout << "salario fixo:\n";
        cin >> empresa[i].salarioFixo;
        contv++;
        resp = leiaResp();
    }while(contv>=TMAX or resp=='S');
}

void calculaComissao(int contv, vendedor empresa[]){
    for (int i=0; i<contv; i++){
        if (empresa[i].qtdVendida<15)
            comissao[i] = empresa[i]*0,1;
        else if (empresa[i].qtdVendida<30)
            comissao[i] = empresa[i]*0,22;
        else
            comissao[i] = empresa[i]*0,3;
    }
}

void calculaTotalRenda(){
    for(int i=0; i<contv; i++)
        empresa[i].total = empresa[i].salarioFixo + empresa[i].valorVenda*qtdVendida + empresa[i].comissao;
}

void ordenaAlpha(){
    for(int i=0; i<contv-1; i++)
        for(int j=i; j<contv;j++)
        swap(empresa[i].nome, empresa[j].nome);
}

void relatorio(){

}

int main(){
    int contv=0;
    vendedor empresa[TMAX];


    return 0;
}
