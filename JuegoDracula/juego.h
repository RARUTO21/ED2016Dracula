#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include "carta.h"
#include "qpushbutton.h"
#include <QtCore>
#include "campodejuego.h"


namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = 0);

    QTimer * reloj; //Variable de tipo QTimer que se va a utilizar para correr el tiempo

    void bloquearBotones(QPushButton *boton);
    string generarPathIcono(Carta carta);

    void evaluaCampo();
    ~Juego();

public slots: //Método que se puede utilizar para conectar con otro objeto y recibir señales.
              //Como un contenedor de señales programable :)
    void correrReloj();




private slots:

    void on_btnMazo_clicked();

    void on_btnCarta1Jugador1_clicked();

    void on_btnCarta2Jugador1_clicked();

    void on_btnCarta3Jugador1_clicked();

    void on_btnCarta4Jugador1_clicked();

    void on_btnCarta1Jugador2_clicked();

    void on_btnCarta2Jugador2_clicked();

    void on_btnCarta3Jugador2_clicked();

    void on_btnCarta4Jugador2_clicked();

private:
    Ui::Juego *ui;
    CampoDeJuego campo;
    int cartaActual;
    int jugadorActual;

};

#endif // JUEGO_H
