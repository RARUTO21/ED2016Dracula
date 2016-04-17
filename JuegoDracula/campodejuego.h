

#ifndef CAMPODEJUEGO_H
#define CAMPODEJUEGO_H

#include "campodejuego.h"
#include "jugador.h"
#include "arraylist.h"
#include "carta.h"
#include "mazo.h"
#include "matriz.h"
#include <QPushButton>

class CampoDeJuego
{
private:
    Jugador jugador1;
    Jugador jugador2;
    Mazo mazo;
    Carta cartaVacia;
    Matriz campo;
    bool jugadorInicialDefinido;
public:
    CampoDeJuego();
    ~CampoDeJuego();
    //manipulacion de cartas
    void reparteCartas(int etapa);
    void reparteCartasInversa(int etapa);
    ArrayList<Carta> getManoJugador(int jugador);
    void moverCartaJugadorACampo(int numeroJugador,  int posMano,
                                 int posCampoColumn, int posCampoRow);
    void moverCartaCampoAJugador(int numeroJugador,
                                 int posCampoColumn, int posCammpoRow);
    Jugador getJugador(int jugador);

    //Evaluaciones
    int evaluaFilaHorizontal(int rowArray);
    int evaluaFilaVertical(int columnArray);
    int evaluaCampoVertical();
    int evaluaCampoHorizontal();
    bool isFull();

    //
    bool hayJugadorInicialDefinido();
    Carta getCartaRonda1Jugador(int jugador);
    bool evaluarGanadorEtapa1();

    //icono
    void ponerIcono(QPushButton boton,Carta carta);
    QIcon getIcono(int jugador, int index, int hilera=1);

    string imprimeMano(int jugador);
    string imprimeCampo();
    void manoAMazo(int jugador);
    int getSizeMazo();
    int evaluaDiferencia();


};

#endif // CAMPODEJUEGO_H

