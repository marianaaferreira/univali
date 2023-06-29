#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, cont;
    cout << "Informe a quantidade de termos: " << endl;
    cin >> n;

    for (cont = 1; cont <= n; cont++){
        cout << pow(cont, 2) << " ";
    }
    return 0;
}
