#include <iostream>
#include <fstream>

using namespace std;
/*4. Escreva um programa que leia um programa fonte C++ e retire os coment�rios deste programa fonte. O
novo arquivo deve ser gravado com o mesmo nome, por�m com extens�o xxx. O arquivo de entrada
deve ser informado pelo usu�rio.
*/

int main(){
    string nomearq, linha;
    char ch, cha=' ';

    cout << "Nome do aquivo:\n"; getline(cin, nomearq);
    ifstream fin(nomearq + ".txt");
    ofstream fout(nomearq + ".xxx");


    while(getline(fin, linha)){
        while(fin.get(ch)){
            if(cha=='/' and ch=='/')
                break;
            fout << ch;
            cha = ch;
        }
    }
    fin.close();
    fout.close();

    return 0;
}
