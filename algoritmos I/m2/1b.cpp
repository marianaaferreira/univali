#include <iostream>

using namespace std;

int main(){
    int n, cont;
     cout << "Informe a quantidade de termos: " << endl;
     cin >> n;

     for (cont = 1; cont <= n; cont++){
        cout << cont << " ";
        cont = cont + 3;
        cout << cont << " " << cont << " ";
     }

    return 0;
}
