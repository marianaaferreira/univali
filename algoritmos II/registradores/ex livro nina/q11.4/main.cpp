#include <iostream>

using namespace std;

typedef struct{
    int numerador, denominador;
}Fracao;

void leiaFracao(Fracao&p){
    cout << "numerador:\n";
    cin >> p.numerador;
    cout << "denominador:\n";
    cin >> p.denominador;
}

void somaFracao(Fracao f1, Fracao f2, Fracao&r){
    if(f1.denominador==f2.denominador)
        r.denominador = f1.denominador;
    else
        r.denominador = f1.denominador*f2.denominador;

    r.numerador = (f1.denominador/r.denominador)*f1.numerador + (f2.denominador/r.denominador)*f2.numerador;
}

Fracao somaFracao1(Fracao f1, Fracao f2){
    Fracao soma;
    if(f1.denominador==f2.denominador)
        soma.denominador = f1.denominador;
    else
        soma.denominador = f1.denominador*f2.denominador;

    soma.numerador = (f1.denominador/soma.denominador)*f1.numerador + (f2.denominador/soma.denominador)*f2.numerador;

    soma.numerador = (f1.denominador/soma.denominador)*f1.numerador + (f2.denominador/soma.denominador)*f2.numerador;
    return soma;
}

void subtraiFracao(Fracao f1, Fracao f2, Fracao&r){
    if(f1.denominador==f2.denominador)
        r.denominador = f1.denominador;
    else
        r.denominador = f1.denominador*f2.denominador;

    r.numerador = (f1.denominador/r.denominador)*f1.numerador - (f2.denominador/r.denominador)*f2.numerador;
}

void mutiplicaFracao(Fracao p1, Fracao p2, Fracao&r){
    r.numerador = p1.numerador*p2.numerador;
    r.denominador = p1.denominador*p2.denominador;
}

void divideFracao(Fracao p1, Fracao p2, Fracao&r){
    r.numerador = p1.numerador*p2.denominador;
    r.denominador = p1.denominador*p2.numerador;
}

int main(){
    Fracao f1, f2, soma, sub, mut, div;
    leiaFracao(f1);
    leiaFracao(f2);
    somaFracao(f1, f2, soma);
    subtraiFracao(f1, f2, sub);
    mutiplicaFracao(f1, f2, mut);
    divideFracao(f1, f2, div);
    //Fracao soma1 = somaFracao1(f1, f2);
    //cout << soma1.denominador << soma1.numerador;

    cout << "soma: " << soma.numerador << "/" << soma.denominador << endl;
    cout << "subtracao: " << sub.numerador << "/" << sub.denominador << endl;
    cout << "mutiplicacao: " << mut.numerador << "/" << mut.denominador << endl;
    cout << "divisao: " << div.numerador << "/" << div.denominador << endl;

    return 0;
}
