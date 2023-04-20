#include <iostream>
#include <cstring>

using namespace std;
//Uma palavra palíndrome é uma cadeia de caracteres cuja leitura tem o mesmo sentido se feita da
//direita para a esquerda ou vice-versa. Por exemplo, OSSO, OVO, RADAR, ... Ler n cadeias de
//caracteres e determinar quais delas são palíndromes.

int main(){
    string p, pa;
    int n;
    char temp;

    do{
        cout << "informe a qtd de cadeia de caracteres" << endl;
        cin >> n;
        cin.ignore();
    }while(n<0);
    cout << "informe a frase/palavra: " << endl;
    getline(cin, p);

    for (unsigned int i=0; i<p.size()/2; i++){
       temp= p[i];
       pa[i]= p[p.size()-i];
       pa[p.size()-i]=temp;
    }
    if (pa == p){
        cout << "e uma palavra palíndrome ";
    }else {
        cout << "nao e uma palavra palíndrome ";
    }

    return 0;
}
