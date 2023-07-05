#include <iostream>
#define TMAX 15

using namespace std;
//4. Faça um algoritmo que leia um vetor V com n (n ≤ 15) número inteiros. Determine o menor e o maior
//elemento do vetor.

int leiaN(int inf, int sup, string msg);
void leiaVetor(int n, int v[]);
void ordenacaoVetor(int n, int v[]);
void exibeVetor(int n, int v[]);

int main(){
    int v[TMAX];
    int inf=0; int sup=TMAX;
    string msg="informe a qtd de termos: ";
    int n=leiaN(inf, sup, msg);
    leiaVetor(n, v);
    ordenacaoVetor(n, v);
    cout << "maior: " << v[n-1];
    cout << "menor: " << v[0];
    return 0;
}

int leiaN(int inf, int sup, string msg){
    int n;
    do{
    cout << msg << endl;
    cin >> n;
    }while(n<inf or n>sup);
    return n;
}

void leiaVetor(int n, int v[]){
    for(int i=0; i<n; i++){
        cout << i+1 << " posicao: ";
        cin >> v[i];
    }
}

void ordenacaoVetor(int n, int v[]){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(v[i]>v[j]){
                swap(v[i], v[j]);
            }
        }
    }
}

