#include <iostream>
#include <vector>

using namespace std;
//P9.3. Escreva um procedimento reverse que inverte a sequência dos elementos em um
//vetor.

void inverteVetor(vector<int>&v){
    for(int i=0; i<v.size()/2; i++){
        swap(v[i], v[v.size()-i-1]);
    }
}

int main(){
    bool continuar=true;
    int elemento;
    vector<int>v;
    while(continuar){
        cout << "elemento:\n"; cin >> elemento;
        v.push_back(elemento);
        cout << "continuar?S[1], N[0]\n"; cin>>continuar;
    }
    for(int i=0; i<v.size(); i++)
        cout << "[" << v[i] << "]";
    cout << "\nvetor invertido:\n";
    inverteVetor(v);
    for(int i=0; i<v.size(); i++)
        cout << "[" << v[i] << "]";
    return 0;
}
