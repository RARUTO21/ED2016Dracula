#include "escogerdireccion.h"
#include "ui_escogerdireccion.h"


EscogerDireccion::EscogerDireccion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscogerDireccion)
{
    ui->setupUi(this);
}

EscogerDireccion::~EscogerDireccion()
{
    delete ui;
}
