#include <iostream>
#include <cstring>

using namespace std;
//2. Faça um programa que recebe uma string A e inteiros positivos I e J e mostre o
//segmento A[I..J].

int main(){
    string a;
    int i, j;

    cout << "informe a string: ";
    getline(cin, a);
    cout << "informe os os valores para i e j: "; cin >>i; cin >> j;

    for (int k=i; k<=j; k++){
        cout << a[k];
    }

    return 0;
}
