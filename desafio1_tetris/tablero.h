#ifndef TABLERO_H
#define TABLERO_H
class Tablero
{
private:
    int ancho;
    int alto;
    int bytesPorFila;
    unsigned char** celdas;

public:
    Tablero(int ancho, int alto);
    ~Tablero();

    bool dimesionesvalidas() const;
    void inicializar();
    void imprimir ()const;

    bool dentroDeLimites(int fila, int columna) const;
    bool estaOcupada(int fila, int columna) const;
    void encenderCelda (int fila, int columna);
    void apagarCelda (int fila, int columna);

    bool filaCompleta (int fila) const;
    void eliminarFila (int fila);
    void limpiarFilasCompletas ();

    int getAncho() const;
    int getAlto() const;
    int getBytesPorFila() const;
};

#endif // TABLERO_H
