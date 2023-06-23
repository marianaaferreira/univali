#include <iostream>
#include <vector>

using namespace std;
/*P9.4. Escreva uma função vector<int> append(vector<int> a, vector<int> b)
que acrescenta um vetor após outro.
P.ex.vetor 1,4,9,16 e b 9,7,4,9,11 então append retorna o vetor 1,4,9,16,9,7,4,9,11*/

vector<int> append(vector<int>a, vector<int>b){
    for(int i=0; i<b.size(); i++)
        a.push_back(b[i]);
    return a;
}
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

void mostraVetor(vector<int>v){
    for(int i=0; i<v.size(); i++)
        cout << "[" << v[i] << "]";
}

int main(){
    vector<int>a; vector<int>b; vector<int>c;
    cout << "vetor a:\n"; a = preencheVetor(a);
    cout << "vetor b:\n"; b = preencheVetor(b);

    c = append(a, b);

    cout << "\nvetor a:\n"; mostraVetor(a);
    cout << "\nvetor b:\n"; mostraVetor(b);
    cout << "\nvetor c:\n"; mostraVetor(c);

    return 0;
}
