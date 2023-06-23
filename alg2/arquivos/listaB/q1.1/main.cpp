#include <iostream>
#include <fstream>

using namespace std;
/*1. Admita a existência de um arquivo de acesso sequencial de nome TEXTO.DOC contendo um texto qualquer.
Escreva um algoritmo que modifique TEXTO.DOC de forma que todas as ocorrências de uma determinada
palavra sejam substituídas por outra palavra.
Exemplificando, substituir todas as ocorrências da palavra FILE pela palavra ARQUIVO. O algoritmo deve
preservar a versão antiga de TEXTO.DOC em um arquivo TEXTO.BAK.*/

int main(){
    string palavra, sub="chapeu", substitui="arquivo";
    char ch;

    rename("texto.txt", "texto.bak");
    ifstream arq("texto.bak");
    ofstream arq2("texto.txt");

    while(arq.get(ch)){
        if(ch==' ' or ch=='\n' or ch==',' or ch=='.'){
            if(palavra==substitui)
                arq2 << sub << ch;
            else
                arq2 << palavra << ch;
        }else
            palavra+=ch;
    }
    arq.close();
    arq2.close();
    return 0;
}
