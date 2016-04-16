#include "escogerjugador.h"
#include "ui_escogerjugador.h"
#include <iostream>
#include "jugador.h"
#include "mazo.h"
#include "carta.h"

Jugador jugador1;
Jugador jugador2;


Mazo mazoInicial;
Carta cartaActual;

EscogerJugador::EscogerJugador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscogerJugador)
{
    ui->setupUi(this);


}

EscogerJugador::~EscogerJugador()
{
    delete ui;
}



void EscogerJugador::on_btnMazo_clicked()
{

}
