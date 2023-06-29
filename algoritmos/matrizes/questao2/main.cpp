#include <iostream>
#define TMAX1 15
#define TMAX2 25

using namespace std;
//2. Faça um algoritmo que leia uma matriz AnXm (1 ≤ n ≤ 15, 1 ≤ m ≤ 25) de números inteiros e
//calcule o vetor resultante da soma dos elementos de cada linha da matriz.

int main(){
    int matriz[TMAX1][TMAX2], n, m;
    float vetor[TMAX1]={0};
    do {
    cout << "Informe o numero de linhas da matriz: " << endl;
    cin >> n;
    }while (n>15 or m<1);
    do{
    cout << "Informe o numero de colunas da matriz: " << endl;
    cin >> m;
    }while (m>25 or m<1);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << "[" << i+1 << "," << j+1 << "]:";
            cin >> matriz [i][j];
            cout << endl;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            vetor[i] += matriz[i][j];
        }
    }

    for (int i=0; i<n; i++){
        cout << vetor[i] << " ";
    }


    return 0;
}
