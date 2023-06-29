#include <iostream>
#define TMAX 15

using namespace std;
//Faça um algoritmo que leia um vetor V com n (n ≤ 15) número inteiros. Determine o menor e o maior
//elemento do vetor.

int main(){
    int n, v[TMAX], temp;

    do{
        cout << "informe o numero de termos: " << endl;
        cin >> n;
    }while(n>TMAX or n<0);

    for (int i=0; i<n; i++){
        cout << "Informe o " << i+1 << " elemento: ";
        cin >> v[i];
        cout << endl;
    }
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (v[j] < v[i]){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            }
        }
    }
    cout << "menor: " << v[0] << endl;
    cout << "maior: " << v[n-1] << endl;

    return 0;
}
