#include <iostream>

using namespace std;

int main(){
    int r[5], a[10], pontos, n;
    do{
        cout << "Informe a quantidade de apostas? " << endl;
        cin >> n;
    }while (n<1);

    for (int i=0; i<5; i++){
        do{
            cout << "Informe o" << i+1 << "° numero do gabarito da LOTO: " << endl;
            cin >> r[i];
        }while (r[i]<0);
    }
    for (int k=0; k<n; k++){
        for (int i=0; i<10; i++){
            do{
                cout << "Informe a aposta: " << endl;
                cin >> a[i];
            }while (a[i]<0);
        }
        pontos=0;
        for (int i=0; i<10; i++){
            for (int j=0; j<5; j++){
                if (a[i] == r[j]){
                    pontos++;
                }
            }
        }
        cout << pontos << " pontos" << endl;
    }

    return 0;
}
