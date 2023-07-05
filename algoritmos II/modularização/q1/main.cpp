#include <iostream>

using namespace std;
//1. Fa�a um algoritmo que leia um n�mero inteiro n maior ou igual a zero e calcule o fatorial de n
//(usualmente escrito como n!). O fatorial � calculado como o produto n * (n -1) * (n - 2) * ... * 2 * 1. Isto
//nada mais � do que uma s�rie de multiplica��es repetidas, onde o multiplicador � reduzido de 1 antes
//de cada multiplica��o. Defina uma fun��o para calcular o fatorial.

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
