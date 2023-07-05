#include <iostream>
#define TMAX 3000
#define TMAXP 42

using namespace std;
/*
7. Uma empresa de turismo fez uma pesquisa em Florianópolis, na temporada de verão deste ano,
questionando sobre a praia de preferência e a renda mensal de um grupo composto por n (n ≤ 3000)
turistas. As praias foram identificadas por códigos (1 a 42). Faça um algoritmo que escreva, por praia,
o número de turistas que a preferem e a renda média destes turistas.
*/
char maisTuristas();
void qtdTuristasPraia(int praia[]);
void exibeVetor(int n, int v[]);

int main(){
    int praia[TMAXP];
    int turistas=1;
    do{
        qtdTuristasPraia(praia);
        if (maisTuristas()=='S'){
            turistas++;
        }
    }while (turistas<=TMAX or maisTuristas()=='N');
    exibeVetor(turistas-1, praia);
    return 0;
}

char maisTuristas(){
    char resp;
    cout << "Mais um turistas? S/N" << endl;
    cin.ignore();
    cin.get(resp);
    return toupper(resp);
}

void qtdTuristasPraia(int praia[]){
    int p;
    do{
        cout << "informe a praia favorita: (1 a 42)" << endl;
        cin >> p;
    }while (p<0 or p>42);
    praia[p-1]++;
}

void exibeVetor(int n, int v[]){
    for (int i=0; i<n; i++)
        cout << "[" << v[i] << "]";
    cout << endl;
}








