#include <iostream>
#define TMAX 5
using namespace std;

int main(){
int v [10], maior, posicao=0;

for (int i=0; i<TMAX; i++){
        cout << "Informe um valor: " << endl;
        cin >> v[i];
}
maior = v[posicao];
 for (int i=1; i<TMAX; i++){
    if (v[i]> v[posicao]){
        maior = v[i];
        posicao = i;
    }

 }
    for (int i=0;i<TMAX;i++){
        cout << v[i] << endl;
    }
    cout << "maior elemento: " << maior << endl;
    cout << "posicao do maior elemento: " << posicao;


    return 0;
}
