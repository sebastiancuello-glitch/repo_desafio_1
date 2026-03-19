#include "tablero.h"
#include <iostream>


using namespace std;

Tablero::Tablero(int ancho, int alto){

    this ->ancho = ancho;
    this ->alto = alto;
    this ->bytesPorFila = ancho/8;
    this -> celdas= nullptr;

}
Tablero :: ~Tablero()
{
    if(celdas != nullptr){
        for(int i= 0; i < alto; i++){
            delete[] celdas[i];
        }
        delete[] celdas;
    }
}

bool Tablero :: dimesionesvalidas() const{

    return(ancho >= 8 && alto >= 8 && ancho % 8 == 0);
}

void Tablero :: inicializar(){

    celdas = new unsigned char*[alto];

    for (int i= 0; i< alto; i++){

        celdas[i] = new unsigned char[bytesPorFila];

        for(int j= 0; j<bytesPorFila; j++){
            celdas[i][j] = 0;
        }
    }

}

void Tablero::imprimir() const{

    for(int i= 0; i< alto; i++){

        for (int j = 0; j < ancho; j++){


            if (estaOcupada(i,j)){

                cout << "#";
            }
            else {
                cout <<".";
            }
        }
        cout << endl;

    }
}

bool Tablero :: dentroDeLimites(int fila, int columna) const{

    return(fila>=0 && fila < alto && columna >= 0 && columna < ancho);
}

bool Tablero :: estaOcupada(int fila, int columna) const{

    if(!dentroDeLimites(fila, columna)){

        return false;
    }

    int indiceByte = columna / 8;
    int indiceBit = 7 -(columna % 8);

    return (celdas[fila][indiceByte] & (1 << indiceBit)) != 0;
}

void Tablero :: encenderCelda(int fila, int columna){

    if(!dentroDeLimites(fila,columna)){

        return;
    }

    int indiceByte = columna / 8;
    int indiceBit = 7- (columna % 8);


    celdas[fila][indiceByte] = celdas[fila][indiceByte] | (1 << indiceBit);
}

void Tablero :: apagarCelda(int fila, int columna){

    if (!dentroDeLimites(fila,columna)){

     return;

    }

    int indiceByte  = columna / 8;
    int indiceBit = 7 - (columna % 8);

    celdas[fila][indiceByte] = celdas[fila][indiceByte] & ~(1 << indiceBit);
}


int Tablero :: NAncho() const{

    return ancho;

}

int Tablero :: NAlto() const {

    return alto;

}

int Tablero:: NBytesPorFila() const {

    return bytesPorFila;
}
