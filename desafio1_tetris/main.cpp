#include <iostream>
#include "tablero.h"
#include "pieza.h"


using namespace std;

void dibujarPiezaEnTablero(Tablero& tablero, const Pieza & pieza){

    for (int i = 0; i < 4; i++){

        for(int j = 0; j <4; j++){

            if (pieza.tieneBloque(i,j)){

                tablero.encenderCelda(pieza.NFila()+ i, pieza.NColumna() + j);
            }
        }
    }
}

int main()
{
    cout << "proyecto tetris!" << endl;


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
    pieza.setPosicion(1, (ancho / 2 )- 2);

    dibujarPiezaEnTablero(tablero,pieza);


    cout << "\ntablero con pieza de prueba:\n";
    tablero.imprimir();


    return 0;

}

