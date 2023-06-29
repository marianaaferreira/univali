#include <iostream>
#define TMAX 10

using namespace std;
//3. Elabore um algoritmo que inicialize de forma otimizada a matriz AnXn (1 ≤ n ≤ 10) desta forma:
//Ou seja, valores acima da diagonal serão 2, abaixo da diagonal serão 0, da diagonal
//serão 1, com exceção das pontas (que serão 10 e 20).
//Não faça declaração com inicialização direta. Utilize laços.

int main(){
    int matriz[TMAX][TMAX]={0}, n;
    do{
        cout << "Informe a ordem da matriz: " << endl;
        cin >> n;
    }while (n<1 or n>10);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((i==0) and (j==0)){
                matriz[i][j]=10;
            }else if (i==n-1 and j==n-1){
                matriz[i][j]=20;
            }else if (i==j){
                matriz[i][j]=1;
            }else if (i<j){
                matriz [i][j]= 2;
            }else
                matriz[i][j] =0;

        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
