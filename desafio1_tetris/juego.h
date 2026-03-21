#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "pieza.h"


class Juego {

private:

    Tablero tablero;
    Pieza piezaActual;
    bool gameOver;

    bool piezaOcupaCelda(int fila, int columna) const;
    void imprimirConPieza () const ;
    bool puedeMoverse(const Pieza& pieza, int nuevaFila, int nuevaColumna) const;
    void fijarPieza();
    void centrarPieza(Pieza& pieza);
    void generarNuevaPieza();
    void procesarOpcion(char opcion);

public:
    Juego(int ancho, int alto);

    bool iniciar();
    void ejecutar();
};


#endif // JUEGO_H
