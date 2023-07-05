#include <iostream>

using namespace std;
//2. Faça um algoritmo que leia n pares de valores (n, r) e escreva, para cada par de valor, a combinação
//de n elementos agrupados r a r. Defina uma função para calcular a combinação de n elementos
//agrupados r a r utilizando a fórmula abaixo:

int leiaN();
int leiaR();
int calculo(int n, int r);
int fatorial(int n);

int main(){
    char resp;
    do{
        int n = leiaN();
        int r = leiaR();
        cout << calculo(n,r) << endl;

        cout << "mais um par de valores? S/N " << endl; cin.ignore(); cin.get(resp);

    }while(toupper(resp)=='S');
    return 0;
}

int leiaN(){
    int n;
    cout << "informe o valor de n: " << endl;
    cin >> n;
    return n;
}

int leiaR(){
    int r;
    cout << "informe o valor de r: " << endl;
    cin >> r;
    return r;
}

int calculo(int n, int r){
    int c = fatorial(n)/(fatorial(r)*fatorial(n-r));
    return c;
}

int fatorial(int n){
    int f=1;
    for (int i=n; i>0; i--){
        f *= i;
    }
    return f;
}
