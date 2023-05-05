#include <iostream>

using namespace std;

int pesquisaRecBinaria(string acervo[], string chave, int inicio, int fim){
    int meio = (inicio + fim) /2;
    if(fim>inicio){
        if(chave==acervo[meio])
            return meio;
        else if (chave>acervo[meio])
            return pesquisaRecBinaria(acervo, chave, meio+1, fim);
        else
            return pesquisaRecBinaria(acervo, chave, inicio, meio-1);
    }
    return -1;
}

int main(){
    string v[4]={"123", "234", "345", "567"};
    int i = 0, f = 3;
    string chave = "345";
    cout << pesquisaRecBinaria(v, chave, i, f);

    return 0;
}
