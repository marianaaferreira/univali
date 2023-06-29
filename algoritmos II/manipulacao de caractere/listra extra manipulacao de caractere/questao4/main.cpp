#include <iostream>

using namespace std;
//4. Faça um programa recebe uma string A e duas letras L1 e L2, e troque todas as
//ocorrências da letra L1 pela letra L2. Ao final mostre a string A atualizada.


int main(){
    string a;
    char L1, L2;

    cout << "informe a string a: "; getline(cin, a);
    cout << endl << "informe a letra que sera substituida: "; cin.get(L1); cin.ignore();
    cout << endl << "informe a letra substituta: "; cin.get(L2);

    for (int i=0; i<a.size(); i++){
        if (a[i]==L1){
            a[i] = L2;
        }
    }
    cout << a;

    return 0;
}
