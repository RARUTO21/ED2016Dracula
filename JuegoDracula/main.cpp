#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"
#include <QTimer>
#include "jugador.h"
#include "escogerjugador.h"
#include "escogerdireccion.h"


    using namespace std;

    int main(int argc, char *argv[])
    {

        QApplication a(argc, argv);

        EscogerJugador pantallaInicio;
        pantallaInicio.exec();

        EscogerDireccion pantallaDireccion;
        pantallaDireccion.exec();

        Juego w;
        w.show();


        Mazo miMazo;
        cout<<miMazo.getSize()<<endl;
        Carta prueba = miMazo.sacarCarta();
        cout<<prueba.getSimbolo()<<endl;
        cout<<prueba.getNombre()<<endl;
        Jugador jugador;
        jugador.putCard(prueba);
        cout<<jugador.getCard(0).getNombre()<<endl;
        cout<<jugador.getCard(0).getSimbolo()<<endl;
        cout<<jugador.getSizeMano()<<endl;

        Juego dracula;

        cout<<"La ruta de la carta es: "<<dracula.generarPathIcono(prueba)<<endl;


        return a.exec();
        //return 0;
    }
