#include <iostream>
#define TMAX 15

using namespace std;
//Faça um algoritmo que leia dois vetores V e W com n (n ≤ 15) números reais. Determine os vetores
//resultantes da soma de V e W, da subtração de V e W, da multiplicação de V e W, da divisão de V e W,
//elemento a elemento. Determine também o produto escalar de V e W, definido como: Σ (Vi * Wi) = V1 *
//W1 + V2 * W2 + ...+ Vn* Wn. Caso o produto escalar seja igual a zero, os vetores são classificados como
//ORTOGONAIS.

int main(){
    float v[TMAX], w[TMAX], soma[TMAX], subtracao[TMAX], mut[TMAX], div[TMAX], prodescalar;
    int n;
    do{
        cout << "Informe a qtd de termos do vetor V e W: " << endl;
        cin >> n;
    }while (n>15 or n<1);
    //leitura de dados
    cout << "vetor v" << endl;
    for (int i=0; i<n; i++){
        cout << i+1 << "o. elemento: ";
        cin >> v[i];
    }
    cout << "vetor w" << endl;
    for (int i=0; i<n; i++){
        cout << i+1 << "o. elemento: ";
        cin >> w[i];
    }
    //soma
    for (int i=0; i<n; i++){
        soma[i]=v[i]+w[i];
    }
    //subtracao
    for (int i=0; i<n; i++){
        subtracao[i]=v[i]-w[i];
    }
    //mutiplicação
    for (int i=0; i<n; i++){
        mut[i]= v[i]*w[i];
    }
    //divisão
    for (int i=0; i<n; i++){
        div[i]= v[i]/w[i];
    }
    //produto escalar
    for (int i=0; i<n; i++){
        prodescalar += (v[i]*w[i]);
    }
    //relatorio
    for (int i=0; i<n; i++){
        cout << "soma do "<< i+1<< " elemento" << soma[i] << endl;
    }
    for (int i=0; i<n; i++){
        cout << "subtracao do "<< i+1<< " elemento" << subtracao[i] << endl;
    }
    for (int i=0; i<n; i++){
        cout << "mutiplicacao do "<< i+1<< " elemento" << mut[i] << endl;
    }
    for (int i=0; i<n; i++){
        cout << "divisao do "<< i+1<< " elemento" << div[i] << endl;
    }
    cout << "produto escalar: " << prodescalar;




    return 0;
}
