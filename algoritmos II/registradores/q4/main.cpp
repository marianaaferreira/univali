#include <iostream>
#define TMAX 10

using namespace std;
/*
4. Fa�a um algoritmo para ler os dados de v�rios funcion�rios (matr�cula, nome, cargo,
departamento, data de admiss�o e sal�rio) de uma empresa e gerar uma rela��o
daqueles que t�m sal�rios superiores � m�dia geral de sal�rios. O algoritmo deve
apresentar a seguinte mensagem: �Mais um funcion�rio: s(SIM) / n(N�O)?� antes de
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
