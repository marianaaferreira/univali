#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef struct{
    int cod, qtd;
    char nome[51];
}Produto;

int main(){
    Produto p;
    string linha, info, operacao;
    int cont=1, cod, qtd, n;
    ofstream arqbinout("produtos.bin", ios::binary);
    for (int i=0; i<3; i++){
        cout << "cod: "; cin >> p.cod;
        cin.ignore();
        cout << "nome: "; getline(cin, info); strcpy(p.nome, info.c_str());
        cout << "qtd: "; cin >> p.qtd;
        arqbinout.write((const char*)(&p), sizeof(Produto));
    }
    arqbinout.close();
    fstream arqbin("produtos.bin", ios::in | ios::out | ios::binary);
    ifstream arq("mvmento.txt");
    if(arqbin.fail()){
        cout << "\nproblema com o produtos.bin\n"; exit(0);}
    if(arq.fail()){
        cout << "\nproblema com o mvmento.txt\n"; exit(0);}
    cout << "\nIniciando atualizacao de produtos\n";
    while(getline(arq, linha)){
        if(cont==1)
            cod=stoi(linha);
        else if(cont==2)
            operacao=linha;
        else {
            qtd=stoi(linha);
            cont=0;
            arqbin.seekg(0, ios::end);
            n = arqbin.tellg()/sizeof(Produto);
            arqbin.seekg(0, ios::beg);

            for(int i=0; i<n; i++){
                arqbin.read((char*)(&p), sizeof(Produto));
                if(operacao=="C")
                    p.qtd+=qtd;
                else
                    p.qtd-=qtd;
            arqbin.seekp(-sizeof(Produto), ios::cur);
            cout << "atualizando produto " << p.cod << " no arq bin\n";
            arqbin.write((const char*)(&p), sizeof(Produto));
        }
        cont++;
    }
    }
    cout << "\nconteudo final do arq bin\n";
    for(int i=0; i<n; i++){
        arqbin.read((char*)(&p), sizeof(Produto));
        cout << p.cod << " " << p.nome << " " << p.qtd << endl;
    }
    arqbin.close();
    arq.close();

    return 0;
}
