#include <iostream>
#define TMAX 30

using namespace std;
//Faça um algoritmo que leia n (n ≤ 30) nomes e notas finais dos estudantes de uma turma e armazene
//estas informações em vetores. Em seguida, dado um nome pesquise sua existência na turma, e caso
//exista mostre a nota final correspondente. Caso contrário, apresente mensagem de pessoa inexistente.
//Faça isso até que o usuário não queira mais pesquisar.


int main(){
    int n;
    string nomes[TMAX], nome;
    float notas[i];
    bool encontrou=false;

    do{
        cout "Informe a qtd de termos: " << endl;
        cin >> n;
    }while (n<1 or n>30);

    for (int i=0; i<n; i++ ){
        cout << "Informe o nome: " << endl;
        cin.getline(nomes[i]);
        cout << "Informe a nota: " << endl;
        cin >> notas[i];
    }
    cout << "Informe o nome que deseja pesquisar: " << endl;
    cin.getline(nome);
    for (int i=0; i<n; i++){
        if (nome == nomes[i])
        encontrou = true

    }


    return 0;
}
