#include "escogerjugador.h"
#include "ui_escogerjugador.h"

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
