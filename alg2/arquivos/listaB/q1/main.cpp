#include <iostream>

using namespace std;
/*1. Admita a exist�ncia de um arquivo de acesso sequencial de nome TEXTO.DOC contendo um texto qualquer.
Escreva um algoritmo que modifique TEXTO.DOC de forma que todas as ocorr�ncias de uma determinada
palavra sejam substitu�das por outra palavra.
Exemplificando, substituir todas as ocorr�ncias da palavra FILE pela palavra ARQUIVO. O algoritmo deve
preservar a vers�o antiga de TEXTO.DOC em um arquivo TEXTO.BAK.
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
