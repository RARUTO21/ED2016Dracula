#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"
#include <QTimer>
#include "jugador.h"



    using namespace std;

    int main(int argc, char *argv[])
    {
        //QApplication a(argc, argv);
        //Juego w;
        //w.show();

        Mazo miMazo;
        cout<<miMazo.getSize()<<endl;
        Carta prueba = miMazo.sacarCartaInicial();
        cout<<prueba.getSimbolo()<<endl;
        cout<<prueba.getNombre()<<endl;
        Jugador jugador;
        jugador.putCard(prueba);
        cout<<jugador.getCard(0).getNombre()<<endl;
        cout<<jugador.getCard(0).getSimbolo()<<endl;


        //return a.exec();
        return 0;
    };
