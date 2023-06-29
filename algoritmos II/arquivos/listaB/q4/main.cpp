#include <iostream>
#include <fstream>

using namespace std;
/*4. Faça um algoritmo que leia um arquivo de acesso seqüencial onde cada linha tem no máximo 80 caracteres e
formate este arquivo de modo que cada linha seja centralizada.*/

int main(){
    string str;
    int tam;
    rename("texto.txt", "texto.bak");
    ifstream arq("texto.bak");
    ofstream arq2("texto.txt");
    while(getline(arq, str)){
        tam = (80-str.size())/2;
        for(int i=0; i<tam; i++){
            arq2 << " ";
        }
        arq2 << str << endl;
    }
    arq.close();
    arq2.close();
    return 0;
}
