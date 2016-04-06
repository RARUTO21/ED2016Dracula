#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include "arraylist.h"

class Jugador
{
private:
    ArrayList<Carta> Mano;
    string Orientacion;

public:
    //constructor
    Jugador();

    //metodos
    void putCard(Carta carta);
    Carta getCard(int posicion);
    void delCarta(int posicion);
    void setOrientacion(string orientacion);
};

#endif // JUGADOR_H
