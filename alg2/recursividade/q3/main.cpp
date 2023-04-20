#include <iostream>

using namespace std;

long somaMutiplos(int m, int x, int n){
    if(n<=x)
        return 0;
//  if (n>x){
    if (n%m==0)
        return n + somaMutiplos(m, x, n-m);
    return somaMutiplos(m, x, n-n%m);
//  }
}


int main(){
    int n = 1000;
    int m = 5;
    int x = 0;
    cout << somaMutiplos(m, x, n);

    return 0;
}
