#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include <string>

Jugador::Jugador()
{
    Mano = ArrayList<Carta>(4);
    Orientacion = "";
    jugadorInicial = false;
}

Jugador::~Jugador(){
    /**
      Destructor
    */
    Mano.clear();
    Orientacion.clear();
}

void Jugador::putCard(Carta carta){
    /**
      Descripcion:
        Pone una carta en la mano del jugador
      Entrada:
        carta: La carta la cual hay q meter
      Salida:
        ninguna
    */
    Mano.append(carta);
}

Carta Jugador::getCard(int posicion){
    /**
      Descripcion:
      Retorna una carta dependiendo de el numero ingresado

      Entrada:
        posicion: la posicion en la cual esta la carta a retornar
      Salida:
        Carta
    */
    Mano.goToPos(posicion);
    return Mano.getElement();
}

void Jugador::delCarta(int posicion){
    /**
      Descripcion:
      Borra una carta deacuerdo con la posicion

      Entrada:
        posicion: la posicion de la carta en el ArrayList
      Salida:
        ninguna
    */
    Mano.goToPos(posicion);
    Mano.remove();
}

void Jugador::setOrientacion(string orientacion){
    /**
      Descripcion:
        Actualiza la orientacion de la carta
      Entrada:
        orientacion: string que nos dice la orientacion
    */
    Orientacion = orientacion;
}

int Jugador::getSizeMano(){
    int size = Mano.getSize();
    return size;
}

ArrayList<Carta> Jugador::getMano(){
    return Mano;
}

bool Jugador::esJugadorInicial(){
    return jugadorInicial;
}

void Jugador::esJugadorInicial(bool valor){
    jugadorInicial = valor;
}


