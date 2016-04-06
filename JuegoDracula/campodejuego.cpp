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
      Descripcion:
        reparte las cartas a las manos de los jugadores
      Entrada:
        int etapa: etapa del juego
    */
    if(etapa == 1){
        jugador1.putCard(mazo.sacarCarta());
        jugador2.putCard(mazo.sacarCarta());
    }

    else if(etapa == 2){
        for(int contador = 0; i < 4; contador++){
            jugador1.putCard(mazo.sacarCarta());
            jugador2.putCard(mazo.sacarCarta());
        }
    }
}

void CampoDeJuego::reparteCartasInversa(int etapa){
    /**
      Descripcion:
        deshace el repartimiento de las cartas
      Entradas:
        int etapa: etapa del juego
    */
    if(etapa == 1){
        mazo.devolverCarta(jugador1.getCard(0));
        jugador1.delCarta(0);
        mazo.devolverCarta(jugador2.getCard(0));
        jugador2.delCarta(0);
    }

    else if(etapa == 2){
        for(int contador = 0; i < 4; contador++){
            mazo.devolverCarta(jugador1.getCard(contador));
            jugador1.delCarta(contador);
            mazo.devolverCarta(jugador2.getCard(contador));
            jugador2.delCarta(contador);
        }
    }
}

ArrayList<Carta> CampoDeJuego::getManoJugador(int jugador){
    if(jugador =1){
        return jugador1.getMano();
    }
    else if(jugador = 2){
        return jugador2.getMano();
    }
}

void CampoDeJuego::moverCartaJugadorACampo(int numeroJugador, int posMano, int posCampo){
    if (numeroJugador == 1){
        campo[posCampo] = jugador1.getCard(posMano);
        jugador1.delCarta(posMano);
    }
    else if(numeroJugador == 2){
        campo[posCampo] = jugador2.getCard(posMano);
        jugador2.delCarta(posMano);
    }
}

void CampoDeJuego::moverCartaCampoAJugador(int numeroJugador, int posCampo){
    if (numeroJugador == 1){
        jugador1.putCard(campo[posCampo]);
        campo[posCampo] = null;
    }
    else if(numeroJugador == 2){
        jugador1.putCard(campo[posCampo]);
        campo[posCampo] = null;
    }
}

Jugador CampoDeJuego::getJugador(int jugador){
    if (jugador== 1){
        return jugador1;
    }
    else if(jugador == 2){
        return jugador2;
    }
}

int CampoDeJuego::evaluaCampo(int etapa){
    int puntuacion = 0;
    if (etapa == 1){
        //TODO
    }
    else if (etapa == 2){
        //TODO
    }
    return puntuacion
}

void CampoDeJuego::evaluaCampoReversa(int etapa){
    if (etapa == 1){
        //TODO
    }
    else if (etapa == 2 ){
        //TODO
    }
}
