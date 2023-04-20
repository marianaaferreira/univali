#include <iostream>

using namespace std;

long somaNaturais(int n){
    if (n==1)
        return 1;
    else
        return n + somaNaturais(n-1);
}

int main(){
    int n = leiaNInt()

    return 0;
}
