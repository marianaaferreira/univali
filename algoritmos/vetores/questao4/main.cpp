#include <iostream>
#define TMAX 15

using namespace std;
//Faça um algoritmo que leia um vetor V com n (n ≤ 15) número inteiros. Determine o menor e o maior
//elemento do vetor.

int main(){
    int v[TMAX], n, temp;

    do{
        cout << "Informe a qtd de termos do vetor V: " << endl;
        cin >> n;
    }while (n<1 or n >15);

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
    cout << "Maior elemento: " << v[n-1] << endl;
    cout << "menor elemento: " << v[0];

    return 0;
}
