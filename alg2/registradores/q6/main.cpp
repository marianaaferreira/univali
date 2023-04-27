#include <iostream>
#define TMAX 5

using namespace std;
/*6. Construa um algoritmo que leia matrícula, nome e os dados dos dependentes de
vários sócios de um clube. Para cada dependente, leia nome e data de nascimento.
Na sequência, escreva o nome do sócio e os nomes de seus dependentes, para todos
os sócios que tiverem mais de 3 dependentes. Admita que cada sócio tenha no
máximo 5 dependentes. */

typedef struct{
    string nomeD, data;
}dependente;

typedef struct{
    string matricula, nomeS;
    int nd[TMAX];
    dependente dependentes[5];
}socio;

int leiaNLimSup(int lsup){
    int n;
    do{
        cout << "Qtd dependentes: ";
        cin >> n;
    }while(n<=0 or n>lsup);
    return n;
}

void leiaDependente(int conts, socio socios[]){
    cout << "Dependente" << endl;
    for (int i=0; i<socios[i].nd[conts]; i++){
        cout << "nome:\n";
        getline(cin, socios[conts].dependentes[i].nomeD);
        cin.ignore();
        cout << "data de nascimento:\n";
        getline(cin, socios[conts].dependentes[i].data);
        cin.ignore();
    }
}

void leiaSocio(int&conts, socio socios[]){
    char resp;
    cout << "Socio" << endl;
    do{
        cout << "nome:\n";
        getline(cin, socios[conts].nomeS);
        cout << "matricula:\n";
        getline(cin, socios[conts].matricula);
        socios[conts].nd[conts] = leiaNLimSup(5);
        leiaDependente(conts, socios);
        conts++;
        cout << "Mais um socio?S/N\n";
        cin.get(resp);
        cin.ignore();
    }while(toupper(resp)=='S' or conts>=TMAX);
}

void relatorio(int conts, socio socios[]){
    for (int i=0; i<conts; i++){
        if (socios[i].nd[i]>3){
            cout << "socio: " << socios[i].nomeS << endl;
            cout << "dependentes:\n";
            for(int j=0; j<socios[i].nd[i]; j++){
                cout << socios[i].dependentes[j].nomeD;
            }
        }
    }
}

int main(){
    int conts=0;
    socio socios[TMAX];
    leiaSocio(conts, socios);
    relatorio(conts, socios);
    return 0;
}
