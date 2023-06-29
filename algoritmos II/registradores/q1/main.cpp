#include <iostream>
#define TMAX 20

using namespace std;
//1. Declare um registro para representar um determinado aluno, contendo nome, notas
//de 4 provas e a sua média.

typedef struct{
    string nome;
    float notas[4], media;
} Aluno;

int leiaNLimSup(int);
void leiaTurma(int, Aluno[]);
void gerarMediaAluno(int, Aluno[]);
float gerarMediaTurma(int, Aluno[]);
void relatorioMF(int, Aluno[]);

int main(){
    Aluno turma[TMAX];
    int nAlunos = leiaNLimSup(TMAX);
    leiaTurma(nAlunos, turma);
    gerarMediaAluno(nAlunos, turma);
    relatorioMF(nAlunos, turma);
    return 0;
}

int leiaNLimSup(int lsup){
    int n;
    do{
        cout << "Qtd desejada: ";
        cin >> n;
    }while(n<=0 or n>lsup);
    return n;
}

void leiaTurma(int n, Aluno t[]){
    for(int i=0; i<n; i++){
        cin.ignore();
        cout << "Nome"; getline(cin, t[i].nome);
        for (int j=0; j<4; j++){
            cout << j+1 << "a nota: "; cin >> t[i].notas[j];
        }
        t[i].media  = 0;
    }
}

void gerarMediaAluno(int n, Aluno t[]){
    for(int i=0; i<n; i++){
        t[i].media  = 0;
        for (int j=0; j<4; j++){
            t[i].media += t[i].notas[j];
        }
        t[i].media = t[i].media/4;
    }
}

float gerarMediaTurma(int n, Aluno t[]){
    float mediaT=0;
    for (int i=0; i<n; i++){
        mediaT += t[i].media;
    }
    return mediaT/n;
}

void relatorioMF(int n, Aluno t[]){
    int cont = 0;
    float x = gerarMediaTurma(n, t);
    cout << "Relatorio MF" << endl;
    for(int i=0; i<n; i++){
        cout << t[i].nome << " " << t[i].media << endl;
        if(t[i].media<x) cont++;
    }
    cout << "Media da turma: " << x << endl;
    cout << "Qtd alunos abaixo da media: " << cont << endl;
}

