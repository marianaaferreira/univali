#include <iostream>
#include <vector>

using namespace std;
/*P9.8. Escreva uma função predicado bool same_set(vector<int> a, vector<int>
b) que verifica se dois vetores têm os mesmos elementos em alguma ordem, ignorando
multiplicidades.
P.ex., os dois vetores 1,4,9,16,9,7,4,9,11 e 11,11,7,9,16,4,1 seriam considerados idênticos.
Você provavelmente vai precisar de uma ou mais funções auxiliares.
*/

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

bool verificaVetorMesmosValores(vector<int>a, vector<int>b){
    bool existe;
    for(int i=0; i<a.size(); i++){
        existe = false;
        for(int j=0; j<b.size(); j++){
            if(a[i]==b[j])
                existe=true;
        }
        if(not existe)
            return false;
    }
    return true;
}

int main(){
    vector<int>a; vector<int>b;
    cout << "vetor a:\n"; a = preencheVetor(a);
    cout << "vetor b:\n"; b = preencheVetor(b);

    if(verificaVetorMesmosValores(a, b))
        cout << "vetor com os mesmos valores";
    else
        cout << "vetor com valores diferentes";

    return 0;
}
