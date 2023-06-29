#include <iostream>
#include <fstream>

using namespace std;
/*1. Escreva um programa que numere as linhas de um arquivo. O arquivo de entrada deve ser informado
pelo usuário. O programa deve mostrar cada linha do arquivo de entrada precedida do seu número e um
espaço.
*/

int main(){
    string nomearq, linha;
    int cont=1;

    cout << "Nome do aquivo:\n"; getline(cin, nomearq);
    ifstream fin(nomearq);
    while(getline(fin, linha)){
        cout << cont << " " << linha << endl;
        cont++;
    }
    fin.close();

    return 0;
}
