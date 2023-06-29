#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int cont=1, posicao=1;
    float soma = 0;

    do{
        if (posicao%2 == 0){
            soma = soma + 1/pow(cont,3);
        } else {
            soma = soma - 1/pow(cont,3);
        }
        cont = cont + 2;
        posicao = posicao + 1;

    }while ((1 / pow(cont-1, cont-1)) - (1 / pow(cont, cont)) > 0.001);
    cout << "soma: " << soma;
    return 0;
}
