#include <iostream>
#include <cmath>

using namespace std;
//3. Faça um algoritmo que leia n valores inteiros representando o valor de um ângulo e escreva o seno,
//o cosseno e a tangente do ângulo lido. Defina funções para calcular o seno, o cosseno e a tangente de
//um dado ângulo em radianos utilizando as fórmulas abaixo:

    int leiaAngulo();
    int fatorial(int n);
    float calculoSeno(int angulo);
    float calculoCosseno(int angulo);
    float calculoTangente(float seno, float cosseno);
    void saida(float seno, float cosseno, float tangente);

int main(){
    int angulo = leiaAngulo();
    float seno = calculoSeno(angulo);
    float cosseno = calculoCosseno(angulo);
    float tangente = calculoTangente(seno, cosseno);
    saida(seno, cosseno, tangente);
    return 0;
}

int leiaAngulo (){
    int angulo;
    cout << "informe o valor do angulo: "; cin >> angulo;
    return angulo;
}

int fatorial(int n){
    int f=1;
    for (int i=n; i>0; i--){
        f *= i;
    }
    return f;
}

float calculoSeno(int angulo){
 // for (int i=3; cont<20; i+=2){
    int i = 3;
    int cont = 0;
    float seno = angulo;
    do{
        if(cont%2==0){
            seno -= pow(angulo, i)/fatorial(i);
        }else{
            seno += pow(angulo, i)/fatorial(i);
        }
        cont++;
        i+=2;
    }while (cont<20);
    return seno;
}

float calculoCosseno(int angulo){
    int i = 2;
    int cont = 0;
    float cosseno = 1;
    do{
        if(cont%2==0){
            cosseno -= pow(angulo, i)/fatorial(i);
        }else{
            cosseno += pow(angulo, i)/fatorial(i);
        }
        cont++;
        i+=2;
    }while (cont<20);
    return cosseno;
}

float calculoTangente (float seno, float cosseno){
    float tangente = seno/cosseno;
    return tangente;
}

void saida(float seno, float cosseno, float tangente){
    cout << "seno: " << seno << endl;
    cout << "cosseno: " << cosseno << endl;
    cout << "tangente: " << tangente << endl;
}

