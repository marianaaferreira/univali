#include <iostream>
#include <fstream>

using namespace std;
/*2. Escreva um programa que leia um programa fonte C++ e verifique se o n�mero de chaves esquerdas e
direitas s�o iguais. O arquivo de entrada deve ser informado pelo usu�rio.
*/

int main(){
    string nomearq;
    char ch;
    int cont=0;

    cout << "Nome do aquivo:\n"; getline(cin, nomearq);
    ifstream fin(nomearq);
    while(fin.get(ch)){
        if(ch=='{')
            cont++;
        else if (ch=='}')
            cont--;
    }
    fin.close();
    if(cont==0)
        cout << "Numero de chaves esquerdas e direitas iguais";
    else
        cout << "Numero de chaves esquerdas e direitas diferentes";

    return 0;
}
