#include <iostream>
using namespace std;
/*
1.Um número é dito ser regular caso sua decomposição em fatores primos apresenta apenas potências de 2, 3 e 5.

Faça uma função que verifique se um número é (retorne 1) ou não (retorne 0) regular. Crie também um programa

para testar tal função.
*/
int main();
int leiaN();
bool decomposicao(int n);

int main(){
    int n = leiaN();
    if (decomposicao(n)==1){
        cout << "e um numero regular";
    }else
        cout << "nao e um numero regular";
    return 0;
}

int leiaN(){
    int n;
    cout << "informe o valor para verificar se e regular  " << endl;
    cin >> n;
    return n;
}

bool decomposicao(int n){
int i=0;
int primo[3]={2,3,5};
    do{
        if (primo[i]>n){
            return 0;
        }else if(n%primo[i]==0){
            n = n/primo[i];
        }else{
            i++;
        }
        if(n/primo[i]==1){
            return 1;
        }
    }while(n/primo[i]!=1);
}
