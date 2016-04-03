#include "juego.h"
#include <QApplication>
#include <iostream>
#include "carta.h"
#include "mazo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();



    return a.exec();
}
