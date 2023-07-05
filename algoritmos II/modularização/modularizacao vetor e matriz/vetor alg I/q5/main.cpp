#include <iostream>
#define TMAX 100

using namespace std;
/*
5. Faça um algoritmo que leia n (n ≤ 100) pares de valores, sendo o primeiro valor o número de inscrição
do atleta e o segundo a altura (em cm) do atleta, e armazene-os em vetores. Apresente ao final o número
de inscrição e a altura do atleta mais alto, o número de inscrição e a altura do atleta mais baixo e a
altura média do grupo de atletas.
*/
int leiaN(int inf, int sup, string msg);
void leiaInscr(int&i, int inscr[]);
void leiaAlt(int&i, int alt[]);
void ordenacaoVetor(int n, int v[], int vaux[]);
float media(int n, int v[]);
void mostraMaiorEMenor(int n, int v[], int vaux[]);

int main(){
    int inscr[TMAX]; int alt[TMAX];
    int inf=0; int sup=TMAX;
    string msg="informe a qtd de atletas";
    int n=leiaN(inf, sup, msg);
    for (int i=0; i<n; i++){
        leiaInscr(i, inscr);
        leiaAlt(i, alt);
    }
    ordenacaoVetor(n, alt, inscr);
    mostraMaiorEMenor(n, inscr, alt);
    cout << "media: " << media(n, alt);

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

void leiaInscr(int&i, int inscr[]){
    cout << "informe a inscricao: ";
    cin>>inscr[i];
}

void leiaAlt(int&i, int alt[]){
    cout << "informe a altura: ";
    cin>>alt[i];
}

void ordenacaoVetor(int n, int v[], int vaux[]){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(v[i]>v[j]){
                swap(v[i], v[j]);
                swap(vaux[i], vaux[j]);
            }
        }
    }
}

float media(int n, int v[]){
    float soma=0;
    for (int i=0; i<n; i++){
        soma+=v[i];
    }
    return soma/n;
}

void mostraMaiorEMenor(int n, int v[], int vaux[]){
    cout << "atleta mais baixo: " << endl;
    cout << "inscricao: " << v[0] << endl;
    cout << "altura: " << vaux[0] << endl;
    cout << "atleta mais alto: " << endl;
    cout << "inscricao: " << v[n-1] << endl;
    cout << "altura: " << vaux[n-1] << endl;
}
