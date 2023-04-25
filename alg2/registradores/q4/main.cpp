#include <iostream>
#define TMAX 10

using namespace std;
/*
4. Faça um algoritmo para ler os dados de vários funcionários (matrícula, nome, cargo,
departamento, data de admissão e salário) de uma empresa e gerar uma relação
daqueles que têm salários superiores à média geral de salários. O algoritmo deve
apresentar a seguinte mensagem: “Mais um funcionário: s(SIM) / n(NÃO)?” antes de
prosseguir com a entrada de dados.
*/
typedef struct{
    string nome;
    float salario;
}Funcionario;

float leiaFuncionario(int, Funcionario[]);
char leiaCaracterSN();
float mediaSalarial(int, Funcionario[]);
void relatorio(int i, Funcionario empresa[]);

int main(){
    Funcionario empresa[TMAX];
    int i=0;
    char resp;
    do{
        leiaFuncionario(i, empresa);
        i++;
        resp =leiaCaracterSN();
    }while (toupper(resp)=='S');
    relatorio(i, empresa);

    return 0;
}

float leiaFuncionario(int i, Funcionario empresa[]){
    cout << "Nome: ";
    getline(cin, empresa[i].nome);
    cout << "Salario: "; cin >> empresa[i].salario;
}

char leiaCaracterSN(){
    cin.ignore();
    char resp;
    cout << "Deseja continuar? S/N";
    cin.get(resp);
    cin.ignore();
    return resp;
}

float mediaSalarial(int i, Funcionario empresa[]){
    float media=0;
    for (int j=0; j<i; j++){
        media += empresa[j].salario;
    }
    return media/i;
}

void relatorio(int i, Funcionario empresa[]){
    cout << "Funcionarios com salario acima da media: ";
    for(int j=0; j<i; j++){
        if(empresa[i].salario> mediaSalarial(i, empresa))
            cout << empresa[i].nome;
    }
}
