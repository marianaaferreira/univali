#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int informaQtdString(string substring){
    ifstream arq("PALAVRAS.txt");
    char ch; string palavra, linha;
    int tam, qtd=0;
    tam = substring.size();
    getline(arq, linha);
    palavra = linha.substr(0, tam);
    while(arq.get(ch)){
        if(palavra==substring)
            qtd++;
        for(int i=0; i<tam-1;i++)
            palavra[i]=palavra[i+1];
        palavra[tam-1]=ch;
    }
    return qtd;
}

int main(){
    string substring="teste";
    cout << "qtd: " << informaQtdString(substring);
    return 0;
}
