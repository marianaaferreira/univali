#include <iostream>
#include <time.h>
#include "ListaEstaticaGenerica.h"

using namespace std;

int main(){
    FilaEstaticaGenerica<int, 100> caixa1;
    FilaEstaticaGenerica<int, 100> caixa2;
    FilaEstaticaGenerica<int, 100> caixa3;
    FilaEstaticaGenerica<int, 100> caixa4;
    int menor;

    int qtdProd[4];
    srand(time(NULL));

    cria(clientes);
    for(int i=0; i<4; i++) insere(caixa1, rand()%50+1);
    for(int i=0; i<3; i++) insere(caixa2, rand()%50+1);
    for(int i=0; i<2; i++) insere(caixa3, rand()%50+1);
    for(int i=0; i<4; i++) insere(caixa4, rand()%50+1);

    for(int i=1; i<60*5; i++){
        if(i%4==0) retira(caixa1);
        if(i%5==0) retira(caixa2);
        if(i%7==0) retira(caixa3);
        if(i%2==0) retira(caixa4);

        n = rand()%50+1;

        for(int i=1; i<=numeroDeElementos(caixa1); i++) qtdProd[0]+= umElemento(caixa1, i);
        for(int i=1; i<=numeroDeElementos(caixa2); i++) qtdProd[1]+= umElemento(caixa2, i);
        for(int i=1; i<=numeroDeElementos(caixa3); i++) qtdProd[2]+= umElemento(caixa3, i);
        for(int i=1; i<=numeroDeElementos(caixa4); i++) qtdProd[3]+= umElemento(caixa4, i);



        /*

        if(numeroDeElementos(caixa1)<=numeroDeElementos(caixa2) and numeroDeElementos(caixa1)<=numeroDeElementos(caixa3))
            menor = numeroDeElementos(caixa1);
        else if(numeroDeElementos(caixa2)<=numeroDeElementos(caixa1) and numeroDeElementos(caixa2)<numeroDeElementos(caixa3))
            menor = numeroDeElementos(caixa2);
        else if(numeroDeElementos(caixa3)<=numeroDeElementos(caixa1) and numeroDeElementos(caixa3)<numeroDeElementos(caixa2))
            menor = numeroDeElementos(caixa3);

        if(n<=6 and numeroDeElementos(caixa4)<=menor))
            insere(caixa4, n);
        else if(numeroDeElementos(caixa1)<numeroDeElementos(caixa2) and numeroDeElementos(caixa1)<numeroDeElementos(caixa3))
            insere(caixa1, n);
        else if(numeroDeElementos(caixa2)<numeroDeElementos(caixa1) and numeroDeElementos(caixa2)<numeroDeElementos(caixa3))
            insere(caixa2, n);
        else if(numeroDeElementos(caixa3)<numeroDeElementos(caixa1) and numeroDeElementos(caixa3)<numeroDeElementos(caixa2))
            insere(caixa3, n);
        else if()
    }*/

    return 0;
}
