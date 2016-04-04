#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"
#include <QTimer>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();

    //Mazo<Carta> miMazo;// = new Mazo();

    //miMazo.crearBaraja();

    //cout<<miMazo.getSize();



    return a.exec();
}
