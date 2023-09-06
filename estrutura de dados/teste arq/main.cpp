#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string linha, numVoo, origem, destino, lugDisponivel;
    ifstream fin("voos.txt");

    if(!fin){cout<< "arquivo nao pode ser aberto"; exit(0);}
    while(getline(fin, linha)){
        numVoo = linha.substr(0, 3);
        origem = linha.substr(4, 3);
        destino = linha.substr(8, 3);
        lugDisponivel = linha.substr(12, 3);
        cout << numVoo << " " << origem << " " << destino << " " << lugDisponivel << endl;
    }

    return 0;
}
