#include "juego.h"
#include <iostream>

using namespace std;

Juego :: Juego(int ancho, int alto)
    :tablero(ancho, alto), piezaActual(), gameOver(false){

}

bool Juego :: piezaOcupaCelda (int fila, int columna) const {

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4 ; j++){

            if (piezaActual.tieneBloque(i, j)){

                int filaGlobal = piezaActual.getFila() + i;
                int columnaGlobal = piezaActual.getColumna() + j;

                if (filaGlobal == fila && columnaGlobal == columna){

                    return true;
                }
            }
        }
    }
    return false;
}

void Juego :: imprimirConPieza() const {

    for ( int i = 0; i< tablero.getAlto(); i++){

        cout << i << " |";

        for ( int j = 0; j < tablero.getAncho(); j++){

            if (piezaOcupaCelda(i, j) || tablero.estaOcupada(i, j)){

                cout << "#";
            }

            else {

                cout << ".";
            }

        }
        cout << "|" << endl;
    }

    cout <<"  +";

    for (int j = 0; j < tablero.getAncho(); j++){

        cout << "-";
    }

    cout<< "+" << endl;
}

bool Juego :: puedeMoverse(const Pieza& pieza, int nuevaFila, int nuevaColumna)const {

    for (int i = 0; i < 4; i++){

        for (int j = 0; j < 4; j++){

            if(pieza.tieneBloque(i,j)){

                int filaGlobal = nuevaFila + i;
                int columnaGlobal = nuevaColumna + j;

                if (!tablero.dentroDeLimites(filaGlobal, columnaGlobal)){

                    return false;
                }

                if (tablero.estaOcupada(filaGlobal, columnaGlobal)){

                    return false;
                }
            }
        }
    }

    return true;

}


void Juego :: fijarPieza(){

    for (int i = 0; i < 4; i++){

        for (int j = 0; j < 4; j++){


            if( piezaActual.tieneBloque(i, j)){

                tablero.encenderCelda(piezaActual.getFila() + i , piezaActual.getColumna() + j);
            }
        }
    }
}

void Juego :: centrarPieza (Pieza& pieza){

    pieza.setPosicion(0, (tablero.getAncho() / 2) - 2);
}


void Juego :: generarNuevaPieza(){

    Pieza nuevaPieza;
    centrarPieza(nuevaPieza);

    if(!puedeMoverse(nuevaPieza, nuevaPieza.getFila(), nuevaPieza.getColumna())){

        gameOver = true;
    }

    else{

        piezaActual = nuevaPieza;
    }

}

void Juego::aplicarDescenso(){

    if (puedeMoverse(piezaActual, piezaActual.getFila()+ 1, piezaActual.getColumna())){

        piezaActual.moverAbajo();
    }
    else{

        fijarPieza();
        tablero.limpiarFilasCompletas();
        generarNuevaPieza();
    }
}
void Juego :: procesarOpcion(char opcion){

    if (opcion == 'a'){


        if(puedeMoverse(piezaActual, piezaActual.getFila(), piezaActual.getColumna() - 1)){

            piezaActual.moverIzquierda();
        }
    }
    else if (opcion == 'd'){

        if (puedeMoverse(piezaActual, piezaActual.getFila(), piezaActual.getColumna() + 1)){

            piezaActual.moverDerecha();
        }
    }

    else if (opcion == 's'){

        if(puedeMoverse(piezaActual, piezaActual.getFila(), piezaActual.getColumna())){

            piezaActual.moverAbajo();

        }
        else {

            fijarPieza();
            tablero.limpiarFilasCompletas();
            generarNuevaPieza();

        }
    }

    else if (opcion == 'r')
        {
        Pieza copia = piezaActual;
        copia.rotarDerecha();

        if(puedeMoverse(copia, copia.getFila(), copia.getColumna())){
          piezaActual.rotarDerecha();
        }
    }
}

bool Juego::iniciar(){


    if (!tablero.dimesionesvalidas()){

        cout << "dimensiones invalidas. el ancho y el alto deben ser minimo 8, y el ancho debe ser multiplo de 8"<< endl;
        return false;

    }
    tablero.inicializar();
    centrarPieza(piezaActual);

    if (!puedeMoverse(piezaActual, piezaActual.getFila(), piezaActual.getColumna())){

       cout << " Game Over: no se pudo colocar la pieza inicial. " << endl;
       return false;
    }

    return true;
}

void Juego :: ejecutar(){

    char opcion;
    while (!gameOver) {


        cout << "\n ------------------------\n";
        imprimirConPieza();


        cout << "[a] izquierda [d] derecha [s] abajo [r] rotar [q] salir\n";
        cout << "opcion:";
        cin >> opcion;

        if(opcion == 'q'){

            break;
        }

        procesarOpcion(opcion);

        if(!gameOver &&(opcion == 'a' || opcion == 'd' || opcion == 'r')){

            aplicarDescenso();
        }
    }

    if (gameOver){

        cout << "n\----------------\n";
        tablero.imprimir();
        cout << "\nGame Over: no hay espacio para una nueva pieza. "<< endl;
    }
}
