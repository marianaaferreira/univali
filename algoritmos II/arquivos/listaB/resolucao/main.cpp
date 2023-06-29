//RESOLUÇÃO DA LISTA B ARQUIVOS
#include <iostream> // EXERC1
#include <fstream>
using namespace std;
int main(){
    string palavra = "", sub="BANANA", substitui = "UVA";
    char ch;
    rename("TEXTOB.txt", "TEXTOB.bak"); // renomear o arq texto.txt para .bak
    ifstream arq("TEXTOB.bak");
    ofstream arq2("TEXTOB.txt");
    if(arq.fail() or arq2.fail()) {cout<< "saindo..."; exit(0);}
    while(arq.get(ch)){
        if(ch == ' ' or ch == '\n'){
            if(palavra == sub) arq2 << substitui << ch;
            else arq2 << ch;
            palavra = "";
        }
        else palavra = palavra + ch;
    }
    arq.close();
    arq2.close();
    return 0;
}

#include <iostream> // EXERC2
#include <fstream>
using namespace std;
int main(){
    string palavra = "";
    char ch;
    rename("TEXTO2.txt", "TEXTO2.bak"); // renomear
    ifstream arq("TEXTO2.bak");
    ofstream arq2("TEXTO2.txt");
    while(arq.get(ch)){
        if(ch == ' ' or ch == '\n'){
            if(palavra.size() > 2){
                arq2 << palavra; cout << palavra << endl;
            }
            arq2 << ch; // sempre grava o ch achado
            palavra = ""; // sempre q testa uma palavra tem q zerar ela
        }
        else palavra = palavra + ch;
    }
    arq.close();
    arq2.close();
    return 0;
}

#include <iostream> // EXERC3
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int linhamaior, linha = 0, quant=0, quantmaior=0;
    char ch;
    vector<int> numeros;
    ifstream arq("DADOS.txt");
    while(arq.get(ch)){
        if(ch == '\n'){
            linha++;
            if(quant > quantmaior){
                quantmaior = quant;
                linhamaior = linha;
            }
            quant = 0;
        }
        else{
            if(ch >= '0' and ch <= '9') numeros.push_back(ch-48); // guarda o valor numerico 1,2,3...
            quant++;
        }
    }
    cout<<"A maior linha eh a linha "<<linhamaior<<endl;
    cout<<"Numeros encontrados no arquivo: ";
    for(unsigned int i=0; i<numeros.size(); i++) cout << numeros[i] << " ";
    arq.close();
    return 0;
}

#include <iostream> // EXERC4
#include <fstream>
using namespace std;
int main(){
    string linha;
    int br;
    rename("TEXTO80.txt", "TEXTO80.bak"); // renomear
    ifstream arq("TEXTO80.bak");
    ofstream arq2("TEXTO80.txt");
    // checar se deu pra abrir
    while(getline(arq,linha)){
        br=(80-linha.size())/2;
        for(int i=1; i<=br; i++) arq2<<' ';
        arq2<<linha<<endl;
    }
    arq.close();
    arq2.close();
    remove("TEXTO80.bak"); // para deletar o antigo
    return 0;
}

#include <iostream> // EXERC5
#include <fstream>
using namespace std;
int main(){
    string linha, linha2;
    int cont=0;
    ifstream arq("TEXTO80.txt"); // reaproveitando o arquivo
    if(arq.is_open()){
        while(getline(arq,linha)) cont++;
        cout<< cont << endl;
    }
    arq.close();
    if(cont<15){
        arq.open("TEXTO80.txt"); // reabrindo o arq
        if(arq.is_open()){
            for(int i=0; i<cont; i++){
                getline(arq,linha2); cout<<linha2<<endl;
            }
        }
        else cout<<"arquivo com +15 linhas"<<endl;
        arq.close();
    }
    return 0;
}

#include <iostream> // EXERC7
#include <fstream>
#include <cstring>
using namespace std;
typedef struct{
    char nome[51];
    int codigo;
    float custo;
} Produto;
int main(){
    char resp;    string nome;    bool achou;    int n, cod;
    float ncusto, media=0;
    Produto p;
    ofstream ofs;
    ofs.open("PRODUTOS.FIL", ios::out|ios::binary);
    if(ofs.fail()){
        cout << "Arquivo nao pode ser aberto para escrita.\n"; exit(1);
    }
    else { // le/grava informações no arquivo e fecha arquivo
        cout << "Arquivo aberto para escrita.\n";
        do{
            cout << "Qtde de produtos: "; cin >> n;
        }while(n<1);
        for (int i=0; i<n; i++){
            cin.ignore();
            cout << "Leitura de dados de um produto" << endl;
            cout << "Nome...: ";
            getline(cin,nome); strcpy(p.nome,nome.c_str());
            do{
                cout << "Codigo.: "; cin >> p.codigo;
            }while(p.codigo<1 or p.codigo>n);
            cout << "Custo de fabricacao: ";
            cin >> p.custo;
            ofs.write((char*)(&p), sizeof(Produto));
        }
        ofs.close();
    }
    cout << endl << "Atualizacao dos dados do arquivo" << endl;
    fstream fs("PRODUTOS.FIL", ios::in | ios::out | ios::ate | ios::binary);
    if(fs.fail())
        cout << "Arquivo nao pode ser aberto para atualizacao.";
    else{
        do{
            achou=false;
            fs.seekg(0, ios::beg);
            cout << "Codigo.: "; cin >> cod;
            cout << "Novo custo de fabricacao: "; cin >> ncusto;
            cin.ignore();
            for (int i=0; i<n; i++){
                fs.read((char*)&p, sizeof(Produto));
                if(p.codigo==cod){
                    achou=true;
                    p.custo = ncusto;
                    fs.seekp(-sizeof(Produto), ios::cur); //reposic p/gravar
                    fs.write((char*)(&p), sizeof(Produto));
                    cout << "Atualizado custo de " << p.nome << endl;
                }
            }
            if(not achou) cout << "Produto inexistente";
            cout<<endl<<"Outro? S/N";
            resp=toupper(cin.get());
            cin.ignore();
        }while(resp=='S');
        fs.close();
    }
    cout << endl << "Recuperando os dados do arquivo" << endl;
    ifstream ifs("PRODUTOS.FIL", ios::binary);
    if(ifs.fail())
        cout << "Arquivo nao pode ser aberto para leitura.";
    else{
        cout << endl << "Todos os produtos"<< endl;
        for (int i=0; i<n; i++){  // varre arquivo pra somar os custos
            ifs.read((char*)&p, sizeof(Produto));
            cout << p.nome << " "<< p.codigo << " "<< p.custo << endl;
            media += p.custo;
        }
        media = media / n;
        ifs.seekg(0, ios::beg); // volta ao inicio do arquivo
        cout << endl << "Produtos acima da media"<< endl;
        for (int i=0; i<n; i++){
            ifs.read((char*)&p, sizeof(Produto));
            if(p.custo>=media)
                cout << p.nome << " "<< p.codigo << " "<< p.custo << endl;
        }
        ifs.close();
    }
    return 0;
}

