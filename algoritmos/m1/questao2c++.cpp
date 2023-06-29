#include <iostream>

using namespace std;

int main(){
    float pesoTerra, pesoPlaneta;
    char codigo;

    cout << "Informe o peso do material: ";
    cin >> pesoTerra;
    cout << "Escolha uma letra correspondente a um planeta:" << endl;
    cout << "[A] Mercurio" << endl << "[B] Venus" << endl << "[C] Marte" << endl << "[D] Jupiter" << endl << "[E] Saturno" << endl << "[F] Urano" << endl;
    cin >> codigo;

    switch (codigo){
    case 'A': pesoPlaneta = pesoTerra*0.37/10;
         break;
    case 'B': pesoPlaneta = pesoTerra*0.88/10;
         break;
    case 'C': pesoPlaneta = pesoTerra*0.38/10;
         break;
    case 'D': pesoPlaneta <- pesoTerra*2.64/10;
         break;
    case 'E': pesoPlaneta = pesoTerra*1.15/10;
         break;
    case 'F': pesoPlaneta = pesoTerra*1.17/10;
         break;
    }
    cout << "O peso no planeta escolhido ? " << pesoPlaneta;

    return 1;
}
