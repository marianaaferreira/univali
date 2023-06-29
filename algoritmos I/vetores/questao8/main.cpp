#include <iostream>
#define TMAX 15

using namespace std;
//Faça um algoritmo que leia n (n ≤ 15) números inteiros e armazene-os em um vetor. Coloque-o em
//ordem crescente. Mostre o vetor após a ordenação.

int main(){
     int v[TMAX], n, temp;
    do{
        cout << "Informe a qtd de termos do vetor: " << endl;
        cin >> n;
    }while (n<1 or n>TMAX);

    for (int i=0; i<n; i++){
        cout << i+1 << " elemento: " << endl;
        cin >> v[i];
    }

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (v[i]>v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
