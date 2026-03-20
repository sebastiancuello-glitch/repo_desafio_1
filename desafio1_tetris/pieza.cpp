#include "pieza.h"
#include <cstdlib>

Pieza::Pieza(int tipo) {

    if (tipo < 0 || tipo > 6) {

        tipo = rand() % 7;
    }

    this ->tipo = tipo;
    this ->rotacion = 0;
    this ->fila = 0;
    this ->columna = 0;

    cargarForma(this -> tipo, this ->rotacion);

}

void Pieza :: cargarForma(int tipo, int rotacion){

    this -> tipo = tipo;
    this -> rotacion = rotacion;

    const unsigned char formas[7][4][4]=
    {
        {
         {15, 0, 0, 0},
         {8, 8, 8, 8},
         {15, 0, 0, 0},
         {8, 8, 8, 8}
        },
        {
         {12, 12, 0, 0},
         {12, 12, 0, 0},
         {12, 12, 0, 0},
         {12, 12, 0, 0}
        },
        {
         {4, 14, 0, 0},
         {8, 12, 8, 0},
         {14, 4, 0, 0},
         {4, 12, 4, 0}
        },
        {
         {6, 12, 0, 0},
         {8, 12, 4, 0},
         {6, 12, 0, 0},
         {8, 12, 4, 0}
        },
        {
         {12, 6, 0, 0},
         {4, 12, 8, 0},
         {12, 6, 0, 0},
         {4, 12, 8, 0}
        },
        {
         {8, 14, 0, 0},
         {12, 8, 8, 0},
         {14, 2, 0, 0},
         {4, 4, 12, 0}
        },
        {
         {2, 14, 0, 0},
         {8, 8, 12, 0},
         {14, 8, 0, 0},
         {12, 4, 4, 0}
        }
    };

    for (int i = 0; i < 4; i++){

        forma[i] = formas[tipo][rotacion][i];
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

int Pieza :: getRotacion() const {

    return rotacion;
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

void Pieza :: rotarDerecha() {

    int nuevaRotacion = (rotacion + 1) % 4;
    cargarForma(tipo, nuevaRotacion);
}










