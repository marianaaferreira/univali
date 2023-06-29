#include <iostream>


using namespace std;

int main()
{
    char cod, resposta;
    int id;
    float precokwh, quantkwh, soma, total, media, totalpagar;
    do
    {
        cout << "Informe o numero de identificacao do consumidor: "<<endl;
        cin >> id;
        cin.ignore();
        cout << "Informe a quantidade de kWh consumidos durante o mes: " << endl;
        cin >> quantkwh;
        cin.ignore();
        cout << "Informe o codigo do tipo de consumidor: (R/C/I)" << endl;
        cod = toupper(cin.get());
        switch (cod)
        {
        case 'R':
            cout <<"Informe o preco do kWh residencial: ";
            cin >> precokwh;
            cout << "quantidade total de kwh consumida para unidade residencial:  " << quantkwh << endl;
            break;
        case 'C':
            cout <<"Informe o preco do kWh comercial: ";
            cin >> precokwh;
            cout << "quantidade total de kwh consumida para unidade comercial:  " << quantkwh << endl;
            break;
        case 'I':
            cout <<"Informe o preco do kWh industrial: ";
            cin >> precokwh;
            cout << "quantidade total de kwh consumida para unidade industrial:  " << quantkwh << endl;
            break;
        }

        soma = soma + quantkwh;
        total = total + 1;
        totalpagar = precokwh * quantkwh;
        cout << "numero de identificacao: "<<id<<endl;
        cout << "total a pagar: " << totalpagar <<endl;
        cout << "Mais um consumidor? S/N" <<endl;
        cin.ignore();
        resposta = toupper(cin.get());
    }
    while (resposta != 'N');
    media = soma/total;
    cout << "media geral de consumo: " << media;
    return 0;
}
