#include <iostream>

using namespace std;

int main(){
    string matricula;
    char conceito;
    float p1, p2, p3, me, mediaFinal;

    cout << "Informe sua matricula: " << endl;
    cin >> matricula;
    cout << "Informe suas notas e sua media dos exercicios: " << endl;
    cin >> p1 >> p2 >> p3 >> me;

    mediaFinal = (p1 + p2 * 2 + p3 * 3 + me)/7;

    if (mediaFinal >= 9){
        conceito = 'A';
    }
    else if ((mediaFinal >= 7.5) and (mediaFinal < 9)){
        conceito = 'B';
    }
    else if ((mediaFinal >= 6) and (mediaFinal < 7.5)){
        conceito = 'C';
    }
    else if ((mediaFinal >=4) and (mediaFinal < 6)){
        conceito = 'D';
    }
    else {conceito = 'E';
    }

    cout << "Matricula: " << matricula << endl;
    cout << "Media final: " << mediaFinal << endl;
    cout << "conceito: " << conceito << endl;

    switch (conceito){
    case 'A':
    case 'B':
    case'C':
        cout << "Aprovado";
        break;
    case 'D':
    case 'E':
    case 'F':
        cout << "Reprovado";
        break;
    }
    return 0;
}
