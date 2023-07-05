#include <iostream>

using namespace std;
//1. Faça um algoritmo que leia um número inteiro n maior ou igual a zero e calcule o fatorial de n
//(usualmente escrito como n!). O fatorial é calculado como o produto n * (n -1) * (n - 2) * ... * 2 * 1. Isto
//nada mais é do que uma série de multiplicações repetidas, onde o multiplicador é reduzido de 1 antes
//de cada multiplicação. Defina uma função para calcular o fatorial.

int leiaN();
int fatorial(int n);

int main(){
    int n = leiaN();
    cout << fatorial(n);
}

int leiaN(){
    int n;
    cout << "informe o valor que deseja fazer o fatorial: " << endl;
    cin >> n;
    return n;
}

int fatorial(int n){
    int f=1;
    for (int i=n; i>0; i--){
        f *= i;
    }
    return f;
}
