#include <iostream>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main(){
    FilaEstaticaGenerica<int, 500> taxi, passageiro;
    int nTaxi=0, esperaPassageiro;

    try{
    for(int i=1; i<=10*60; i++){
        if(i%5==0)
            for(int i=0; i<rand()%4; i++)
                insere(taxi, 1);
        if(i%3==0)
            for(int i=0; i<rand()%3; i++)
                insere(passageiro, i);
        if(not ehVazia(taxi) and not ehVazia(passageiro)){
            retira(taxi); nTaxi++;
            esperaPassageiro = esperaPassageiro+(i-primeiro(passageiro));
        }
    }
    }catch(const char* e){
        cerr << e << endl;
    }

    cout << "qtd de taxis utilizados: " << nTaxi << endl;
    cout << "tempo medio de espera dos passageiros: " << float(esperaPassageiro/nTaxi);


    return 0;
}
