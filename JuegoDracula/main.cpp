#include "juego.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();
    cout<<"Hola mundo";
    return a.exec();
}
