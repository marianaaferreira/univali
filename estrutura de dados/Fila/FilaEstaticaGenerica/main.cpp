#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main(){
    FilaEstaticaGenerica<int, 100> filaCinema;
    int n, pessoas;

    srand(time(NULL));
    cria(filaCinema);

    for(int i=0; i<13; i++)
        insere(filaCinema, 1);
    pessoas = 12;

    for(int i=0; i<=45*60; i++){
        if(i%60==0){
            n = rand()%3+2;
            pessoas+=n;
            for(int j=0; j<n; j++)
                insere(filaCinema, 1);
        }
        if(i%30==0)
            if(not ehVazia(filaCinema))
                retira(filaCinema);
    }

    cout << "pessoas que vieram assistir o filme: " << pessoas << endl;
    cout << "quantidade de pessoas na fila qnd o filme comecou: " << numeroDeElementos(filaCinema);

    return 0;
}
