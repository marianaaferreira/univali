#include <iostream>

using namespace std;

int main(){
    float n = 0, maior = 0, menor = 0, na = 0, soma = 0, media = 0;
    int total = 0;
    char resposta;

    do {
        cout << "Informe o valor: " << endl;
        cin >> n;
        cin.ignore();

        if (n > na){
            maior = n;
        }else if (n < na){
            menor = n;
        }
        soma = soma + n;
        total = total + 1;
        na = n;
        cout << "Mais um valor? (S/N) " << endl;
        resposta = toupper(cin.get());

    }while(resposta == 'S');

    media = soma/ total;
    cout << "media: " << media << endl << "maior: " << maior << endl << "menor: " << menor;

    return 0;
}
