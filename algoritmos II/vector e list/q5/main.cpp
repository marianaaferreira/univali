#include <iostream>
#include <vector>

using namespace std;
/*P9.5. Escreva uma função vector<int> merge(vector<int> a, vector<int> b)
que intercala dois arrays, alternando elementos dos dois arrays. Se um array é mais
curto do que o outro, então alterne enquanto você puder e depois acrescente os elementos
restantes do array mais longo.
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

vector<int> intercalaVetor(vector<int>a, vector<int>b){
    vector<int>c;
    int menor, i;
    char maior;
    if(a.size()<b.size()){
        menor = a.size();
        maior = 'b';
    }
    else{
        menor = b.size();
        maior = 'a';
    }
    for(i=0; i<menor; i++){
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    if(maior=='a')
        for(; i<a.size(); i++)
            c.push_back(a[i]);
    else
        for(; i<b.size(); i++)
            c.push_back(b[i]);
    return c;
}

void mostraVetor(vector<int>v){
    for(int i=0; i<v.size(); i++)
        cout << "[" << v[i] << "]";
}

int main(){
    vector<int>a; vector<int>b; vector<int>c;
    cout << "vetor a:\n"; a = preencheVetor(a);
    cout << "vetor b:\n"; b = preencheVetor(b);

    c = intercalaVetor(a, b);

    cout << "\nvetor a:\n"; mostraVetor(a);
    cout << "\nvetor b:\n"; mostraVetor(b);
    cout << "\nvetor c:\n"; mostraVetor(c);

    return 0;
}
