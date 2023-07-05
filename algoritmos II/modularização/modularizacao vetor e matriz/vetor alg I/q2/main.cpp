#include <iostream>
#define TMAX 10

using namespace std;
/*
2. Em qualquer experiência, existe um certo erro associado às medidas. Uma técnica conhecida como
suavização pode ser utilizada para reduzir o efeito deste erro na análise dos resultados. Suponha que
uma série de n (n ≤ 10) valores do tipo real tenha sido registrada e armazenada em um vetor V. Antes
da análise destes resultados, a seguinte operação de suavização é aplicada aos valores de V (exceto
para o primeiro e último valor que não mudam): Vi é substituído por (Vi-1 + Vi + Vi+1) / 3. Faça um
algoritmo que leia as medidas iniciais e, então, escreva os valores observados (medidas iniciais) e os
suavizados.
*/
int leiaN(int inf, int sup, string msg);
void leiaVetor(int n, float v[TMAX]);
void suavizacao(int n, float v[], float vs[]);
void exibeVetor(int n, float v[]);

int main(){
    float v[TMAX];
    float vs[TMAX];
    int inf=0; int sup=TMAX;
    string msg="informe a qtd de termos: ";
    int n=leiaN(inf, sup, msg);
    preencheVetor(n, v);
    suavizacao(n, v, vs);
    exibeVetor(n, v);
    exibeVetor(n, vs);

    return 0;
}

int leiaN(int inf, int sup, string msg){
    int n;
    do{
    cout << msg << endl;
    cin >> n;
    }while(n<inf or n>sup);
    return n;
}

void leiaVetor(int n, float v[]){
    for(int i=0; i<n; i++){
        cout << i+1 << " posicao: ";
        cin >> v[i];
    }
}

void suavizacao(int n, float v[], float vs[]){
    vs[0] = v[0];
    vs[n-1] = v[n-1];
    for (int i=1; i<n-1; i++){
        vs[i] = (v[i-1] + v[i] + v[i+1])/3;
    }
}

void exibeVetor(int n, float v[]){
    for (int i=0; i<n; i++)
        cout << "[" << v[i] << "]";
    cout << endl;
}
