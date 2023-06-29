#include <iostream>
#define TMAX 20

using namespace std;
//Faça um algoritmo que leia o nome e a nota da prova de uma turma de n (n ≤ 20) estudantes, e
//armazene as informações em vetores. Calcule a média da turma. Apresente o nome dos estudantes
//cuja a nota é maior ou igual a média da turma e determine também quantos estudantes obtiveram nota
//abaixo da média da turma.


int main(){
    int n, j=0, contAbaixo=0;
    string nomes[TMAX], media=0;

    do{
        cout << "qtd de alunos: " << endl;
        cin >> n;
    }while(n<=0 or n>TMAX);

    for(int i=0; i<n, i++){
       cout << "nome: " << endl;
       getline(cin)
    }

    return 0;
}
