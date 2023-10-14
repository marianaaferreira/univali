#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main(){
    FilaEstaticaGenerica<int, 100> filaTaxi;
    FilaEstaticaGenerica<int, 100> filaPassageiro;
    float tempoEspera=0; int nTaxi=0, nPassageiro=0, n;

    srand(time(NULL));

    for(int i=1; i<=10*60; i++){
        if(i%5==0){
            n = rand()%4;
            for(int j=0; j<n; j++){
                insere(filaTaxi, 1);
            }
        }
        if(i%3==0){
            n = rand()%3;
            for(int j=0; j<n; j++)
                insere(filaPassageiro, i);
        }
        if(not ehVazia(filaTaxi) and not ehVazia(filaPassageiro)){
            tempoEspera+= i-umElemento(filaPassageiro, 1);
            retira(filaTaxi); nTaxi++;
            retira(filaPassageiro); nPassageiro++;
        }
    }

    cout << "Numero de taxis que fizeram o transporte de passageiros: " << nTaxi << endl;
    cout << "Tempo medio de espera dos passageiros: " << tempoEspera/nPassageiro;


    return 0;
}
