#include <iostream>
#include <cstring>

using namespace std;
//Faça um algoritmo que leia uma frase e determine qual a vogal mais usada.

int main(){
    string f;
    char va[5]={'a','e','i','o','u'};
    int v[5], temp, tempa;

    cout << "informe a frase" << endl;
    cin >> f;

    for (unsigned int i=0; i<f.size(); i++){
        if (f[i]=='a'){
            v[0]++;
        }else if(f[i]=='e'){
            v[1]++;
        }else if(f[i]=='i'){
            v[2]++;
        }else if(f[i]=='o'){
            v[3]++;
        }else if (f[i]=='u'){
            v[4]++;
        }
    }
    for (int i=0; i<4; i++){
        for (int j=i+1; j<5; j++){
            if (v[i] > v[j]){
                temp= v[i];
                v[i]=v[j];
                v[j]=temp;
                tempa=va[i];
                va[i]=va[j];
                va[j]=tempa;
            }
        }
    }
    cout << "a vogal mais usada e " << va[0];

    return 0;
}
