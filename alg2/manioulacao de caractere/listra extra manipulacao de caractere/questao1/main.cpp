#include <iostream>
#include <cstring>

using namespace std;
//1. Faça um programa que receba uma frase e imprima esta frase de maneira invertida,
//trocando também as letras A por *.


int main(){
    string frase;
    int tam;
    char temp;

    cout << "informe a frase: ";
    getline(cin, frase);

    tam = frase.size();
    for (int i=tam-1; i>=0; i--){
        if (frase.at(i)=='a' or frase.at(i)=='A'){
                frase.at(i) = '*';
        }
        cout << frase.at(i);
    }

    return 0;
}
