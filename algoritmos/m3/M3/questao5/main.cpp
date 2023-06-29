#include <iostream>
#define TMAX 10

using namespace std;

int main(){
    int b[TMAX], x, p;
    for (int i=0; i<TMAX-1; i++){
        cout << "Informe um valor para b: " << endl;
        cin >> b[i];
    }
    cout << "Informe um valor para x: " << endl;
    cin >> x;
    do{
     cout << "Informe uma valor para posição p: (0 a 8) " << endl;
     cin >> p;
    }while(p<0 or p>8);

    for (int i=8; i>TMAX-p-1; i--){
        b[i+1]= b[i];
    }
    b[p]=x;
    for (int i=0; i<TMAX; i++){
        cout << b[i] << " ";
    }


    return 0;
}
