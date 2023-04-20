#include <iostream>
#include <cstring>

using namespace std;
//Dadas duas palavras verificar se uma � permuta��o circular de outra. Para se obter uma
//permuta��o circular dessa palavra transfere-se o primeiro caracter do in�cio para o fim da mesma.
//Para se obter todas as outras permuta��es circulares, repete-se esse mesmo processo para cada
//permuta��o circular obtida at� que o �ltimo caracter da palavra inicial torne-se o primeiro. Assim,
//por exemplo a palavra AROMA tem as seguintes permuta��es circulares:
//ROMAA, OMAAR,
//MAARO, AAROM, AROMA.

int main(){
    string p, pc;
    bool v=false;
    char temp;

    cout << "informe a palavra nao permutada: " << endl;
    getline(cin, p);
    cout << "informe a palavra para verificar se e uma permutacao circular: " << endl;
    getline(cin, pc);

    for (int j=0; j<p.size(); j++){
        temp=p[0];
        for (int i=0; i<p.size(); i++){
            p[i] = p[i+1];
        }
        p[p.size()]=temp;
        if (p == pc){
            cout << "e uma permutacao circular";
            v = true;
        }
    }
    if (v==false){
        cout << "nao e uma permutacao circular";
    }

    return 0;
}
