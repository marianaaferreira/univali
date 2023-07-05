#include <iostream>
#define TMAX 10

using namespace std;
/*
6. Desenvolva um algoritmo que leia n (1 ≤ n ≤ 10) números inteiros e armazene-os no vetor X. Realize
um processo que troque a disposição dos elementos do vetor X de forma que o primeiro elemento seja
trocado com o último, o segundo seja trocado com o penúltimo e assim sucessivamente. Mostre os
elementos do vetor X após este processo. Não utilizar vetor auxiliar
*/
int leiaN(int inf, int sup, string msg);
void leiaVetor(int n, int v[]);
void inverteVetor(int n, int v[]);
void exibeVetor(int n, int v[]);

int main(){
    int x[TMAX];
    int inf=0; int sup=TMAX;
    string msg="informe a qtd de termos: ";
    int n=leiaN(inf, sup, msg);
    leiaVetor(n, x);
    inverteVetor(n, x);
    exibeVetor(n, x);

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

void inverteVetor(int n, int v[]){
    for (int i=0; i<n/2; i++){
        swap(v[i], v[n-i-1]);
    }
}

void exibeVetor(int n, int v[]){
    for (int i=0; i<n; i++)
        cout << "[" << v[i] << "]";
    cout << endl;
}
