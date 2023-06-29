#include <iostream>
#include <fstream>

using namespace std;
/*6. Considere um arquivo de acesso direto com código (inteiro), nome (string) e quantidade (inteiro) de uma
série de produtos. Elabore um algoritmo que i) crie e preencha uma estrutura em memória para
armazenar estes dados; ii) a partir de um arquivo de acesso sequencial contendo código (inteiro),
operação (caracter) – onde operação pode ser C (compra) ou V (venda) – e quantidade (inteiro), atualize
os dados dos produtos na lista; iii) atualize o arquivo de acesso direto com as informações da lista e iv)
finalize o processo.
*/

typedef struct Nodo{
    int cod, qtd;
    string nome;
    Nodo *proximo;
}Tipolista;

typedef struct{
    int cod, qtd;
    string nome;
}Registro;

void inserenoinicio(Tipolista **ptr_lista, int cod, int qtd, string nome){
    Tipolista *p;
    p = new Tipolista; // aloca memoria p/ novo nodo
    if(p==NULL){
        cout << "Sem memoria";
        cin.get(); exit(1);
    }
    p->cod = cod;
    p->qtd = qtd;
    p->nome = nome;
    p->proximo = *ptr_lista;
    *ptr_lista = p; // conecta o novo nodo ao inicio da lista
}



int main(){
    Tipolista *lista;
    string linha;
    for (iint i=0; i<5; i++){
        cout << "cod: "; cin >> cod;
        cout << "nome: "; getline(cin, nome);
        cout << "qtd: "; cin >> qtd;
        inserenoinicio(&lista, cod, qtd, nome);
    }
    ifstream arqMvmento("mvmento.txt");
    while(getline(arqMvmento, linha)){
        if(cont==1)
            cod=linha;
        else if(cont==2)
            operacao=linha;
        else {
            qtd==linha;
            cont=0;
        }
        atualizalista(&lista, cod, operacao, qtd);
        cont++;
    }

    return 0;
}
