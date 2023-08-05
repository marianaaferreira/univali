#include <iostream>

using namespace std;

typedef struct{
    int x, y, raio;
}Circuferencia;

Circunferencia criarCircunferencia(Circunferencia c, int x, int y, int raio){
    c.x = x;
    c.y = y;
    c.raio = raio;
    return c;
}

int recuperaRaio(Cincunferencia c){
    return c.raio;
}

int recuperaCoordenadaX(Circunferencia c){
    return c.x;
}

int recuperaCoordenadaY(Circunferencia c){
    return c.y;
}

int calculaDiametro(Circunferencia c){
    return c.raio*2;
}

float calculaPerimetro(Circunferencia c){
    return c.raio*2*3.14;
}

void alteraRaio(Circunferencia &c, int raio){
    c.raio = raio;
}

void alteraCoordenadaX(Circunferencia &c, int x){
    c.x = x;
}

void alteraCoordenadaY(Circunferencia &c, int y){
    c.y = y;
}

void comparaDuasCircunferencias(){

}

bool verificaCircunferenciaMesmaPosicao

int main(){
    Cincunferencia c[5];


    return 0;
}
