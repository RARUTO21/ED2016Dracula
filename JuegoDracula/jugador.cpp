#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include <string>
#include <iostream>
    using namespace std;
Jugador::Jugador(): Mano(4)
{
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

Carta Jugador::popCarta(int index){
    Carta cartaTemp = getCard(index);
    delCarta(index);
    return cartaTemp;
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


string Jugador::imprimeMano(){
    Mano.goToStart();
    string tiraFinal;
    for(int index = Mano.getSize(); index != 0; index--){
        string tira = "";
        tira += Mano.getElement().getSimbolo() + "|";
        tira += Mano.getElement().getColor() + "|";
        tira += Mano.getElement().getNombre() + "|";
        //tira += std::string::Mano.getElement().getValor();
        tiraFinal += tira + "\n";
        Mano.next();
    }
    Mano.goToStart();
    return tiraFinal;
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

void Jugador::appendCarta(Carta carta){
    Mano.append(carta);
}

void Jugador::clearMano(){
    Mano.clear();
}
