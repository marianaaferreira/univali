#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "ListaDuplamenteEncadeada.h"

using namespace std;

void menu(ListaDuplamenteEncadeada<string>, ListaDuplamenteEncadeada<string>, ListaDuplamenteEncadeada<string>, ListaDuplamenteEncadeada<int>);
void entradaDadosCliente(string &, char &op, string &, string &, ListaDuplamenteEncadeada<string>, ListaDuplamenteEncadeada<string>);

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

    //insere dados do arquivo na lista encadeada
    if(!fin){cout<< "arquivo nao pode ser aberto"; exit(0);}
    while(getline(fin, linha)){
        num = linha.substr(0, 3);
        insere(numVoo, num, qtdElementos(numVoo)+1);

        orig = linha.substr(4, 3);
        if(orig[2]==' ') orig = orig.substr(0,2);
        insere(origem, orig, qtdElementos(origem)+1);

        dest = linha.substr(8, 3);
        if(dest[2]==' ') dest = dest.substr(0,2);
        insere(destino, dest, qtdElementos(destino)+1);

        lugdisp = linha.substr(12, 3);
        insere(lugDisponivel, stoi(lugdisp), qtdElementos(lugDisponivel)+1);
    }

    do{
        menu(numVoo, origem, destino, lugDisponivel);
        cout << endl << "Reserva de voos" << endl;
        entradaDadosCliente(nome, op, orig, dest, origem, destino);

        pos = recuperaPosicao(origem, orig);
        if(pos==recuperaPosicao(destino, dest)){
            if(recuperaElemento(lugDisponivel, pos)==0){
                cout << "** NAO CONFIRMADO ** " << nome << " VOO LOTADO" << endl;
            }else if(op=='+'){
                insere(lugDisponivel, recuperaElemento(lugDisponivel, pos)-1, pos);
                excluiElemento(lugDisponivel, pos+1);
                cout << "** CONFIRMADO ** " << nome << " " << recuperaElemento(numVoo, pos) << endl;
            }else{
                insere(lugDisponivel, recuperaElemento(lugDisponivel, pos)+1, pos);
                excluiElemento(lugDisponivel, pos+1);
                cout << "** CONFIRMADO ** " <<  nome << " VOO DESMARCADO" << endl;
            }
        }else
            cout << "** NAO CONFIRMAADO ** " << nome << " VOO INEXISTENTE" << endl;

        cout << "Deseja cadastrar mais um cliente? S/N\n"; cin.get(resp); resp = toupper(resp); cin.ignore();
    }while(resp=='S');

    destroilista(numVoo);
    destroilista(origem);
    destroilista(destino);
    destroilista(lugDisponivel);

    return 0;
}

void menu(ListaDuplamenteEncadeada<string> numVoo, ListaDuplamenteEncadeada<string> origem, ListaDuplamenteEncadeada<string> destino, ListaDuplamenteEncadeada<int> lugDisponivel){
    cout << "Numero do voo - lugar de origem - lugar de destino -  assentos disponiveis" << endl;
    for(int i=1; i<=qtdElementos(numVoo); i++){
        cout << "      " << recuperaElemento(numVoo, i) << "             " << recuperaElemento(origem, i) << "               ";
        cout << recuperaElemento(destino, i) << "                  " << recuperaElemento(lugDisponivel, i) << endl;
    }
}

void entradaDadosCliente(string &nome, char &op, string &orig, string &dest, ListaDuplamenteEncadeada<string>origem, ListaDuplamenteEncadeada<string>destino){
    cout << "Informe  nome do cliente: ";
    getline(cin, nome); cout << endl;
    do{
        cout << "Deseja marcar (+) ou desmarcar (-) a passagem? ";
        cin.get(op); cin.ignore(); cout << endl;
    }while(op!='+' and op!='-');
    do{
        cout << "Local de origem: ";
        getline(cin, orig); cout << endl;
    }while(not elementoEstaNaLista(origem, orig));
    do{
        cout << "Local de destino: ";
        getline(cin, dest); cout << endl;
    }while(not elementoEstaNaLista(destino, dest));
}
