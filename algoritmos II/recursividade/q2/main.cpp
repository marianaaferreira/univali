#include <iostream>

using namespace std;

int leiaN() {
    int n;
    cout << "Informe o valor de n: " << endl;
    cin >> n;
    return n;
}

long somaNaturais(int n){
    if (n==1)
        return 1;
    else
        return n + somaNaturais(n-1);
}

int main(){
    int n = leiaNInt();
    cout << somaNaturais(n);

    return 0;
}
