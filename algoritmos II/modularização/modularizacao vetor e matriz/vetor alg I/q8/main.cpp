#include <iostream>
#define TMAX 15

using namespace std;
//8. Faça um algoritmo que leia n (n ≤ 15) números inteiros e armazene-os em um vetor. Coloque-o em
//ordem crescente. Mostre o vetor após a ordenação.

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
    exibeVetor(n, v);

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

void exibeVetor(int n, int v[]){
    for (int i=0; i<n; i++)
        cout << "[" << v[i] << "]";
    cout << endl;
}

