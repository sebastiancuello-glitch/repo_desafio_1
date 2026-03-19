#include "pieza.h"
#include <iostream>

using namespace std;

Pieza::Pieza() {

    forma[0] = 4; //0100
    forma[1] = 14; // 1110
    forma[2] = 0; // 0000
    forma[3] = 0; // 0000

    fila = 0;
    columna = 0;
}

bool Pieza :: tieneBloque(int filaLocal, int columnaLocal) const{


    if (filaLocal < 0 || filaLocal >= 4 || columnaLocal < 0 || columnaLocal >= 4){

        return false;
    }

    int mascara = 1 << (3 - columnaLocal);
    return(forma[filaLocal] & mascara) != 0;

}

int Pieza::NFila () const{

    return fila;
}

int Pieza :: NColumna () const {

    return columna;
}


void Pieza::setFila(int fila){

    this -> fila = fila;

}

void Pieza::setColumna (int columna){

    this -> columna = columna;

}

void Pieza::setPosicion(int fila, int columna){

    this -> fila = fila;
    this -> columna = columna;

}

void Pieza:: moverIzquierda(){

    columna--;
}


void Pieza:: moverDerecha (){

    columna++;
}

void Pieza:: moverAbajo (){

    fila++;
}











