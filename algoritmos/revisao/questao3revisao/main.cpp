#include <iostream>
#define TMAX 15

using namespace std;
//Faça um algoritmo que leia dois vetores V e W com n (n ≤ 15) números reais. Determine os vetores
//resultantes da soma de V e W, da subtração de V e W, da multiplicação de V e W, da divisão de V e W,
//elemento a elemento. Determine também o produto escalar de V e W, definido como: Σ (Vi * Wi) = V1 *
//W1 + V2 * W2 + ...+ Vn* Wn. Caso o produto escalar seja igual a zero, os vetores são classificados como
//ORTOGONAIS.

int main(){
    int n;
    float v[TMAX], w[TMAX], soma[TMAX], sub[TMAX], mut[TMAX], div[TMAX], pe;
    do{
        cout << "informe o numero de termos: " << endl;
        cin >> n;
    }while(n>15 or n<0);
    for (int i=0; i<n; i++){
        cout << "informe o valor do " << i+1 << "elemento para v: ";
        cin >> v[i];
        cout << endl;
    }
    for (int i=0; i<n; i++){
        cout << "informe o valor do " << i+1 << "elemento para w: ";
        cin >> w[i];
        cout << endl;
    }
    for (int i=0; i<n; i++){
       soma[i] = v[i] + w[i];
       sub[i] = v[i] - w[i];
       mut[i] = v[i] * w[i];
       div[i] = v[i] / w[i];
       pe += v[i] * w[i];
    }
    //soma
    cout << "vetor soma";
    for (int i=0; i<n; i++){
       cout << soma[i] << " ";
    }
    //subtração
    cout << "vetor subtracao";
    for (int i=0; i<n; i++){
       cout << sub[i] << " ";
    }
    //multiplicação
    cout << "vetor mutiplicacao";
    for (int i=0; i<n; i++){
       cout << mut[i] << " ";
    }
    //divisão
    cout << "vetor divisao";
    for (int i=0; i<n; i++){
       cout << div[i] << " ";
    }
    cout << "produto escalar: " << pe;



    return 0;
}
