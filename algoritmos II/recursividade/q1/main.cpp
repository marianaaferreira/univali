#include <iostream>

using namespace std;
/*
1. A sequ�ncia de Fibonacci � 1, 1, 2, 3, 5, 8, 13, 21, ... Os primeiros dois termos s�o 1 e 1;
cada termo subsequente � calculado como a soma dos dois �ltimos termos. Assim, ti = ti-1 +
ti-2. Elabore uma fun��o recursiva para determinar o valor do en�simo termo da sequ�ncia.
*/

long fibonacci (int n) {
    if (n == 1)
        return 1;
    else
        if (n == 2)
            return 1;
        else
            return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n = 9;
    cout << fibonacci(n);
    return 0;
}
