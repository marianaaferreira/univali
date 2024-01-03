#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED

using namespace std;

bool validaNumeroIntPositivo(string num){
    if (num != ""){
        for(int i=0; i<num.size(); i++)
            if(not isdigit(num[i]))
                return false;
    }
    else
        return false;
    return true;
}

#endif // VALIDACOES_H_INCLUDED
