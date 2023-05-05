#include <iostream>

using namespace std;

void ordenacaoRec(int i, int n, int v[]){
    if(n<0)
        return;
    if(v[n-1]>v[i])
        swap(v[n], v[i]);
    ordenacaoRec(i-1, n, v);
    ordenacaoRec(i, n-1, v);
}

int main(){
    int v[5] = {4, 2, 3, 8, 1};
    int n =5;
    int i = n-1;
    ordenacaoRec(i, n, v);
    for(int i=0; i<n; i++){
        cout << "[" << v[i] << "]";
    }

    return 0;
}
