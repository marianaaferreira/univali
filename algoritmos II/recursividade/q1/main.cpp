#include <iostream>

using namespace std;
/*
1. A sequência de Fibonacci é 1, 1, 2, 3, 5, 8, 13, 21, ... Os primeiros dois termos são 1 e 1;
cada termo subsequente é calculado como a soma dos dois últimos termos. Assim, ti = ti-1 +
ti-2. Elabore uma função recursiva para determinar o valor do enésimo termo da sequência.
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
