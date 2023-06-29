#include <iostream>
#define TMAX1 10
#define TMAX2 20

using namespace std;

int main(){
    int x[TMAX1], y[TMAX1], r[TMAX2], contx=0, conty=0;

    for (int i=0; i<TMAX1; i++){
        cout << "Informe um valor para o vetor x: " << endl;
        cin >> x[i];
    }
    for (int i=0; i<TMAX1; i++){
        cout << "Informe um valor para o vetor y: " << endl;
        cin >> y[i];
    }

    for (int i; i<TMAX2; i++){
        if (i%2==0){
            r[i]=x[contx];
            contx++;
        }else{
            r[i]=y[conty];
            conty++;
        }
    }
    for(int i=0; i<TMAX2; i++){
        cout << r[i] << " ";
    }


    return 0;
}
