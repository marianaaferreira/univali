#include <iostream>

using namespace std;

int calculaMDC(int m, int n){
    if(n==0)
        return m;
    if(n>m)
        return calculaMDC(n, m);
    return calculaMDC(n, m%n);
}

int main(){
    int m = 135;
    int n = 35;
    cout << calculaMDC(m, n);
    return 0;
}
