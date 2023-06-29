#include <iostream>
#define TMAX 20

using namespace std;
/*5. Faça um algoritmo que leia n códigos de profissão e o respectivo nome da profissão.
Em seguida, leia um número indeterminado de códigos e informe, para cada código
lido, o nome da profissão correspondente. Elabore uma subrotina para informar o
nome da profissão.*/

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
