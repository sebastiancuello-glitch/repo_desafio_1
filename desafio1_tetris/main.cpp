#include <iostream>
#include <cstdlib>
#include <ctime>
#include "juego.h"


using namespace std;

int main (){

    srand(time(nullptr));

    int ancho, alto;

    cout << "ingrese el acho del tablero: ";
    cin>> ancho;

    cout <<"ingrese el alto del tablero: ";
    cin >> alto;

    Juego juego(ancho, alto);


    if(juego.iniciar()){

        juego.ejecutar();
    }

    return 0;


}
