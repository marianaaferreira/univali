#include <iostream>
#include <cstring>

using namespace std;
//Considere que uma frase tem no máximo 80 caracteres, cada palavra é separada por um espaço
//em branco e finalizada com ponto final. Faça um algoritmo que leia várias frases e, para cada
//uma imprima as palavras contidas nela e seu número de caracteres. Por exemplo, a partir da
//frase “Vamos resolver exercícios.”, o resultado será:
//“Vamos resolver exercícios.”
//Vamos 5 resolver 8 exercícios 10

int main(){
    string frase;
    int n, cont;
    do{
        cout << "Informe a qtd de frases: " << endl;
        cin >> n;
    }while (n<0);
    for(int j=0; j<n; j++){
        do{
        cout << "Informe a frase: " << endl;
        getline(cin, frase);
        cin.ignore();
        }while(frase.size()>TMAX);

     for (int i=0; i<frase.size(); i++){
        if (frase[i]!= ' ' and frase[i]!= '.'){
            cout << frase[i];
            cont++;
        }else{
            cout << cont;
            cont = 0;
        }
     }
    }
    return 0;
}
