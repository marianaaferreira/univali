#include <iostream>
#include <vector>

using namespace std;
/*P9.1. Escreva uma função double scalar_product(vector<double> a,
vector<double> b) que calcula o produto escalar de dois vetores. */

double produtoEscalar(vector<double>a, vector<double>b){
    double pe=0;
    for(int i=0; i<a.size(); i++){
         pe+=a[i]*b[i];
    }
    return pe;
}

int main(){
    double pe;
    vector<double>a;
    vector<double>b;
    for(int i=0; i<5; i++){
        a.push_back(i+1);
        b.push_back(i+1);
    }
    pe = produtoEscalar(a, b);
    cout << pe;
    return 0;
}
