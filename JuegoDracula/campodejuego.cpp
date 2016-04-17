#include "campodejuego.h"
#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include <string>
#include "matriz.h"


CampoDeJuego::CampoDeJuego(): jugador1(), jugador2(), mazo(), campo()
{
    //jugador1 = Jugador;
    //jugador2 = Jugador;
    //mazo = Mazo;
    cartaVacia = Carta("vacio", "vacio", "vacio", 0);
    //campo = Matriz;
    jugadorInicialDefinido = false;
    for(int hilera = 0; hilera < 3; hilera++){
        for(int columna = 0; columna< 3; columna++){
            campo.setElement(hilera,columna,cartaVacia);
        }
    }
}

CampoDeJuego::~CampoDeJuego(){

}

void CampoDeJuego::reparteCartas(int etapa){
    /**
      Descripcion:
        reparte las cartas de el mazo a los jugadores
      Entradas:
        int etapa: la etapa actual
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
      Descripcion:
        reparte las cartas inversamente
      DISCUTIR ESTE METODO
    **/
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

ArrayList<Carta> CampoDeJuego::getManoJugador(int jugador){
    /**
      Descripcion:
        retornar la mano del jugador
      Entrada:
        int jugador: el jugador 1 o el jugador 2
      Salida:
        Un ArrayList de cartas
    */
    if(jugador  == 1){
        return jugador1.getMano();
    }
    else if(jugador == 2){
        return jugador2.getMano();
    }
}

//*************************************************************************
//*************************************************************************

void CampoDeJuego::moverCartaJugadorACampo(int numeroJugador, int posMano,
                                           int posCampoColumn, int posCampoRow){
    /**
      Descripcion:
        Mueve una carta de la mano del jugador hacia el campo de juego "campo"
      Entradas:
        int numeroJugador: El numero del jugador, jugador1 o jugador2
        int posMano: la posicion de la carta en la mano del jugador
        int posCampoColumn: la posicion de la columna del campo en el que se quiere
        colocar
        int posCampoRow: la posicion de la hilera del campo en donde se quiere colocar
        la carta
    */
    if (numeroJugador == 1){
        campo.setElement(posCampoRow,posCampoColumn,jugador1.getCard(posMano));
        // ^ pone la carta en el campo
        jugador1.delCarta(posMano);
    }
    else if(numeroJugador == 2){
        campo.setElement(posCampoRow,posCampoColumn,jugador2.getCard(posMano));
        jugador2.delCarta(posMano);
    }
}

void CampoDeJuego::moverCartaCampoAJugador(int numeroJugador,
                                           int posCampoColumn, int posCampoRow){
    if (numeroJugador == 1){
        jugador1.putCard(campo.popElement(posCampoRow, posCampoColumn, cartaVacia));
    }
    else if(numeroJugador == 2){
        jugador2.putCard(campo.popElement(posCampoRow, posCampoColumn,cartaVacia));
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

int CampoDeJuego::evaluaFilaHorizontal(int rowArray){
    /**
     * Descripcion:
     *  Evalua la fila horizontalmente
     * DISCUTIR
     */
    int puntuacion = 0;
    int puntuacionRow = 0;
    int multiplicador = 1;
    if(campo.getElement(rowArray,0).getSimbolo() == campo.getElement(rowArray,1).getSimbolo() &&
            campo.getElement(rowArray,1).getSimbolo() == campo.getElement(rowArray,2).getSimbolo()){
        multiplicador = 4;
    }
    else if(campo.getElement(rowArray,0).getColor() == campo.getElement(rowArray,1).getColor() &&
            campo.getElement(rowArray,1).getColor() == campo.getElement(rowArray,2).getColor()){
        multiplicador = 3;
    }
    else if(campo.getElement(rowArray,0).getSimbolo() == campo.getElement(rowArray,1).getSimbolo() ||
            campo.getElement(rowArray,1).getSimbolo() == campo.getElement(rowArray,2).getSimbolo() ||
            campo.getElement(rowArray,0).getSimbolo() == campo.getElement(rowArray,2).getSimbolo()){
        multiplicador = 2;
    }
    for(int columnArray = 0; columnArray < 3; columnArray++){
        puntuacionRow += campo.getElement(rowArray, columnArray).getValor();
        if(campo.getElement(rowArray, columnArray).getSimbolo() == "Joker"){
            multiplicador = 0;
        }
    }
    puntuacionRow *= multiplicador;
    puntuacion += puntuacionRow;
    return puntuacion;
}

int CampoDeJuego::evaluaFilaVertical(int columnArray){
    /**
     * Descripcion:
     *  Evalua la columna horizontalmente
     * DISCUTIR
     */
    int puntuacion = 0;
    int puntuacionColumn = 0;
    int multiplicador = 1;
    if(campo.getElement(0,columnArray).getSimbolo() == campo.getElement(1,columnArray).getSimbolo() &&
            campo.getElement(1,columnArray).getSimbolo() == campo.getElement(2,columnArray).getSimbolo()){
        multiplicador = 4;
    }
    else if(campo.getElement(0,columnArray).getColor() == campo.getElement(1,columnArray).getColor() &&
            campo.getElement(1,columnArray).getColor() == campo.getElement(2,columnArray).getColor()){
        multiplicador = 3;
    }
    else if(campo.getElement(0,columnArray).getSimbolo() == campo.getElement(1,columnArray).getSimbolo() ||
            campo.getElement(1,columnArray).getSimbolo() == campo.getElement(2,columnArray).getSimbolo() ||
            campo.getElement(0,columnArray).getSimbolo() == campo.getElement(2,columnArray).getSimbolo()){
        multiplicador = 2;
    }
    for(int rowArray = 0; rowArray < 3; rowArray++){
        puntuacionColumn += campo.getElement(rowArray,columnArray).getValor();
        if(campo.getElement(rowArray,columnArray).getSimbolo() == "Joker"){
            multiplicador = 0;
        }
    }
    puntuacionColumn *= multiplicador;
    puntuacion += puntuacionColumn;

    return puntuacion;
}

//

int CampoDeJuego::evaluaCampoHorizontal(){
    /**
     * Descripcion:
     *  evalua el campo para el jugador horizontal
     * Salida:
     *  int puntuacion final
     */
    int puntuacion = 0;
    for(int fila = 0; fila < 3; fila++){
        puntuacion += evaluaFilaHorizontal(fila);
    }
    return puntuacion;
}

int CampoDeJuego::evaluaCampoVertical(){
    /**
     * Descripcion:
     *  evalua el campo para el jugador vertical
     * Salida:
     *  int puntuacion final
     */
    int puntuacion = 0;
    for(int fila = 0; fila < 3; fila++){
        puntuacion += evaluaFilaVertical(fila);
    }
    return puntuacion;
}

//*************************************************************************
//*************************************************************************

string CampoDeJuego::imprimeMano(int jugador){
    if(jugador == 1){
        return jugador1.imprimeMano();
    }
    else if (jugador == 2){
        return jugador2.imprimeMano();
    }
}


string CampoDeJuego::imprimeCampo(){
    string tiraFinal = "";
    for(int hilera = 0; hilera<3; hilera++){
        tiraFinal+= "hilera numero: " + to_string(hilera) + "\n";
        for(int columna = 0; columna<3; columna++){
            string tira = "";
            tira += campo.getElement(hilera, columna).getColor() + "|";
            tira += campo.getElement(hilera, columna).getNombre() + "|";
            tira += to_string(campo.getElement(hilera, columna).getValor());
            tiraFinal += tira + "\n";
        }
    }
    return tiraFinal;
}

//Anthony

bool CampoDeJuego::hayJugadorInicialDefinido(){
    return jugadorInicialDefinido;
}

Carta CampoDeJuego::getCartaRonda1Jugador(int jugador){
    return getJugador(jugador).getCard(0);
}


bool CampoDeJuego::evaluarGanadorEtapa1(){
    reparteCartas(1);


    if(getCartaRonda1Jugador(1).getColor() == "negro"){
        if(getCartaRonda1Jugador(2).getColor()== "rojo"){
            jugador2.esJugadorInicial(true);
            return true;
        }
        else{
            if(getCartaRonda1Jugador(2).getColor() == "negro"){
                return false;
            }
        }
    }
    else{
            //cj.getManoJugador(1).getCard(0).getColor()
        if(getCartaRonda1Jugador(1).getColor() == "rojo"){
            if(getCartaRonda1Jugador(2).getColor() == "negro"){
                jugador1.esJugadorInicial(true);
                return true;
            }
            else{
                if(getCartaRonda1Jugador(2).getColor() == "rojo"){
                    //detallar esto: cuando dos cartas son rojas
                    if(getCartaRonda1Jugador(1).getNombre() == "joker"){//cartaJugador1
                        jugador2.esJugadorInicial(true);
                        return true;
                    }
                    else{
                        if(getCartaRonda1Jugador(2).getNombre() == "joker"){//cartaJugador2
                            jugador1.esJugadorInicial(true);
                            return true;
                        }
                    }

                    //if()
                }
            }
        }
    }
}

