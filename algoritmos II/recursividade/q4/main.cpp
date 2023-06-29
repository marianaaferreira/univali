#include <iostream>

using namespace std;

void escreveSeqRec(int n){
    if(n==1)
        cout << n;
    else{
        escreveSeqRec(n-1);
        if(n%2==0)
            cout << ", " << n* n;
        else
            cout << ", " << n;
 //     escreveSeqRec(n-1);
    }
}

int main(){
    int n = 10;
    escreveSeqRec(n);
    return 0;
}
