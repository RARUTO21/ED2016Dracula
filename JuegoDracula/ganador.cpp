#include "ganador.h"
#include "ui_ganador.h"

Ganador::Ganador(QString ganadorJugador, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ganador)
{
    ui->setupUi(this);\
    ui->label->setText(ganadorJugador);
}

Ganador::~Ganador()
{
    delete ui;
}
