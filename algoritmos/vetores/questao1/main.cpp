#include <iostream>
#define TMAX 20

using namespace std;

//Faça um algoritmo que leia o nome e a nota da prova de uma turma de n (n ≤ 20) estudantes, e
//armazene as informações em vetores. Calcule a média da turma. Apresente o nome dos estudantes
//cuja a nota é maior ou igual a média da turma e determine também quantos estudantes obtiveram nota
//abaixo da média da turma.

int main(){
    string nomes[TMAX];
    float notas[TMAX], media=0;
    int n, alunosabaixo=0;

    do{
        cout << "Informe a quantidade de alunos: " << endl;
        cin >> n;
    }while (n <0 or n > 20);

    for (int i=0; i < n; i++){
       cin.ignore();
       cout << "Informe o nome: " << endl;
       getline(cin, nomes[i]);
       cout << "Informe a nota: " << endl;
       cin >> notas[i];
    }

    for (int i=0; i<n; i++){
        media += notas[i];
    }
    media = media/n;

    cout <<"Alunos com nota acima ou igual a media: " << endl;
    for (int i=0; i<n; i++){
        if (notas[i] >= media){
            cout << nomes[i] << endl;
        }else {
           alunosabaixo++;
        }
    }

    cout << "quantidade de alunos abaixo da media: " << endl;
    cout << alunosabaixo;
    return 0;
}
