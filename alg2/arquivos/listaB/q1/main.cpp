#include <iostream>

using namespace std;
/*1. Admita a existência de um arquivo de acesso sequencial de nome TEXTO.DOC contendo um texto qualquer.
Escreva um algoritmo que modifique TEXTO.DOC de forma que todas as ocorrências de uma determinada
palavra sejam substituídas por outra palavra.
Exemplificando, substituir todas as ocorrências da palavra FILE pela palavra ARQUIVO. O algoritmo deve
preservar a versão antiga de TEXTO.DOC em um arquivo TEXTO.BAK.
*/

int main(){
    string palavra = "", sub="cafe", substitui="pao";
    char ch;
    rename("TEXTOB.txt", "TEXTOB.bak");
    ifstream arq("TEXTOB.bak");
    ofstream arq2("TEXTOB.txt");

    while(arq.get(ch)){
        if(ch!=' ' or ch =='\n'){
            if (palavra==sub) arq2 << substitui << ch;
            else arq2 << palavra << ch;
            palavra = "";
        }else
            palavra += ch;
    }
    arq.close()

    return 0;
}
