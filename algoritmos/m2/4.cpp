#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char resp, vencedor;
    int d = 0, e = 0, fimjogo;

    do{
        cout<< "Informe o lado que recebe ponto: "<<endl;
        resp = toupper(cin.get());
        cin.ignore();

        if (resp == 'D'){
            d = d + 1;
        }else if (resp == 'E'){
            e = e + 1;
        }
        if ((d>=21) and (d>e+2)){
            vencedor = 'D';
            fimjogo = 1;
        }else if ((e>=21) and (e>d+2)){
            vencedor = 'E';
            fimjogo = 1;
        }
}while(fimjogo !=1);
  cout << "vencedor: " << vencedor;
}
