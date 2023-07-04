#include <iostream>
#define TMAX1 10
#define TMAX2 20

using namespace std;

int main(){
    int r[TMAX1], s[TMAX2], x[TMAX1], cont=0;
    bool encontrou;

    for (int i=0; i<TMAX1; i++){
        cout << "Informe um valor para r: " << endl;
        cin >> r[i];
    }
    for (int i=0; i<TMAX2; i++){
        cout << "Informe um valor para s: " << endl;
        cin >> s[i];
    }
    for (int i=0; i<TMAX1; i++){
        for(int j=0; j<TMAX2; j++){
            encontrou = false;
            for (int k=0; k<cont; k++){
                if (r[i]==x[k] or s[j]==x[k]){
                    encontrou = true;
                }
            }
            if ((r[i]==s[j]) and (encontrou == false) ){
                x[cont]=r[i];
                cont++;
            }

        }
    }
    for (int i=0; i<cont; i++){
        cout << x[i] << " ";
    }

    return 0;
}
