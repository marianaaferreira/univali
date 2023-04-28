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

void leiaFunc(int%i, Func empresa[]){
    do{
        cout << "codigo:\n";
        cin >> p.cod;
        cout << "idade:\n";
        cin >> p.idade;
        cout << "salario\n";
        cin >> p.salario;
        cout << "sexo:\n";
        p.sexo = toupper(cin.get(p.sexo));
        i++;
        resp = leiaCaracterSN();
    }while(resp=='S' and i<=TMAX);
}

int pesqCod(){
    for(int j=0; j<i; j++){
        if(codPesq==v[j].cod)
            return j;
    }
    return -1;
}

void mostraFuncionario(int codPesq, Func empresa[]){
    j = pesqCod();
    if (j>=0){
        cout << "codigo:\n" << empresa[j].cod;
        cout << "idade:\n" << empresa[j].idade;
        cout << "salario\n" << empresa[j].salario;
        cout << "sexo:\n" << empresa[j].sexo;
    }

}

void aumentaSalario(int codPesq, Func empresa[]){

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
    int i=0;
    do{
        menu();
        cin.get(toupper(op));
        switch(op){
            case 'A': leiaFunc(i, empresa);
            case 'B': cout << "codigo:\n"; cin >> codPesq); mostraFuncionario(codPesq, empresa);
            case 'C': cout << "codigo:\n"; cin >> codPesq); aumentaSalario(codPesq, empresa);

        }

    return 0;
}
