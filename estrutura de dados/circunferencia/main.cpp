#include <iostream>

using namespace std;

typedef struct{
    int x, y, raio;
}Circunferencia;

void criarCircunferencia(Circunferencia &c, int x, int y, int raio){
    c.x = x;
    c.y = y;
    c.raio = raio;
}

int recuperaRaio(Circunferencia c){
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

string comparaDuasCircunferencias(Circunferencia c1, Circunferencia c2){
    if(c1.raio*2*3.14 == c2.raio*2*3.14)
        return "c1=c2";
    else if(c1.raio*2*3.14 > c2.raio*2*3.14)
        return "c1>c2";
    return "c1<c2";
}

bool verificaCircunferenciaMesmaPosicao(Circunferencia c1, Circunferencia c2){
    if(c1.x==c2.x and c1.y==c2.y)
        return true;
    return false;
}

int main(){
    Circunferencia c[5];
    /*a) representar cinco circunferências, sendo que a penúltima circunferência
    terá as mesmas coordenadas da primeira circunferência e raio 5 unidades
    maior e a última circunferência terá valor de coordenada X com 10 unidades
    a menos que a coordenada Y da terceira circunferência; */
    int x, y, raio;
    bool existe = false;
    //Entrada de dados c1 a c3
    for(int i=0; i<3; i++){
        cout << "\nCircunferencia " << i+1;
        cout << "\nnCoordenada x: "; cin >> x;
        cout << "\nCoordenada y: "; cin >> y;
        cout << "\nRaio: "; cin >> raio; cout << endl;
        criarCircunferencia(c[i], x, y, raio);
    }
    //c4
    x = recuperaCoordenadaX(c[0]);
    y = recuperaCoordenadaY(c[0]);
    raio = recuperaRaio(c[0])+5;
    criarCircunferencia(c[3], x, y, raio);
    cout << "Circunferencia 4 gerada\n";
    cout << "x: " << x << endl << "y: " << y << endl << "raio: " << raio << endl;

    //c5
    cout << "Circunferencia 5\n";
    x = recuperaCoordenadaY(c[2])-10;
    cout << "Coordenada x gerada: " << x << endl;
    cout << "Coordenada y: "; cin >> y; cout << endl;
    cout << "Raio: "; cin >> raio; cout << endl;
    criarCircunferencia(c[4], x, y, raio);

    /*for (int i=0; i<5; i++){
        cout << c[i].x << " " << c[i].y << " " << c[i].raio << endl;
    }*/

    //b) alterar o raio da primeira circunferência para mais 3 unidades;
    raio = recuperaRaio(c[0]);
    alteraRaio(c[0], raio+3);

    //c) exibir o perímetro de todas as circunferências;
    for(int i=0; i<5; i++){
        cout << "Circunferencia " << i+1 << " ";
        cout << "Perimetro: " << calculaPerimetro(c[i]) << endl;
    }
    //d) identificar as circunferências com a mesma posição.
    cout << "Circunferencias com as mesmas posicoes:" << endl;
    for(int i=0; i<4; i++){
        for(int j=i+1; j<5; j++){
            if(verificaCircunferenciaMesmaPosicao(c[i], c[j])){
                cout << i << " e " << j << endl;
                existe = true;
            }
        }
    }
    if (not existe){
        cout << "Todas as circunferencias possuem posicoes diferentes\n";
    }

    return 0;
}
