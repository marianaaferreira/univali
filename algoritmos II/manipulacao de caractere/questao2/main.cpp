#include <iostream>
#include <cstring>

using namespace std;
//Dado uma string A e um n�mero n, retorne uma string B que consiste na reprodu��o de A n
//vezes. Por exemplo, se A = �tchau� e n = 2 ent�o B = �tchau tchau�.

int main(){
    string a, b;
    int n;

    do{
        cout << "informe a qtd de repeti�oes" << endl;
        cin >> n;
        cin.ignore();
    }while(n<0);
    cout << "informe a frase/palavra: " << endl;
    getline(cin, a);

    for (int j=0; j<n; j++){
        for (int i=0; i<a.size(); i++){
            b[i] = a[i];
        }
    }
    cout << b;
    return 0;
}
