#include <iostream>
#include <cmath>
#define TMAX 5

using namespace std;
//6. Escreva uma função recursiva que calcule o valor do polinômio pn(x) = anxn + an-1xn-1 + an-2xn2 +...+ a1x + a0

long polinomioRec(int x, int n, int a[]){
    if(n==0)
        return 1;
    return a[n]*pow(x, n) + polinomioRec(x, n-1, a);
}

int main(){
    int a[TMAX] = {1, 2, 3};
    int x = 2; int n = 2;
    cout << polinomioRec(x, n, a) << endl;
    return 0;
}
