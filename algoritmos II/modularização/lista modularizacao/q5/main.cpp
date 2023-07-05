#include <iostream>

using namespace std;
/*
5. Faça um algoritmo que leia n pares de valores (x, y) e calcule, para cada par de valor, xy. Defina uma
função para efetuar o cálculo solicitado, sem utilizar nenhuma função pré-definida do C. Considere que
y é um número inteiro.
*/
int main();
int leiaN();
float leiaX();
int leiaY();
float calculoXY(float x, int y);

int main(){
    int n = leiaN();
    for (int i=0; i<n; i++){
        float x = leiaX();
        int y = leiaY();
        calculoXY(x, y);
    }
    return 0;
}

int leiaN(){
    int n;
    cout << "informe o valor de n:" << endl;
    cin >> n;
}

float leiaX(){
    float x;
    cout << "informe o valor de x:" << endl;
    cin >> x;
}

int leiaY(){
    int y;
    cout << "informe o valor de y:" << endl;
    cin >> y;
}

float calculoXY(float x, int y){
    int c =
    return x*y;
}
