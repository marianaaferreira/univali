#include <iostream>
#include <cstring>

using namespace std;

int main(){
string frase;
char resp;
do{
   cout<<"Insira uma frase: ";
   getline(cin,frase);

   for (int i=frase.size()-1; i>=0;i--){
       if(frase.at(i)=='a' or frase.at(i)=='A'){
           frase.at(i)='*';
       }
       cout<<frase.at(i);
   }
   do{
   cout<<endl<<"Mais uma frase? S/N:"<<endl;
   cin.get(resp);
   cin.ignore();
   }while(toupper(resp)!='S' and toupper(resp) !='N');
}while(toupper(resp)!='N');



    return 0;
}
