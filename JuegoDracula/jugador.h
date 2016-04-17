#ifndef JUGADOR_H
#define JUGADOR_H
#include "carta.h"
#include "arraylist.h"
#include <string>

class Jugador
{
private:
    ArrayList<Carta> Mano;
    string Orientacion;
    bool jugadorInicial;

public:
    //constructor y destructor
    Jugador();
    ~Jugador();
    //metodos
    void putCard(Carta carta);
    Carta getCard(int posicion);
    void delCarta(int posicion);
    void setOrientacion(string orientacion);
    int getSizeMano();
    ArrayList<Carta> getMano();
    string imprimeMano();
    bool esJugadorInicial();
    void esJugadorInicial(bool valor);
    Carta popCarta(int index);
};

#endif // JUGADOR_H
