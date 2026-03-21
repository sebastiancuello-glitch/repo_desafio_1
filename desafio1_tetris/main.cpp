#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "pieza.h"


using namespace std;

bool piezaOcupaCelda (const Pieza& pieza, int fila, int columna){

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4 ; j++){

            if (pieza.tieneBloque(i, j)){

                int filaGlobal = pieza.getFila() + i;
                int columnaGlobal = pieza.getColumna() + j;

                if (filaGlobal == fila && columnaGlobal == columna){

                    return true;
                }
            }
        }
    }
    return false;
}

void imprimirConPieza(const Tablero& tablero, const Pieza& pieza){

    for ( int i = 0; i< tablero.getAlto(); i++){

        cout << i << " |";

        for ( int j = 0; j < tablero.getAncho(); j++){

            if (piezaOcupaCelda(pieza, i, j) || tablero.estaOcupada(i, j)){

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


bool puedeMoverse( const Tablero& tablero, const Pieza& pieza, int nuevaFila, int nuevaColumna){

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

void fijarPieza(Tablero& tablero, const Pieza& pieza){

    for (int i = 0; i < 4; i++){

        for (int j = 0; j < 4; j++){


            if( pieza.tieneBloque(i, j)){

                tablero.encenderCelda(pieza.getFila() + i , pieza.getColumna() + j);
            }
        }
    }
}
void centrarPieza (Pieza& pieza, int anchoTablero){

    pieza.setPosicion(0, (anchoTablero / 2) - 2);
}
void imprimirSeparador(){

    cout << "\n ------------------------\n";
}


int main()
{

    srand (time(nullptr));
    int ancho, alto;

    cout << "ingrese el acho del tablero: "<< endl;
    cin >> ancho;

    cout<< "ingrese el alto del tablero: "<< endl;
    cin >> alto;

    Tablero tablero(ancho, alto);

    if (!tablero.dimesionesvalidas()){

        cout << "dimensiones invalidas. el ancho y el alto deben ser minimo 8, y el ancho debe ser multiplo de 8"<< endl;
        return 1;
    }

    tablero.inicializar();

    Pieza pieza;
    centrarPieza(pieza, tablero.getAncho());

    if (!puedeMoverse(tablero, pieza, pieza.getFila(), pieza.getColumna())){

        cout << " Game Over: no se pudo colocar la pieza inicial. " << endl;
        return 0;
    }

    char opcion;
    bool gameOver = false;

    do
    {
        imprimirSeparador();
        imprimirConPieza(tablero,pieza);

        cout << "[a] izquierda [d] derecha [s] abajo [r] rotar [q] salir\n";
        cout << "opcion:";
        cin >> opcion;





        if(opcion == 'a'){

            if(puedeMoverse(tablero, pieza, pieza.getFila(), pieza.getColumna() - 1)){

                pieza.moverIzquierda();
            }
        }

        else if (opcion == 'd'){

            if (puedeMoverse(tablero, pieza, pieza.getFila(), pieza.getColumna() + 1)){

                pieza.moverDerecha();
            }
        }

        else if (opcion == 's'){

            if(puedeMoverse(tablero, pieza, pieza.getFila(), pieza.getColumna())){

                pieza.moverAbajo();
            }

            else {

                fijarPieza(tablero, pieza);
                tablero.limpiarFilasCompletas();

                Pieza nuevaPieza;
                centrarPieza(nuevaPieza, tablero.getAncho());


                if(!puedeMoverse(tablero, nuevaPieza, nuevaPieza.getFila(),nuevaPieza.getColumna())){

                    gameOver = true;
                }

                else{
                    pieza = nuevaPieza;
                }

            }
        }

        else if (opcion == 'r'){

            Pieza copia = pieza;
            copia.rotarDerecha();

            if(puedeMoverse(tablero, copia, copia.getFila(), copia.getColumna())){
                pieza.rotarDerecha();
            }
        }
    }while (opcion != 'q' && !gameOver);




    if(gameOver){

        imprimirSeparador();
        tablero.imprimir();
        cout <<"\nGame Over: no hay espacio para una nueva pieza. " << endl;
    }



    return 0;

}

