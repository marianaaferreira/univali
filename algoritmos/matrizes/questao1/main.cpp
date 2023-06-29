#include <iostream>

using namespace std;

int main(){
    int n, matriz[10][10];
    do{
    cout << "informe a ordem da matriz: " << endl;
    cin >> n;
    }while(n<1 or n>10);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "[" << i+1 << "," << j+1 << "]:";
            cin >> matriz[i][j];
            cout << endl;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }


    return 0;
}
