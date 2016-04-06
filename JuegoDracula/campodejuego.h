#ifndef CAMPODEJUEGO_H
#define CAMPODEJUEGO_H

#include "campodejuego.h"
#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include "mazo.h"

class CampoDeJuego
{
private:
    Jugador jugador1;
    Jugador jugador2;
    Mazo mazo;
    Carta *campo;
public:
    CampoDeJuego();
    ~CampoDeJuego();
    void reparteCartas(int etapa);
    void reparteCartasInversa(int etapa);
    ArrayList<Carta> getManoJugador(int cartaIndex);
    void moverCartaJugadorACampo(int numeroJugador, Carta carta, int posMano, int posCampo);
    void moverCartaCampoAJugador(int numeroJugador, Carta carta, int posCampo);
    Jugador getJugador(int jugador);
    int evaluaCampo(int etapa);
    void evaluaCampoReversa(int etapa);

};

#endif // CAMPODEJUEGO_H
