#include <iostream>
#define TMAX 10

using namespace std;
//Desenvolva um algoritmo que leia n (1 ≤ n ≤ 10) números inteiros e armazene-os no vetor X. Realize
//um processo que troque a disposição dos elementos do vetor X de forma que o primeiro elemento seja
//trocado com o último, o segundo seja trocado com o penúltimo e assim sucessivamente. Mostre os
//elementos do vetor X após este processo. Não utilizar vetor auxiliar.

int main(){
    int n, x[TMAX], temp;

    do{
        cout << "informe a qtd de elementos: " << endl;
        cin >> n;
    }while (n<0 or n>TMAX);
    for (int i=0; i<n; i++){
        cout << "informe o valor do " << i+1 << " elemento: "; cin >> x[i];
    }
    for (int i=0; i<n/2; i++){
        temp = x[i];
        x[i] = x[n-i-1];
        x[n-i-1] = temp;
    }
    for (int i=0; i<n; i++){
        cout << x[i] << " ";
    }


    return 0;
}
