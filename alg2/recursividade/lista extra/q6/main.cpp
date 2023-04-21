#include <iostream>
#define TMAX 5

using namespace std;
/*6. Dado um vetor de inteiros e o seu n�mero de elementos, inverta a posi��o dos seus elementos.
Caso base? Tamanho do vetor menor ou igual a 1
Passo da recurs�o: troca 1o. e �ltimo elementos e inverte resto do vetor. */

void inverteVetorRec(int n, int i, int v[]){
    if(n<=0)
        return;
    if (i==n or i==n+1)
        return;
    swap(v[n-1], v[i]);
    inverteVetorRec(n-1, i+1, v);

}

int main(){
    int n = 5, i = 0;
    int v[TMAX] = {1, 2, 3, 4, 5};
    inverteVetorRec(n, i, v);
    for (int i=0; i<n; i++){
        cout << "[" << v[i] << "]";
    }
    return 0;
}
