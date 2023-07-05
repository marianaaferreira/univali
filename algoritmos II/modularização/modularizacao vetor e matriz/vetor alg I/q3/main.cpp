#include <iostream>
#define TMAX 15

using namespace std;
/*
Faça um algoritmo que leia dois vetores V e W com n (n ≤ 15) números reais. Determine os vetores
resultantes da soma de V e W, da subtração de V e W, da multiplicação de V e W, da divisão de V e W,
elemento a elemento. Determine também o produto escalar de V e W, definido como: Σ (Vi * Wi) = V1 *
W1 + V2 * W2 + ...+ Vn* Wn. Caso o produto escalar seja igual a zero, os vetores são classificados como
ORTOGONAIS.
*/
int leiaN(int inf, int sup, string msg);
void leiaVetor(int n, float v[]);
void somaVetores(int n, float v[], float w[], float soma[]);
void subVetores(int n, float v[], float w[], float sub[]);
void mutVetores(int n, float v[], float w[], float mut[]);
void divVetores(int n, float v[], float w[], float div[]);
float produtoEscalar(int n, float mut[]);
void exibeVetor(int n, float v[]);

int main(){
    float v[TMAX]; float w[TMAX];
    int inf=0; int sup=TMAX;
    string msg="informe a qtd de termos";
    int n=leiaN(inf, sup, msg);
    leiaVetor(n, v);
    leiaVetor(n, w);
    float soma[TMAX]; somaVetores(n, v, w, soma);
    float sub[TMAX]; subVetores(n, v, w, sub);
    float mut[TMAX]; mutVetores(n, v, w, mut);
    float div[TMAX]; divVetores(n, v, w, div);
    cout << "soma: " << endl; exibeVetor(n, soma);
    cout << "subtracao: " << endl; exibeVetor(n, sub);
    cout << "mutiplicacao: " << endl; exibeVetor(n, mut);
    cout << "divisao: " << endl; exibeVetor(n, div);
    cout << "produto escalar: " << produtoEscalar(n, mut);

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

void leiaVetor(int n, float v[]){
    for(int i=0; i<n; i++){
        cout << i+1 << " posicao: ";
        cin >> v[i];
    }
}

void somaVetores(int n, float v[], float w[], float soma[]){
    for (int i=0; i<n; i++){
        soma[i]=v[i]+w[i];
    }
}

void subVetores(int n, float v[], float w[], float sub[]){
    for (int i=0; i<n; i++){
        sub[i]=v[i]-w[i];
    }
}

void mutVetores(int n, float v[], float w[], float mut[]){
    for (int i=0; i<n; i++){
        mut[i]=v[i]*w[i];
    }
}

void divVetores(int n, float v[], float w[], float div[]){
    for (int i=0; i<n; i++){
        div[i]=v[i]/w[i];
    }
}

float produtoEscalar(int n, float mut[]){
    float pe=0;
    for (int i=0; i<n; i++){
        pe+=mut[i];
    }
    return pe;
}

void exibeVetor(int n, float v[]){
    for (int i=0; i<n; i++)
        cout << "[" << v[i] << "]";
    cout << endl;
}
