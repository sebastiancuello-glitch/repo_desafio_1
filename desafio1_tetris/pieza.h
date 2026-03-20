#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{

private:
    unsigned char forma[4];
    int fila;
    int columna;
    int tipo;
    int rotacion;

    void cargarForma(int tipo, int rotacion);


public:
    Pieza(int tipo = -1);

    bool tieneBloque(int filaLocal, int columnaLocal) const;

    int getFila() const;
    int getColumna () const;
    int getTipo () const;
    int getRotacion () const;



    void setFila (int fila);
    void setColumna(int columna);
    void setPosicion(int fila, int columna);

    void moverIzquierda();
    void moverDerecha();
    void moverAbajo();
    void rotarDerecha();
};




#endif // PIEZA_H
