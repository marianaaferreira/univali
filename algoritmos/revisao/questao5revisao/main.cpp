#include <iostream>
#define TMAX 100

using namespace std;
//Faça um algoritmo que leia n (n ≤ 100) pares de valores, sendo o primeiro valor o número de inscrição
//do atleta e o segundo a altura (em cm) do atleta, e armazene-os em vetores. Apresente ao final o número
//de inscrição e a altura do atleta mais alto, o número de inscrição e a altura do atleta mais baixo e a
//altura média do grupo de atletas.

int main(){
    int n, alt[TMAX], insc[TMAX], temp, tempi;
    do{
      cout << "informe a qtd de atletas: " << endl;
      cin >> n;
    }while (n>TMAX or n<0);
    for (int i=0; i<n; i++){
        cout << "informe o numero de incricao: "; cin >> insc[i];
        cout << "informe a altura em cm: "; cin >> alt[i];
    }
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (alt[i] > alt[j]){
                temp = alt[i];
                alt[i] = alt[j];
                alt[j] = temp;
                tempi = insc[i];
                insc[i] = insc[j];
                insc[j] = tempi;
            }
        }
    }

    cout << "atleta mais alto " << endl << "inscricao: " << insc[n-1] << endl << "altura: " << alt[n-1] << endl;
    cout << "atleta mais baixo " << endl << "inscricao: " << insc[0] << endl << "altura: " << alt[0];


    return 0;
}
