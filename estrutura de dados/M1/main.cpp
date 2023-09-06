#include <iostream>
#include <fstream>
#include <iomanip>
#include "ListaDuplamenteEncadeada.h"

using namespace std;

int main(){
    ListaDuplamenteEncadeada<string> numVoo;
    ListaDuplamenteEncadeada<string> origem;
    ListaDuplamenteEncadeada<string> destino;
    ListaDuplamenteEncadeada<int> lugDisponivel;
    string linha, num, orig, dest, lugdisp, nome;
    char op, resp; int pos;
    ifstream fin("voos.txt");

    crialista(numVoo);
    crialista(origem);
    crialista(destino);
    crialista(lugDisponivel);

    if(!fin){cout<< "arquivo nao pode ser aberto"; exit(0);}
    while(getline(fin, linha)){
        num = linha.substr(0, 3);
        insere(numVoo, num, qtdElementos(numVoo)+1);

        orig = linha.substr(4, 3);
        insere(origem, orig, qtdElementos(origem)+1);

        dest = linha.substr(8, 3);
        insere(destino, dest, qtdElementos(destino)+1);

        lugdisp = linha.substr(12, 3);
        insere(lugDisponivel, stoi(lugdisp), qtdElementos(lugDisponivel)+1);
    }
    /*
    mostralista(numVoo);
    mostralista(origem);
    mostralista(destino);
    mostralista(lugDisponivel);
    */

    do{
        cout << "Informe  nome do cliente: ";
        getline(cin, nome); cout << endl;
        do{
            cout << "Deseja marcar (+) ou desmarcar (-) a passagem? ";
            cin.get(op); cin.ignore(); cout << endl;
        }while(op!='+' and op!='-');
        cout << "Local de origem: ";
        getline(cin, orig); cout << endl;
        cout << "Local de destino: ";
        getline(cin, dest); cout << endl;

        pos = recuperaPosicao(origem, orig);
        if(pos==recuperaPosicao(destino, dest)){
            if(recuperaElemento(lugDisponivel, pos)==0){
                cout << "** NAO CONFIRMADO ** " << nome << "VOO LOTADO" << endl;
            }else if(op=='+'){
                insere(lugDisponivel, recuperaElemento(lugDisponivel, pos)-1, pos);
                excluiElemento(lugDisponivel, pos+1);
                cout << "** CONFIRMADO ** " << nome << " " << recuperaElemento(numVoo, pos) << endl;
            }else{
                insere(lugDisponivel, recuperaElemento(lugDisponivel, pos)+1, pos);
                excluiElemento(lugDisponivel, pos+1);
                cout << "** CONFIRMADO ** " <<  nome << "VOO DESMARCADO" << endl;
            }
        }else
            cout << "** NAO CONFIRMAADO ** " << nome << " VOO INEXISTENTE" << endl;


        cout << "Deseja cadastrar mais um cliente? S/N\n"; cin.get(resp); resp = toupper(resp);
    }while(resp=='S');

    destroilista(numVoo);
    destroilista(origem);
    destroilista(destino);
    destroilista(lugDisponivel);

    return 0;
}
