#include "campodejuego.h"
#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include <string>
#include "matriz.h"
#include <QPushButton>


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
        jugador1.clearMano();
        jugador2.clearMano();
        for(int contador = 0; contador < 4; ++contador){
            jugador1.putCard(mazo.sacarCarta());
            jugador2.putCard(mazo.sacarCarta());
        }
        for(int hilera = 0; hilera < 3; hilera++){
            for(int columna = 0; columna< 3; columna++){
                campo.setElement(hilera,columna,cartaVacia);
            }
        }
        campo.setElement(1,1,mazo.sacarCarta());
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
        // y la elimina
        jugador1.delCarta(posMano);
        jugador1.appendCarta(cartaVacia);
    }
    else if(numeroJugador == 2){
        campo.setElement(posCampoRow,posCampoColumn,jugador2.getCard(posMano));
        jugador2.delCarta(posMano);
        jugador2.appendCarta(cartaVacia);
    }
}

void CampoDeJuego::moverCartaCampoAJugador(int numeroJugador,
                                           int posCampoColumn, int posCampoRow){
    /**
      Descripcion:
        mueve una carta del campo a la mano de un jugador
      Entradas:
        int numero Jugador: jugador 1 o 2
        int posCampoColumn: posicion de la columna en la matriz
        int posCampoRow: posicion de la hilera en la matriz
    */
    if (numeroJugador == 1){
        jugador1.putCard(campo.popElement(posCampoRow, posCampoColumn, cartaVacia));
    }
    else if(numeroJugador == 2){
        jugador2.putCard(campo.popElement(posCampoRow, posCampoColumn,cartaVacia));
    }
}

Jugador CampoDeJuego::getJugador(int jugador){
    /**
      Descripcion:
        regresa el jugador para utilizar su mano u otra funcion
      Entrada:
        int jugador: numero de jugador 1 o 2
    */
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
     * Entrada:
     *  int rowArray: la hilera a la cual evaluar
     * Salida:
     *  int puntuacion: la puntuacion total de esa hilera
     */
    int puntuacion = 0;
    int puntuacionRow = 0;
    int multiplicador = 1;
    if(campo.getElement(rowArray,0).getSimbolo() == campo.getElement(rowArray,1).getSimbolo() &&
            campo.getElement(rowArray,1).getSimbolo() == campo.getElement(rowArray,2).getSimbolo()){
        multiplicador = 5;
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
        if(campo.getElement(rowArray, columnArray).getNombre() == "j"){
            puntuacionRow +=0;
        }
        else{
            puntuacionRow += campo.getElement(rowArray, columnArray).getValor();
        }
        if(campo.getElement(rowArray, columnArray).getNombre() == "joker"){
            multiplicador = 0;
        }
    }
    puntuacion += puntuacionRow;
    puntuacion *= multiplicador;

    return puntuacion;
}

int CampoDeJuego::evaluaFilaVertical(int columnArray){
    /**
     * Descripcion:
     *  Evalua la columna horizontalmente
     * Entradas:
     *  int columnArray: la columna a la cual evaluar tiene q ser de 0-2
     * Salida:
     *  int puntuacion la puntuacion total de la columna
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
        if(campo.getElement(rowArray,columnArray).getNombre() == "q"){
            puntuacionColumn +=0;
        }
        else{
            puntuacionColumn += campo.getElement(rowArray,columnArray).getValor();
        }
        if(campo.getElement(rowArray,columnArray).getNombre() == "joker"){
            multiplicador = 0;
        }
    }
    puntuacion += puntuacionColumn;
    puntuacion *= multiplicador;


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

int CampoDeJuego::evaluaDiferencia(){
    /**
     * Descripcion:
     *  evalua la diferencia de puntaje entre el jugador vertical y el horizontal
     * Salida:
     *  int diferencia: la diferencia
     */
    int puntuacion1 = evaluaCampoHorizontal();
    int puntuacion2 = evaluaCampoVertical();
    int diferencia;
    if(puntuacion1 > puntuacion2){
        diferencia = puntuacion1 - puntuacion2;
    }
    else if(puntuacion1 < puntuacion2){
        diferencia = puntuacion2 - puntuacion1;
    }
    else{
        diferencia = 0;
    }

}

string CampoDeJuego::imprimeMano(int jugador){
    /**
     * Descripcion:
     *  imprime la mano de el jugador indicado
     * Entrada:
     *  int Jugador: el numero de jugador
     */
    if(jugador == 1){
        return jugador1.imprimeMano();
    }
    else if (jugador == 2){
        return jugador2.imprimeMano();
    }
}


string CampoDeJuego::imprimeCampo(){
    /**
     * Descripcion:
     *  imprime el campo en la consola, se utiliza para debugging
     */
    string tiraFinal = "";
    for(int hilera = 0; hilera<3; hilera++){
        //tiraFinal+= "hilera numero: " + to_string(hilera) + "\n";
        for(int columna = 0; columna<3; columna++){
            string tira = "";
            tira += campo.getElement(hilera, columna).getSimbolo() + "|";
            tira += campo.getElement(hilera, columna).getColor() + "|";
            tira += campo.getElement(hilera, columna).getNombre() + "|";
            //tira += to_string(campo.getElement(hilera, columna).getValor());
            tiraFinal += tira + "\n";
        }
    }
    return tiraFinal;
}




void CampoDeJuego::manoAMazo(int jugador){
    /**
      Descripcion:
        devuelve la primera carta de un jugador al mazo
      Entrada:
        int jugador: cual jugador recoger carta
    */

    if(jugador == 1){
        mazo.devolverCarta(jugador1.popCarta(0));
    }
    else if (jugador == 2){
        mazo.devolverCarta(jugador2.popCarta(0));
    }
}


bool CampoDeJuego::isFull(){
    /**
     * Descripcion:
     *  retorna true si el campo esta lleno
     *  else retorna false
     */
    return campo.isFull();
}

//Anthony

bool CampoDeJuego::estaDisponible(int row, int column){
    if(row == 0){
        //(0,0)
        if(column == 0){
            if(campo.getElement(0,1).getNombre() == "vacio" & campo.getElement(1,0).getNombre() == "vacio"){
                //std::cout<<"(0,0)=    (0,1)=='vacio'"<<campo.getElement(0,1).getNombre()=="vacio"<<endl;
                return false;
            }
            else{
                return true;
            }
        }
        else{
            //(0,2)
            if(column == 2){
                if(campo.getElement(0,1).getNombre() == "vacio" & campo.getElement(1,2).getNombre() == "vacio"){
                    return false;
                }
                else{
                    return true;
                }
            }
        }

    }
    else{//row = 2
        //(2,0)
        if(column == 0){
            if(campo.getElement(2,1).getNombre() == "vacio" & campo.getElement(1,0).getNombre() == "vacio"){
                return false;
            }
            else{
                return true;
            }

        }
        else{
            if(column == 2){
                if(campo.getElement(2,1).getNombre() == "vacio" & campo.getElement(1,2).getNombre() == "vacio"){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }
}

void CampoDeJuego::ponerIcono(QPushButton boton, Carta carta){
    boton.setIcon(carta.getIcono());
}

//Devuelve le icono desde el campo de juego
QIcon CampoDeJuego::getIcono(int jugador, int index, int hilera){
    if(jugador == 1){
        return jugador1.getCard(index).getIcono();
    }
    else if(jugador == 2){
        return jugador2.getCard(index).getIcono();
    }
    else if(jugador == 3){
        return campo.getElement(hilera,index).getIcono();
    }
}

int CampoDeJuego::getSizeMazo(){
    return mazo.getSize();
}


bool CampoDeJuego::hayJugadorInicialDefinido(){
    return jugadorInicialDefinido;
}

Carta CampoDeJuego::getCartaRonda1Jugador(int jugador){
    return getJugador(jugador).getCard(0);
}


bool CampoDeJuego::evaluarGanadorEtapa1(){
    reparteCartas(1);

    //Si el jugador1 tiene carta negra:
    if(getCartaRonda1Jugador(1).getColor() == "negro"){
        //Si el jugador2 tiene carta roja: gana el jugador2
        if(getCartaRonda1Jugador(2).getColor()== "rojo"){
            jugador2.esJugadorInicial(true);
            return true;
        }
        else{
            //Pero, si el jugador 2 tiene carta negra también: se rebaraja
            if(getCartaRonda1Jugador(2).getColor() == "negro"){
                return false;
            }
        }
    }
    else{

        //Si el jugador1 tiene un joker
        if(getCartaRonda1Jugador(1).getNombre() == "joker"){
            //Y el jugador2 también: va de nuevo: false
            if(getCartaRonda1Jugador(2).getNombre() == "joker"){
                return false;
            }
        }


        //Si el jugador1 tiene carta roja:
        if(getCartaRonda1Jugador(1).getColor() == "rojo"){
            //Si el jugador2 tiene carta negra: gana el jugador1
            if(getCartaRonda1Jugador(2).getColor() == "negro"){
                jugador1.esJugadorInicial(true);
                return true;
            }
            else{
                //Si el jugador2 también tiene una carta roja:
                if(getCartaRonda1Jugador(2).getColor() == "rojo"){
                    //Si el jugador1 tiene una carta de corazones
                    if(getCartaRonda1Jugador(1).getSimbolo() == "corazones"){
                        //Y el jugador2 también tiene una carta de corazones
                        if(getCartaRonda1Jugador(2).getSimbolo() == "corazones"){
                            //Si la carta de corazones del jugador1 tiene mayor valor que la carta del jugador2
                            if(getCartaRonda1Jugador(1).getValor() > getCartaRonda1Jugador(2).getValor()){
                                jugador1.esJugadorInicial(true);
                                return true;
                            }
                            else{
                                jugador2.esJugadorInicial(true);
                                return true;
                            }

                        }
                        else{
                            //Si el jugador1 tiene carta de corazones y el jugador tiene carta de oros
                            jugador1.esJugadorInicial(true);
                            return true;
                        }


                    }
                    else{
                        //El jugador1 tiene carta de oros
                        if(getCartaRonda1Jugador(2).getSimbolo() == "corazones"){
                            //Y el jugador2 tiene carta de corazones
                            jugador2.esJugadorInicial(true);
                            return true;
                        }
                        else{
                            //O el jugador2 tiene también carta de oros
                            if(getCartaRonda1Jugador(2).getSimbolo() == "oros"){
                                if(getCartaRonda1Jugador(1).getValor() > getCartaRonda1Jugador(2).getValor()){
                                    //El jugador1 tiene la carta de oros de mayor valor
                                    jugador1.esJugadorInicial(true);
                                }
                                else{
                                    //El jugador2 tiene la carta de mayor valor
                                    jugador2.esJugadorInicial(true);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

