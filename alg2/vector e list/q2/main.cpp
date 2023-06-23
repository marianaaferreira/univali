#include <iostream>
#include <vector>

using namespace std;
//P9.2. Escreva uma função que calcule a soma alternada de todos os elementos em um vetor.
//P.ex. vetor 1,4,9,16,9,7,4,9,11 calcula 1 - 4 + 9 - 16 + 9 - 7 + 4 - 9 + 11 = -2

float somaAlternada(vector<float>v){
    float soma=0;
    for(int i=0;i<v.size(); i++){
        if(i%2==0)
            soma+=v[i];
        else
            soma-=v[i];
    }
    return soma;
}

int main(){
    vector<float>v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(9);
    v.push_back(16);
    v.push_back(9);
    v.push_back(7);
    v.push_back(4);
    v.push_back(9);
    v.push_back(11);
    cout << somaAlternada(v);

    return 0;
}
