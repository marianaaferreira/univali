#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAX_SENTENCAS 20
#define QTD_CARACTERES 5
#define COLUNA_ERRO 5

bool reconhece_sentenca(int tabela[10][6], bool ef[], string sentenca) {
    char simbolo=' ';
    int estado = 4, coluna, indice_sentenca=0; 

    while (indice_sentenca < sentenca.length()) {
        simbolo = sentenca[indice_sentenca]; indice_sentenca++; 
        //simbolo = toupper(simbolo);
        char c = 'a'; int i = 0; coluna = COLUNA_ERRO;
        for (; c <= 'e' and i < QTD_CARACTERES+1; c++, i++)
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
    while (i < entrada.length()) {
        if (entrada[i] != '+' and entrada[i] != '-' and entrada[i] != '*' and entrada[i] != '/' and not isspace(entrada[i])) {
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
    int tabela[10][6] = {
        {6,9,5,2,7,9},
        {9,9,5,2,7,9},
        {9,9,9,2,7,9},
        {9,9,9,9,7,9},
        {8,9,1,9,9,9},
        {9,9,1,9,9,9},
        {9,4,9,9,9,9},
        {9,9,9,9,3,9},
        {9,0,9,9,9,9},
        {9,9,9,9,9,9}
    };
    bool ef[] = { 1,1,1,1,0,0,0,0,0,0 };
    string entrada, sentenca, sentencas[MAX_SENTENCAS];
    int n_sentencas;

    cout << "Digite uma sequencia de caracteres contendo sentenças validas: "; getline(cin, entrada);

    n_sentencas = separa_sentencas(entrada, sentencas);

    for (int i = 0; i < n_sentencas; i++) {
        if (sentencas[i] == "+" or sentencas[i] == "-" or sentencas[i] == "*" or sentencas[i] == "/")
            cout << "operador aritmetico: " << sentencas[i] << endl;
        else if (reconhece_sentenca(tabela, ef, sentencas[i]))
            cout << "sentenca valida: " << sentencas[i] << endl;
        else if (sentencas[i][1] != 'a' and  sentencas[i][1] != 'b' and sentencas[i][1] != 'c' and sentencas[i][1] != 'd' and sentencas[i][1] != 'e')
            cout << "ERRO: simbolos invalidos: '" << sentencas[i] << "'" << endl;
        else
            cout << "ERRO: sentenca invalida: '" << sentencas[i] <<"'"<< endl; 
    }

    /*for (int i = 0; i < n_sentencas; i++) {
        cout << sentencas[i] << "  indice: " << i << endl;
    }*/

    //if(reconhece_sentenca(tabela, ef, "abd")) cout << "reconhece"; 

    //if (reconhece_sentenca(tabela, ef, entrada)) cout << "reconhece"; else cout << "nao reconhece";

}


