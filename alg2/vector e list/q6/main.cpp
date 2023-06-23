#include <iostream>
#include <vector>

using namespace std;
/*P9.6. Escreva uma função vector<int> merge_sorted(vector<int> a,
vector<int> b) que intercala dois arrays ordenados, produzindo um novo array
ordenado. Mantenha um índice para cada array, indicando quanto dele já foi processado.
A cada vez, acrescente o menor elemento não processado de qualquer um dos arrays,
então avance o índice.
P.ex., a é 1,4,9,16 e b é 4,7,9,9,11 então merge_sorted retorna o array
1,4,4,7,9,9,9,11,16
*/

vector<int> intercalaOrdenado(vector<int>a, vector<int>b){
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
        if(a[i]<=b[i]){
            c.push_back(a[i]);
            c.push_back(b[i]);
        }else{
            c.push_back(b[i]);
            c.push_back(a[i]);
        }
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
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    b.push_back(2);
    b.push_back(4);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
    b.push_back(9);

    c = intercalaOrdenado(a, b);
    cout << "\nvetor a:\n"; mostraVetor(a);
    cout << "\nvetor b:\n"; mostraVetor(b);
    cout << "\nvetor c:\n"; mostraVetor(c);

    return 0;
}
