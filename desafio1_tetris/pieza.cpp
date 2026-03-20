#include "pieza.h"
#include <cstdlib>

Pieza::Pieza(int tipo) {

    if (tipo < 0 || tipo > 6) {

        tipo = rand() % 7;
    }

    cargarForma(tipo);

    fila = 0;
    columna = 0;
}

void Pieza :: cargarForma(int tipo){

    this ->tipo = tipo;

    const unsigned char formas[7][4] = {

    {15, 0, 0, 0}, // I -> 111
    {12, 12, 0, 0}, // O -> 1100 / 1100
    {4, 14, 0, 0}, // T -> 0100 / 1110
    {6, 12, 0, 0}, // S -> 0110 / 1100
    {12, 6, 0, 0}, // Z -> 1100 / 0110
    {8, 14, 0, 0}, // J -> 1000 / 1110
    {2, 14, 0, 0} // L -> 0010 / 1110
    };

    for (int i = 0; i < 4; i++){

        forma[i] = formas[tipo][i];
    }

}

bool Pieza :: tieneBloque(int filaLocal, int columnaLocal) const{


    if (filaLocal < 0 || filaLocal >= 4 || columnaLocal < 0 || columnaLocal >= 4){

        return false;
    }

    int mascara = 1 << (3 - columnaLocal);
    return(forma[filaLocal] & mascara) != 0;

}

int Pieza::getFila () const{

    return fila;
}

int Pieza :: getColumna () const {

    return columna;
}

int Pieza :: getTipo() const {

    return tipo;
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











