#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>

#include <QtCore>


namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = 0);

    QTimer * reloj; //Variable de tipo QTimer que se va a utilizar para correr el tiempo

    ~Juego();


public slots: //Método que se puede utilizar para conectar con otro objeto y recibir señales.
              //Como un contenedor de señales programable :)
    void miSlot();

private:
    Ui::Juego *ui;

};

#endif // JUEGO_H
