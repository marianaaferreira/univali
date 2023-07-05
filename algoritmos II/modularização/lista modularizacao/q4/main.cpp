#include <iostream>

using namespace std;
/*4. Faça um algoritmo que calcule os sucessivos valores de "E" usando a série abaixo. O algoritmo deve
escrever o 1o termo da série, a soma dos dois primeiros termos da série, a soma dos três primeiros da
série e assim por diante.
O valor de n (n > 0) deve ser lido. Defina uma função para calcular o valor de E.
*/
int fatorial(int n);
int leiaN();
float calculoE(float &e, int&i);
int main();

int main(){
    float e = 0;
    int i=0;
    int n = leiaN();
    for (int j=0; j<n; j++){
        e = calculoE(e, i);
        cout << e << ", ";
    }

    return 0;
}

int fatorial(int n){
    int f=1;
    for (int i=n; i>0; i--){
        f *= i;
    }
    return f;
}

int leiaN(){
    int n;
    cout << "informe o valor de n: " << endl;
    cin >>n;
    return n;
}

float calculoE(float &e, int&i){
    e += 1.0/fatorial(i);
    i++;
    return e;
}


