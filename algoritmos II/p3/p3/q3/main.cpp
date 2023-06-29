#include <iostream>
#include <fstream>

using namespace std;

typedef struct{
    int cod;
    float preco;
}Produto;

void registraDados(){
    Produto p;
    ofstream arq("PRODUTOS.BIN", ios::binary);
    for(int i=0; i<3; i++){
        p.cod=i;
        cout << "produto " << p.cod << endl;
        cout << "preco: ";
        cin >> p.preco;
        arq.write((const char*)(&p), sizeof(Produto));
    }
    arq.close();
}

void atualizaPreco(int codp, float novoPreco){
    Produto p; bool encontrou=false;
    fstream arq("PRODUTOS.BIN", ios::in | ios::out | ios::binary);
    if(arq.fail()){
        cout << "nao foi possivel abrir o arquivo"; exit(0);}
    while(arq.read((char*)(&p), sizeof(Produto))){
        if(p.cod==codp){
            p.preco = novoPreco;
            arq.seekp(-sizeof(Produto), ios::cur);
            arq.write((const char*)(&p), sizeof(Produto));
            encontrou = true;
        }
    }
    arq.close();
    if(not encontrou)
        cout << "produto inexistente";
}

void mostraDados(){
    Produto p;
    ifstream arq("PRODUTOS.BIN", ios::binary);
    if(arq.fail()){
        cout << "nao foi possivel abrir o arq pra leitura"; exit(0);}
    while(arq.read((char*)(&p), sizeof(Produto))){
        cout << p.cod << " " << p.preco << endl;
    }
}

int main(){
    registraDados();
    atualizaPreco(2, 1000);
    mostraDados();
    return 0;
}
