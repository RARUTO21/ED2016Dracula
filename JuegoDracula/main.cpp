#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();

    Carta<string> carta("rojo","corazones","10",10);
    //cout<<carta.getColor();
    //cout<<carta.getNombre();
    //cout<<carta.getValor();
    //cout<<carta.getCarta();



   // cout<<"Hola Mundo!"<<endl;


    return a.exec();
}
