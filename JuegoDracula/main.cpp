#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"
#include <QTimer>
#include "jugador.h"
#include "escogerjugador.h"
#include "escogerdireccion.h"
#include "matriz.h"

#include "campodejuego.h"

using namespace std;

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);

        CampoDeJuego campo;
        //campo.reparteCartas(1);

        //std::cout<<campo.getCartaRonda1Jugador(1).getNombre()<<endl;

        EscogerJugador pantallaInicio(campo);
        pantallaInicio.exec();

        EscogerDireccion pantallaDireccion;
        pantallaDireccion.exec();

        Juego w;
        w.show();


        /*
        cout<<"----------------empieza campo de juego tests -----------------"<<endl;
        CampoDeJuego campo;
        campo.reparteCartas(2);
        cout<<"mano 1: \n" +campo.imprimeMano(1)<<endl;
        cout<<"mano 2: \n" + campo.imprimeMano(2)<<endl;
        cout<<campo.imprimeCampo()<<endl;
        cout<<"----------------termina campo de juego -----------------"<<endl;

        cout<<"----------------Pruebas de mover de mano a campo -----------------"<<endl;
        campo.moverCartaJugadorACampo(1,0,1,0);
        campo.moverCartaJugadorACampo(2,0,0,1);
        campo.moverCartaJugadorACampo(1,0,2,1);
        campo.moverCartaJugadorACampo(2,0,0,2);
        campo.moverCartaJugadorACampo(1,0,1,2);
        campo.moverCartaJugadorACampo(2,0,2,0);
        campo.moverCartaJugadorACampo(1,0,0,0);
        campo.moverCartaJugadorACampo(2,0,2,2);

        cout<<"mano 1: \n" +campo.imprimeMano(1)<<endl;
        cout<<"mano 2: \n" + campo.imprimeMano(2)<<endl;
        cout<<campo.imprimeCampo()<<endl;

        cout<<"puntuacion fila horizontal 0: "<<to_string(campo.evaluaFilaHorizontal(0))<<endl;
        cout<<"puntuacion fila horizontal 1: "<<to_string(campo.evaluaFilaHorizontal(1))<<endl;
        cout<<"puntuacion fila horizontal 2: "<<to_string(campo.evaluaFilaHorizontal(2))<<endl;
        cout<<"----------------Pruebas de mover de mano a campo -----------------"<<endl;

        Mazo miMazo;
        Jugador jugador;

        cout<<miMazo.getSize()<<endl;
        Carta prueba = miMazo.sacarCarta();
        cout<<prueba.getSimbolo()<<endl;
        cout<<prueba.getNombre()<<endl;

        jugador.putCard(prueba);


        Matriz matrizT;
        matrizT.setElement(0, 0, prueba);
        cout<<matrizT.getElement(0,0).getColor()<<endl;
        cout<<"prueba"<<endl;

        //cout<<"La ruta de la carta es: "<<prueba.getRutaImagenCarta()<<endl;
        prueba.getIcono();


        cout<<jugador.getCard(0).getColor()<<endl;
        */
        return a.exec();
        //return 0;
    }
