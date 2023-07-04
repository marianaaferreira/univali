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
    int n;
    float vs[TMAX], vi[TMAX];
    do{
      cout << "informe o valor de n: " << endl;
      cin >> n;
    }while(n>10 or n<0);
    for(int i=0; i<TMAX; i++){
       cout << "informe o valor do " << i+1 << " valor: " << endl;
       cin >> vi[i];
    }

    for (int i=1; i<n-1; i++){
       vs[i] = (vi[i-1]+vi[i]+vi[i+1])/3;
    }
    vs[0] = vi[0];
    vs[n-1] = vi[n-1];

    cout << "vetor inicial: " << endl;
    for (int i=0; i<n; i++){
        cout << vi[i] << " ";
    }

    cout << "vetor suavizado: " << endl;
    for (int i=0; i<n; i++){
        cout << vs[i] << " ";
    }

    return 0;
}
