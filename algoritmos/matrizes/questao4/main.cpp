#include <iostream>
#include <iomanip>
#define TMAX1 15
#define TMAX2 25

using namespace std;
//Faça um algoritmo que leia uma matriz AnXm (1 ≤ n ≤ 15, 1 ≤ m ≤ 25) de números reais e:
//1. gere uma matriz B que seja a matriz transposta de A;
//2. verifique se a matriz A é simétrica (uma matriz é simétrica quando é quadrada e quando
//aji = aij).

int main(){

    float a[TMAX1][TMAX2], b[TMAX1][TMAX2], temp;
    int n, m;
    bool simetrica=true;

    do{
        cout << "Informe a qtd de linhas: " << endl;
        cin >> n;
    }while(n<1 or n>15);
    do{
        cout << "Informe a qtd de colunas: " << endl;
        cin >> m;
    }while(m<1 or m>25);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << "[" << i+1 << "," << j+1 << "]:";
            cin >> a[i][j];
            cout << endl;
        }
    }
    cout << "matriz original" << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            b[i][j] = a[j][i];
            b[j][i]= a[i][j];
        }
    }
    cout << "matriz transposta" << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                cout << b[i][j] << " ";
        }
        cout << endl;
    }
    //verificar se é simetrica
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
           if (a[i][j]!= a[j][i] or i!=j){
             simetrica = false;
        }
    }
    }
    if (simetrica==true){
        cout << "A matriz A e simetrica.";
    }else {
        cout << "A matriz A nao e simetrica.";
    }
    return 0;
}
