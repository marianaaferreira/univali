#include <iostream>
#include <vector>

using namespace std;
//P9.7. Escreva uma função predicado bool equals(vector<int> a, vector<int>
//b) que verifica se dois vetores têm os mesmos elementos na mesma ordem.

vector<int> preencheVetor(vector<int>v){
    bool continuar=true;
    int elemento;
    while(continuar){
        cout << "elemento:\n"; cin >> elemento;
        v.push_back(elemento);
        cout << "continuar?S[1], N[0]\n"; cin>>continuar;
    }
    return v;
}

bool verificaVetoresIguais(vector<int>a, vector<int>b){
    if(a.size()!=b.size())
        return false;
    for(int i=0; i<a.size(); i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main(){
    vector<int>a; vector<int>b;
    cout << "vetor a:\n"; a = preencheVetor(a);
    cout << "vetor b:\n"; b = preencheVetor(b);

    if(verificaVetoresIguais(a, b))
        cout << "vetores iguais";
    else
        cout << "vetores diferentes";

    return 0;
}
