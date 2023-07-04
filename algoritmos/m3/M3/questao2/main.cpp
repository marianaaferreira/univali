#include <iostream>
#define TMAX 10
using namespace std;

int main(){
    int d[TMAX], temporario[TMAX], cont, i;

    for (int i=0; i<TMAX; i++){
        cout << "Informe um valor: " << endl;
        cin >> d[i];
    }
    for (int i=0; i<TMAX; i++){
        if (d[i]>0){
            temporario[cont]=d[i];
            cont++;
        }
    }
    for (int i=0; i<cont; i++){
       d[i]=temporario[i];
    }
    for (int i=0; i<cont; i++){
        cout << d[i] << " ";
    }

    return 0;
}
