#include <iostream>
#define TMAX 5

using namespace std;
/*6. Construa um algoritmo que leia matr�cula, nome e os dados dos dependentes de
v�rios s�cios de um clube. Para cada dependente, leia nome e data de nascimento.
Na sequ�ncia, escreva o nome do s�cio e os nomes de seus dependentes, para todos
os s�cios que tiverem mais de 3 dependentes. Admita que cada s�cio tenha no
m�ximo 5 dependentes. */

typedef struct{
    string matricula, nomeS;
    typedef struct{
        string nomeD, data;
    }dependente;
}socio;

int leiaNLimSup(int lsup){
    int n;
    do{
        cout << "Qtd desejada: ";
        cin >> n;
    }while(n<=0 or n>lsup);
    return n;
}

void leiaDependente(int nd, int conts, dependente dependentes[], socio socios[]){
    cout << "Dependente" << endl;
    for (int i=0; i<nd; i++){
        cout << "nome:\n";
        getline(cin, socios[conts].dependentes[i].nomeD);
        cout << "data de nascimento:\n";
        getline(cin, socios[conts].dependentes[i].data);
    }
}

void leiaSocio(socio socios){
    cout << "Socio" << endl;
    do{
        cout << "nome:\n";
        getline(cin, socios[i].nomeS);
        cout << "matricula:\n";
        getline(cin, socios[i].matricula);
        nd = leiaNLimSup(5);
        leiaDependente(nd, conts, dependentes, socios);
        conts++;
    }while(cotinuar or conts>=TMAX);
}

int main(){
    int nd, conts=0;
    socio socios[TMAX];
    dependente dependentes[5];
    leiaSocio(socios);

    return 0;
}
