

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
    Carta **campo;
    Carta cartaVacia;
public:
    CampoDeJuego();
    ~CampoDeJuego();
    void reparteCartas(int etapa);
    void reparteCartasInversa(int etapa);
    ArrayList<Carta> getManoJugador(int jugador);
    void moverCartaJugadorACampo(int numeroJugador,  int posMano,
                                 int posCampoColumn, int posCampoRow);
    void moverCartaCampoAJugador(int numeroJugador,
                                 int posCampoColumn, int posCammpoRow);
    Jugador getJugador(int jugador);
    int evaluaFilaHorizontal(int rowArray);
    int evaluaFilaVertical(int columnArray);
    int evaluaCampoVertical();
    int evaluaCampoHorizontal();
};

#endif // CAMPODEJUEGO_H

