#include <iostream>
#include "FilaEstaticaGenerica.h"

using namespace std;

bool possuemMesmosElementos(FilaEstaticaGenerica<int, 10> fila1, FilaEstaticaGenerica<int, 10> fila2){
    bool encontrou;
    try{
        for(int i=1; i<=numeroDeElementos(fila1); i++){
            encontrou = false;
            for(int j=1; j<=numeroDeElementos(fila2); j++){
                if(umElemento(fila1, i) == umElemento(fila2, j))
                    encontrou = true;
            }
            if(not encontrou) return false;
        }
        return true;
    }catch(const char* e){
        cerr << e << endl;
    }
}


int main(){
    FilaEstaticaGenerica<int, 10> fila1, fila2;
    try{
        cria(fila1);
        cria(fila2);

        for(int i=0; i<5; i++){
            insere(fila1, i+1);
            insere(fila2, i+2);
        }
        mostra(fila1), mostra(fila2);
        cout << possuemMesmosElementos(fila1, fila2);
    }catch(const char* e){
        cerr << e << endl;
    }

    return 0;
}
