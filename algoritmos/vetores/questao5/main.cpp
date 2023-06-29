#include <iostream>
#define TMAX 100

using namespace std;
//Faça um algoritmo que leia n (n ≤ 100) pares de valores, sendo o primeiro valor o número de inscrição
//do atleta e o segundo a altura (em cm) do atleta, e armazene-os em vetores. Apresente ao final o número
//de inscrição e a altura do atleta mais alto, o número de inscrição e a altura do atleta mais baixo e a
//altura média do grupo de atletas.

int main(){
    int insc[100], alt[100], n, tempinsc, tempalt;
    float media;

    do{
        cout << "Informe a qtd de altletas: " << endl;
        cin >> n;
    }while(n<1 or n>100);

    for(int i=0; i<n; i++){
        cout << "informe o numero de inscricao: " << endl;
        cin >> insc[i];
        cout << "Informe a altura(cm): " << endl;
        cin >> alt[i];
    }

    for (int i=0; i<n; i++){
        media += alt[i];
    }
    media = media/n;

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (alt[i]>alt[j]){
                tempalt = alt[i];
                alt[i] = alt[j];
                alt[j] = tempalt;
                tempinsc = insc[i];
                insc[i] = insc[j];
                insc[j] = tempinsc;
            }
        }
    }

    cout << "Atleta mais alto: " << endl << "n de inscricao: " << insc[n-1] << "altura: " << alt[n-1] << endl;
    cout << "Atleta mais baixo: " << endl << "n de inscricao: " << insc[0] << "altura: " << alt[0] << endl;
    cout << "Altura media dos atletas: " << media;

    return 0;
}
