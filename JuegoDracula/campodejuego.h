

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
    ArrayList<Carta> getManoJugador(int jugador);
    void moverCartaJugadorACampo(int numeroJugador,  int posMano, int posCampo);
    void moverCartaCampoAJugador(int numeroJugador, int posCampo);
    Jugador getJugador(int jugador);
    int evaluaCampo(int etapa);
    void evaluaCampoReversa(int etapa);

};

#endif // CAMPODEJUEGO_H

