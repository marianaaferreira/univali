#include <iostream>

using namespace std;

int main(){
    int n, mut;
    int matriz [10][10]={{0}}, vetor[10], soma=0, somadiagonal, p, q, temporario[10];

    do{
    cout << "Informe a ordem da matriz: " << endl;
    cin >> n;
    }while(n<=10 and n>=10);
    // leitura da matriz
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "[" << i+1 << "," << j+1 << "]:";
            cin >> matriz[i][j];
        }
    }
    //soma da segunda coluna
    for (int i=0; i<n; i++){
        soma += matriz[i][1];
    }
    //mutiplicaçao das linhas
    for (int i=0; i<n; i++){
        mut =0;
        for (int j=0; j<n; j++){
          mut = mut * matriz[i][j];
        }
       vetor[i] = mut;
    }
    for (int i=0; i<n; i++){
        cout << vetor[i] << " ";
    }
    //some todos os elementos da matriz
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            soma += matriz[i][j];
        }
    }
    //some os elementos da diagonal principal
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j){
                somadiagonal += matriz[i][j];
            }
        }
    }
    cout << "soma diagonal: " << somadiagonal << endl;

    //permute os elementos das linhas p e q
    cout << "Informe a linha que quer permutar: (p) " << endl;
    cin >> p;
    cout << "Informe a linha que quer permutar: (q) " << endl;
    cin >> q;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
              temporario[i] = matriz[p][j];
              matriz[p][j] = matriz [q][j];
              matriz[q][j] = temporario[i];
            }
        }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
