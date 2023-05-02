#include <iostream>
#define TMAX 10

using namespace std;

typedef struct{
    int cod, idade;
    float salario;
    char sexo;
}Func;

char leiaCaracterSN(){
    cin.ignore();
    char resp;
    cout << "Mais um funcionario? S/N";
    cin.get(resp);
    cin.ignore();
    return resp;
}

void leiaFunc(int&i, Func empresa[]){
    char resp;
    do{
        cout << "codigo:\n";
        cin >> empresa[i].cod;
        cout << "idade:\n";
        cin >> empresa[i].idade;
        cout << "salario\n";
        cin >> empresa[i].salario;
        cout << "sexo:\n";
        cin.get(empresa[i].sexo);
        i++;
        resp = leiaCaracterSN();
    }while(resp=='S' and i<=TMAX);
}

int pesqCod(int codPesq, int i, Func empresa[]){
    for(int j=0; j<i; j++){
        if(codPesq==empresa[j].cod)
            return j;
    }
    return -1;
}

void mostraFuncionario(int codPesq, int i, Func empresa[]){
    int j = pesqCod(codPesq, i, empresa);
    if (j>=0){
        cout << "codigo:\n" << empresa[j].cod;
        cout << "idade:\n" << empresa[j].idade;
        cout << "salario\n" << empresa[j].salario;
        cout << "sexo:\n" << empresa[j].sexo;
    }

}

void aumentaSalario(int codPesq, int i, Func empresa[]){
    int j = pesqCod(codPesq, i, empresa);
    if(j>=0)
        empresa[j].salario += empresa[j].salario*0,1;
}

void mostraQtdHM(int&contF, int&contM, int i, Func empresa[]){
    for(int j=0; j<i; j++){
        if (empresa[j].sexo=='F')
            contF++;
        else
            contM++;
    }
}

float calculaIdadeMedia(int i, Func empresa[]){
    float idadeMedia=0;
    for (int j=0; j<i; j++)
        idadeMedia += empresa[i].idade;
    return idadeMedia/i;
}

void mostraDadosMulheres(int i, Func empresa[]){
    for (int j=0; j<i; j++)
        if (empresa[j].sexo=='F'){
            cout << "codigo:\n" << empresa[j].cod;
            cout << "idade:\n" << empresa[j].idade;
            cout << "salario\n" << empresa[j].salario;
            cout << "sexo:\n" << empresa[j].sexo;
        }
}

void menu(){
    cout << "O que deseja fazer?\n";
    cout << "A. informar dados de um funcionario\n";
    cout << "B. visualizar dados de um funcionario pelo codigo\n";
    cout << "C. aumentar salario de um funcionario em 10% atraves do codigo\n";
    cout << "D. visualizar a qtd de homens e mulheres\n";
    cout << "E. visualizar a idade media dos funcionarios\n";
    cout << "F. visualizar dados das funcionarias mulheres\n";
}

int main(){
    Func empresa[TMAX];
    char resp, op;
    int i=0, contF=0, contM=0, codPesq;
    do{
        menu();
        cin.get(toupper(op));
        switch(op){
            case 'A': leiaFunc(i, empresa);
            case 'B': cout << "codigo:\n"; cin >> codPesq); mostraFuncionario(codPesq, empresa);
            case 'C': cout << "codigo:\n"; cin >> codPesq); aumentaSalario(codPesq, empresa);
            case 'D': cout << "mulheres: " << contF << endl << "homens: " << contM << endl;
            case 'E': cout << "idade media: " << calculaIdadeMedia(i, empresa) << endl;
            case 'F': mostraDadosMulheres(i, empresa);
        }
        resp == leiaCaracterSN();
    }while(toupper(resp)=='S');
    return 0;
}
