#include <iostream>
#include <fstream>

using namespace std;
/*3. Escreva um programa que imprima na tela 20 linhas por vez – a cada 20 linhas impressas, o programa
só deverá imprimir as próximas após o usuário pressionar <ENTER>. O arquivo de entrada deve ser
informado pelo usuário. */

int main(){
    string nomearq, linha;
    int cont;

    cout << "Nome do aquivo:\n"; getline(cin, nomearq);
    ifstream fin(nomearq);
    while(!fin.eof()){
        cont = 0;
        while(cont<5){
            getline(fin, linha);
            cout << linha << endl;
            cont++;
        }
        cin.get();
    }
    fin.close();
    return 0;
}
