#include <iostream>
#include <fstream>
#include <cstring>
#define TMAX 10

using namespace std;
/*8. Faça um algoritmo que leia o nome, sexo, cor dos olhos, altura, peso e data de nascimento de n
pessoas e crie um arquivo de acesso direto chamado CADASTRO. Após, leia o arquivo anterior e gere
outros dois arquivos de acesso direto chamados HOMENS e MULHERES para armazenar os dados das
pessoas do sexo masculino e feminino, respectivamente. O sexo das pessoas não deverá ser
armazenado nos novos arquivos. */

typedef struct{
    char nome[51], corOlhos[11], dataNasc[11], sexo;
    int altura;
    float peso;
}Pessoa;

typedef struct{
    char nome[51], corOlhos[11], dataNasc[11];
    int altura;
    float peso;
}Registro;

void leDadosPessoa(int n, Pessoa p[]){
    ofstream cadastro("cadastro.bin", ios::binary);
    string info;
    for(int i=0; i<n; i++){
        cin.ignore();
        cout << "Nome:\n"; getline(cin, info); strcpy(p[i].nome, info.c_str());
        cout << "Data de nascimento:\n"; getline(cin, info); strcpy(p[i].dataNasc, info.c_str());
        cout << "Cor dos olhos:\n"; getline(cin, info); strcpy(p[i].corOlhos, info.c_str());
        cout << "Sexo:\n"; cin.get(p[i].sexo);
        cin.ignore();
        cout << "Altura em metros:\n"; cin >> p[i].altura;
        cout << "Peso:\n"; cin >> p[i].peso;
        cadastro.write((const char*)(&p[i]), sizeof(Pessoa));
    }
    cadastro.close();
}

int main(){
    Pessoa p[TMAX], pe;
    Registro r;
    int n;

    cout << "Numero de pessoas?\n"; cin>>n;
    leDadosPessoa(n, p);

    ifstream cadastro("cadastro.bin", ios::binary);
    ofstream homens("homens.bin", ios::binary);
    ofstream mulheres("mulheres.bin", ios::binary);
    while(cadastro.read((char*)(&pe), sizeof(Pessoa))){
        if(pe.sexo=='F'){
            strcpy(r.nome,pe.nome); strcpy(r.corOlhos, pe.corOlhos); strcpy(r.dataNasc, pe.dataNasc);
            r.altura = pe.altura; r.peso = pe.peso;
            mulheres.write((const char*)(&r), sizeof(Registro));
        }else{
            strcpy(r.nome, pe.nome); strcpy(r.corOlhos, pe.corOlhos); strcpy(r.dataNasc, pe.dataNasc);
            r.altura = pe.altura; r.peso = pe.peso;
            homens.write((const char*)(&r), sizeof(Registro));
        }
    }
    homens.close();
    mulheres.close();

    ifstream homensin("homens.bin", ios::binary);
    ifstream mulheresin("mulheres.bin", ios::binary);
    while(mulheresin.read((char*)(&r), sizeof(Registro))){
        cout << "conteudo arq bin mulheres" << endl;
        cout << r.nome << " " << r.corOlhos << r.dataNasc << " " << r.altura << " " << r.peso << endl;
    }
    while(homensin.read((char*)(&r), sizeof(Registro))){
        cout << "conteudo arq bin homens" << endl;
        cout << r.nome << " " << r.corOlhos << r.dataNasc << " " << r.altura << " " << r.peso << endl;
    }
    homensin.close();
    mulheresin.close();

    return 0;
}
