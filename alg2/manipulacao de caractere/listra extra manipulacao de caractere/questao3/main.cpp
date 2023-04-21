#include <iostream>
#include <cstring>

using namespace std;
//3. Faça um programa que recebe do usuário uma string A e monte uma nova string B
//cujo conteúdo é a string A sem suas vogais. Mostre B ao final.

int main(){
    int cont=0;
    string a, b;

    cout << "informe a string a: ";
    getline(cin, a);

    for (int i=0; i<a.size(); i++){
        if (a[i]!='a' and a[i]!='e' and a[i]!='i' and a[i]!= 'o' and a[i]!= 'u'){
            b[cont] = a[i];
            cont++;
        }
    }

    for (int i=0; i<cont; i++){
        cout << b[i];
    }

    return 0;
}
