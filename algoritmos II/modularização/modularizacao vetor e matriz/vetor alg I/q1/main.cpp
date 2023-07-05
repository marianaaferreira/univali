#include <iostream>
#define TMAX 20

using namespace std;
/*
1. Faça um algoritmo que leia o nome e a nota da prova de uma turma de n (n ≤ 20) estudantes, e
armazene as informações em vetores. Calcule a média da turma. Apresente o nome dos estudantes
cuja a nota é maior ou igual a média da turma e determine também quantos estudantes obtiveram nota
abaixo da média da turma.
*/
int leiaN(int inf, int sup, string msg);
string leiaNome();
float leiaNota();
void leiaVetNomes(int n, string[TMAX]);
void leiaVetNotas(int n, float notas[TMAX]);
float calculoMedia(int n);
void alunosAcimaMedia(int n, float notas[], string nomes[]);
int contAlunosAbaixoMedia(int n, float notas[]);

int main(){
    string msg = "Informe a qtd de alunos: ";
    int inf=0; int sup=20;
    int n= leiaN(inf, sup, msg);
    string nomes[TMAX];
    float notas[TMAX];
    leiaVetNomes(n, nomes);
    leiaVetNotas(n, notas);
    alunosAcimaMedia(n, notas, nomes);
    cout << "qtd de alunos abaixo da media: " << contAlunosAbaixoMedia(n, notas);

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

string leiaNome(){
    string nome;
    cout << "informe o nome: " << endl;
    cin.ignore();
    getline(cin, nome);
    return nome;
}

float leiaNota(){
    float nota;
    cout << "informe a nota: " << endl;
    cin >> nota;
    return nota;
}

void leiaVetNomes(int n, string nomes[]){
    for(int i=0; i<n; i++){
       nomes[i]= leiaNome();
    }
}

void leiaVetNotas(int n, float notas[]){
    for(int i=0; i<n; i++){
        notas[i]= leiaNota();
    }
}

float calculoMedia(int n, float notas[]){
    float media=0;
    for(int i=0; i<n; i++){
        media+=notas[i];
    }
    return media/n;
}

void alunosAcimaMedia(int n, float notas[], string nomes[]){
    cout << "alunos acima da media: " << endl;
    for (int i=0; i<n; i++){
        if(notas[i]>=calculoMedia(n, notas)){
            cout << nomes[i];
        }
    }
}

int contAlunosAbaixoMedia(int n, float notas[]){
    int cont=0;
    for (int i=0; i<n; i++){
        if(notas[i]<calculoMedia(n, notas)){
            cont++;
        }
    }
    return cont;
}


