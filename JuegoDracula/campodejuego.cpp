#include "campodejuego.h"
#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include <string>

CampoDeJuego::CampoDeJuego()
{
    jugador1 = Jugador();
    jugador2 = Jugador();
    mazo = Mazo();
    campo = new Carta[9];
}


void CampoDeJuego::reparteCartas(int etapa){
    /**
      reparte las cartas a las manos de los jugadores
    */
    if(etapa == 1){
        jugador1.putCard(mazo.sacarCarta());
        jugador2.putCard(mazo.sacarCarta());
    }

    else if(etapa == 2){
        for(int contador = 0; contador < 4; contador++){
            jugador1.putCard(mazo.sacarCarta());
            jugador2.putCard(mazo.sacarCarta());
        }
    }
}

void CampoDeJuego::reparteCartasInversa(int etapa){
    /**
      deshace el repartimiento de las cartas
    */
    if(etapa == 1){
        mazo.devolverCarta(jugador1.getCard(0));
        jugador1.delCarta(0);
        mazo.devolverCarta(jugador2.getCard(0));
        jugador2.delCarta(0);
    }

    else if(etapa == 2){
        for(int contador = 0; contador < 4; contador++){
            mazo.devolverCarta(jugador1.getCard(contador));
            jugador1.delCarta(contador);
            mazo.devolverCarta(jugador2.getCard(contador));
            jugador2.delCarta(contador);
        }
    }
}
