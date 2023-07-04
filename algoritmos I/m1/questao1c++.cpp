#include <iostream>

using namespace std;

int main(){
    float peso, altura;

    cout << "Informe seu peso e sua altura: " << endl;
    cin >> peso >> altura;

    if ((peso >= 65) and (peso <= 100) and (altura >= 1.70) and (altura <= 1.95)){
        cout << "Aceito";
    }else if (((peso < 65) or (peso > 100)) and ((altura < 1.70) or (altura > 1.95))){
        cout << "Totalmente recusado";
    }else if ((altura < 1.70) or (altura > 1.95)){
        cout << "Recusado por altura";
    }else {
        cout << "Recusado por peso";
    }
    return 0;
}
