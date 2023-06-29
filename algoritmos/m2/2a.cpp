#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float soma = 0;
    int cont = 1;
    do{
        soma = soma + (1 / pow(cont, cont));
        cont = cont + 1;
    } while ((1 / pow(cont-1, cont-1)) - (1 / pow(cont, cont)) > 0.001);
    cout << soma;
    return 1;
}
