#include <iostream>

using namespace std;

int main(){
    int alimentacao, bebida, sobremesa;
    float preco1, preco2, preco3, precoFinal;

    cout << "[1] Hamburger R$30,50" << endl;
    cout << "[2] Chessburger R$25,50" << endl;
    cout << "[3] Cachorro Quente R$18,00" << endl;
    cout << "[4] Sanduiche Natural R$20,50" << endl;
    cout << "[5] Refrigerante R$6,50" << endl;
    cout << "[6] Suco de Laranja R$9,50" << endl;
    cout << "[7] Milk shake R$15,50" << endl;
    cout << "[8] Sundae R$20,00" << endl;
    cout << "[9] Casquinha R$15,00" << endl;
    cout << "Digite o codigo correspondente ao seu pedido: " << endl;
    cin >> alimentacao >> bebida >> sobremesa;

    if ((alimentacao > 4) or (bebida < 5) or (bebida > 6 ) or (sobremesa < 7)){
        cout << "Pedido invalido ";
    }else {
        switch (alimentacao){
          case 1: cout << "[1] Hamburger R$30,50" << endl;
                preco1 = 30.50;
                break;
          case 2: cout << "[2] Chessburger R$25,50" << endl;
                preco1 = 25.50;
                break;
          case 3: cout << "[3] Cachorro Quente R$18,00" << endl;
                preco1 = 18.00;
                break;
          case 4: cout << "[4] Sanduiche Natural R$20,50" << endl;
                preco1 =  20.50;
                break;
    } switch (bebida){
        case 5: cout << "[5] Refrigerante R$6,50" << endl;
                preco2 = 6.50;
                break;
        case 6: cout << "[6] Suco de Laranja R$9,50" << endl;
                preco2 = 9.50;
                break;
    } switch (sobremesa){
        case 7: cout << "[7] Milk shake R$15,50" << endl;
                preco3 = 15.50;
                break;
        case 8: cout << "[8] Sundae R$20,00" << endl;
                preco3 = 20.00;
                break;
        case 9: cout << "[9] Casquinha R$15,00" << endl;
                preco3 = 15;
                break;
    }
    precoFinal = preco1 + preco2 + preco3;
    cout << "Valor total a pagar: R$" << precoFinal;
    }

    return 0;
}
