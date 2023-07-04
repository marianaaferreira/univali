#include <iostream>
#define TMAX 50
using namespace std;

int main(){
    int v[TMAX];
    for (int i=0; i<TMAX; i++){
        v[i] = (i+5*i)%(i+1);
        cout << v[i] << " ";
    }

    return 0;
}
