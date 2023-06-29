#include <iostream>
#define TAM_MAX 50

using namespace std;

int main(){
        int dado[TAM_MAX], j=0,k=0;
        float porcentagem, media=0;
        for(int i=0; i<TAM_MAX; i++){
            do{
                    cout << "Informe o valor do dado nessa jogada: ";
                    cin >> dado[i];
        }while(dado[i]<0 or dado[i]>6);
            media+= dado[i];
           
        }
        media = media/TAM_MAX;
        for (int i=0; i<TAM_MAX; i++){
            if (dado[i]> media){
                j++; 
            }if (dado[i]==6){
                k++;     
        }   
    }   
    porcentagem = k*100.0/TAM_MAX;
    cout << "Quantidade de lançamentos que o valor é maior que a média: " << j << endl;
    cout << "Ocorrencia da face de seis do dado: " << porcentagem << "%";
    return 0;
}
