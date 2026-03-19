#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{

private:
    unsigned char forma[4];
    int fila;
    int columna;


public:
    Pieza();

    bool tieneBloque(int filaLocal, int columnaLocal) const;

    int NFila() const;
    int NColumna () const;

    void setFila (int fila);
    void setColumna(int columna);
    void setPosicion(int fila, int columna);

    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
};




#endif // PIEZA_H
