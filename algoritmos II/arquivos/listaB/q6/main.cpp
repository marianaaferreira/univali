#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
/*6. Uma empresa deseja processar os dados sobre seus funcionários. Para tanto, necessita criar um arquivo de
acesso direto CADASTRO.DDO com matrícula, nome e salário. Faça um algoritmo que leia os dados
necessários para criar esse arquivo.
A seguir deve ser feita uma atualização do arquivo. Essa atualização consiste em ler, para uma quantidade
indeterminada de funcionários, matrícula e código (I ou E, correspondendo a uma inclusão ou exclusão de
funcionário, respectivamente).
 O algoritmo deve ser modularizado, de forma que os seguintes passos sejam executados:
 inicialmente é chamado uma subrotina para ler os dados e gerar o arquivo;
 a seguir, são lidos matrícula e código. Para código ‘E’ deve ser invocado um procedimento para marcar o
registro correspondente ao funcionário que se deseja excluir. Essa marcação é feita colocando o valor -1 no
campo correspondente a matrícula do funcionário no arquivo; para o código ‘I’ deve ser chamado outra
subrotina para incluir os dados do novo funcionário no arquivo. A inclusão dos dados é sempre feita no final
do arquivo;
 depois de feitas todas as operações de inclusão e exclusão, deve ser invocado uma subrotina para atualizar
os dados. Essa atualização consiste em criar um novo arquivo, excluindo fisicamente os registros que
tenham sido marcados anteriormente como logicamente excluídos. O arquivo inicial deve ser apagado.
*/

typedef struct{
    char nome[51];
    float salario;
    int mat;
}Funcionario;

void gravaDados(){
    Funcionario f;
    char resp='S';
    string info;
    ofstream arq("CADASTRO.DDO", ios::binary);
    if (arq.fail()){
        cout << "problema com o arquivo cadastro"; exit(0);}
    while(resp=='S'){
        cout << "nome:\n"; cin.ignore(); getline(cin, info); strcpy(f.nome, info.c_str());
        cout << "salario:\n"; cin >> f.salario;
        cout << "matricula:\n"; cin >> f.mat;
        arq.write((const char*)(&f), sizeof(Funcionario));
        cout << "continuar? S/N\n"; cin.ignore(); cin.get(resp); resp = toupper(resp);
    }
}

int main(){
    gravaDados();

    return 0;
}
