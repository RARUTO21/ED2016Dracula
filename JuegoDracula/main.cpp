#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"
#include <QTimer>


using namespace std;

/*void iniciarTiempo(){
    QTimer * reloj = new QTimer();
}*/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();



    return a.exec();
}
