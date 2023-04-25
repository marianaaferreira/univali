#include <iostream>
#define TMAX 20

using namespace std;
/*5. Fa�a um algoritmo que leia n c�digos de profiss�o e o respectivo nome da profiss�o.
Em seguida, leia um n�mero indeterminado de c�digos e informe, para cada c�digo
lido, o nome da profiss�o correspondente. Elabore uma subrotina para informar o
nome da profiss�o.*/

typedef struct{
  string nomePro;
  int cod, n;
}pro;

int leiaNLimSup(int lsup){
    int n;
    do{
        cout << "Qtd desejada: ";
        cin >> n;
    }while(n<=0 or n>lsup);
    return n;
}

void leiaCodPro(int n, pro profissoes[]){
    cin.ignore();
    for (int i=0; i<n; i++){
        cout << "Informe o codigo e a profissao correspondente: " << endl;
        cin >> profissoes[i].cod;
        cin.ignore();
        getline(cin, profissoes[i].nomePro);
    }
}

void leiaCod(int n, pro profissoes[]){
    int cod;
    cout << "codigo: ";
    cin >> cod;
    for (int i=0;i<n;i++){
        if (profissoes[i].cod==cod)
            cout << "profissao: " << profissoes[i].nomePro << endl;
    }
}

int main(){
    pro profissoes[TMAX];
    int n = leiaNLimSup(TMAX);
    bool continuar=1;
    leiaCodPro(n, profissoes);
    cout << "Digite o codigo que deseja saber a profissao" << endl;
    do{
        leiaCod(n, profissoes);
        cin.ignore();
        cout << "Deseja continuar sim[1] nao[0]" << endl;
        cin >> continuar;
    }while(continuar);
    return 0;
}
