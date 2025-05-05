#include <iostream>
#include <string>
using namespace std;
#define MAX_SENTENCAS 20
#define QTD_CARACTERES 5
#define COLUNA_ERRO 8

bool reconhece_sentenca(int tabela[9][6], bool ef[], string sentenca) {
    char simbolo=' ';
    int estado = 0, coluna, indice_sentenca=0; 

    while (indice_sentenca < sentenca.length()) {
        simbolo = sentenca[indice_sentenca]; indice_sentenca++; 
        simbolo = toupper(simbolo);
        char c = 'A'; int i = 0; coluna = COLUNA_ERRO;
        for (; c <= 'E' and i < QTD_CARACTERES+1; c++, i++)
            if (c == simbolo) coluna = i;
        estado = tabela[estado][coluna];
        //cout << "estado: " << estado << "coluna: " << coluna  << endl; 
    }
    if (ef[estado] == 1) 
        return true;
    return false;
}

int separa_sentencas(string entrada, string sentencas[]) {
    int i = 0, j=0;
    string sentenca="";
    while (i <= entrada.length()) {
        if (entrada[i] != '+' and entrada[i] != '-' and entrada[i] != '*' and entrada[i] != '/' and entrada[i] != ' ') {
            sentenca += entrada[i];
        }
        else{
            if (not sentenca.empty()) { sentencas[j] = sentenca; j++; sentenca = ""; }
            if (entrada[i] == '+' or entrada[i] == '-' or entrada[i] == '*' or entrada[i] == '/') {
                sentencas[j] = entrada[i]; j++;
            }
        }
        i++;
    }
    if (not sentenca.empty()) {
        sentencas[j++] = sentenca;
    }
    return j;
}

int main(){
    int tabela[9][6] = {
        {1,8,2,3,8,8},
        {8,4,8,8,8,8},
        {8,8,5,3,6,8},
        {8,8,8,3,6,8},
        {1,8,2,3,8,8},
        {8,8,2,3,6,8},
        {8,8,8,8,7,8},
        {8,8,8,8,6,8},
        {8,8,8,8,8,8}
    };
    bool ef[] = { 1,0,1,1,1,1,0,1,0 };
    string entrada, sentenca, sentencas[MAX_SENTENCAS];
    int n_sentencas;

    cout << "Digite uma sequencia de caracteres contendo sentenças validas: "; getline(cin, entrada);

    n_sentencas = separa_sentencas(entrada, sentencas);

    for (int i = 0; i < n_sentencas; i++) {
        if (sentencas[i] == "+" or sentencas[i] == "-" or sentencas[i] == "*" or sentencas[i] == "/")
            cout << "operador aritmetico: " << sentencas[i] << endl;
        else if (reconhece_sentenca(tabela, ef, sentencas[i]))
            cout << "sentenca valida: " << sentencas[i] << endl;
        else cout << "ERRO: sentenca invalida: " << sentencas[i] << endl; //separar em diferentes tipos de erros
    }

    //if (reconhece_sentenca(tabela, ef, entrada)) cout << "reconhece"; else cout << "nao reconhece";

}


