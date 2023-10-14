#include <iostream>
#include <time.h>
#include "FilaEstaticaGenerica.h"

using namespace std;

int main(){
    FilaEstaticaGenerica<int, 100> filaA;
    FilaEstaticaGenerica<int, 100> filaB;
    FilaEstaticaGenerica<int, 100> filaC;
    int pA=0, pB=0, pC=0, n;

    cria(filaA); cria(filaB); cria(filaC);

    srand(time(NULL));

    for(int i=1; i<=100; i++){
        n = rand()%101;
        if(n<=49){
            if(n<=25)
                if(temEspaco(filaA)) insere(filaA, 1);
            if(n<=39)
                if(temEspaco(filaB)) insere(filaB, 1);
            else
                if(temEspaco(filaC)) insere(filaC, 1);
        }else{
            if(n<=75)
                if(not ehVazia(filaA)){retira(filaA); pA++;}
            if(n<=89)
                if(not ehVazia(filaB)){retira(filaB); pB++;}
            else
                if(not ehVazia(filaC)){retira(filaC); pC++;}
        }


        if(i%5==0){
            cout << "Classe A" << endl;
            cout << "qtd de processos em espera: " << numeroDeElementos(filaA) << endl;
            cout << "qtd de processos executados: " << pA << endl;
            cout << endl;
            cout << "Classe B" << endl;
            cout << "qtd de processos em espera: " << numeroDeElementos(filaB) << endl;
            cout << "qtd de processos executados: " << pB << endl;
            cout << endl;
            cout << "Classe C" << endl;
            cout << "qtd de processos em espera: " << numeroDeElementos(filaC) << endl;
            cout << "qtd de processos executados: " << pC << endl;
            cout << endl;
        }
    }


    return 0;
}
