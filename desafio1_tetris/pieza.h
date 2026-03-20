#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{

private:
    unsigned char forma[4];
    int fila;
    int columna;
    int tipo;

    void cargarForma(int tipo);


public:
    Pieza(int tipo = -1);

    bool tieneBloque(int filaLocal, int columnaLocal) const;

    int getFila() const;
    int getColumna () const;
    int getTipo () const;


    void setFila (int fila);
    void setColumna(int columna);
    void setPosicion(int fila, int columna);

    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
};




#endif // PIEZA_H
