#include <iostream>
#define TMAX 100

using namespace std;
//Faça um algoritmo que leia o conteúdo de um vetor X de n (1 ≤ n ≤ 100) elementos inteiros e “construa”
//um vetor Y contendo apenas os elementos primos de X.

int main(){
    int x[TMAX], y[TMAX],n, div=0, cont=0;
    do{
        cout << "Informe a qtd de termos: " << endl;
        cin >> n;
    }while(n<1 or n>TMAX);

    for (int i=0; i<n; i++){
        cout << i+1 << "elemento: ";
        cin >> x[i];
        cout << endl;
    }

    for (int i=0; i<n; i++){
        for (int j=x[i]-1; j=0; j--){
            if ((x[i]%(x[i]-j))==0){
            div++;
            }
        }
            if (div==2){
                y[cont] = x[i];
                cont++;
            }

    }

    for (int i=0; i<cont; i++){
        cout << y[i] << " ";
    }
    return 0;
}
