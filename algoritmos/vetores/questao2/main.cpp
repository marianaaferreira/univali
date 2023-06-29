#include <iostream>
#define TMAX 10

using namespace std;

//Em qualquer experiência, existe um certo erro associado às medidas. Uma técnica conhecida como
//suavização pode ser utilizada para reduzir o efeito deste erro na análise dos resultados. Suponha que
//uma série de n (n ≤ 10) valores do tipo real tenha sido registrada e armazenada em um vetor V. Antes
//da análise destes resultados, a seguinte operação de suavização é aplicada aos valores de V (exceto
//para o primeiro e último valor que não mudam): Vi é substituído por (Vi-1 + Vi + Vi+1) / 3. Faça um
//algoritmo que leia as medidas iniciais e, então, escreva os valores observados (medidas iniciais) e os
//suavizados.

int main(){
    float v[TMAX];
    int n;
    do{
        cout << "Informe a qtd de termos: " << endl;
        cin >> n;
    }while(n<1 or n>TMAX);


    for (int i=0; i<n; i++){
        cout << i+1 << "elemento: ";
        cin >> v[i];
        cout << endl;
    }

    for (int i=1; i<n-1; i++){
        v[i] = (v[i-1]+v[i]+v[i+1])/3;
    }

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    return 0;
}
