#include "escogerjugador.h"
#include "ui_escogerjugador.h"
#include <iostream>
#include "campodejuego.h"

//CampoDeJuego campoJuego;


//EscogerJugador::EscogerJugador(CampoDeJuego campo, QWidget *parent) :
EscogerJugador::EscogerJugador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscogerJugador)
{
    ui->setupUi(this);


    //campoJuego = campo;

    //campo.reparteCartas(1);

    std::cout<<"hola mundo"<<endl;


    //std::cout<<"Carta del jugador1: Nombre:"<<campo.getJugador(1).getCard(0).getNombre()<< "simbolo: "<<campo.getJugador(1).getCard(0).getSimbolo()<<endl;
    //std::cout<<campo.getJugador(1).getCard(0).getNombre()<<campo.getJugador(1).getCard(0).getSimbolo()<<endl;
    //std::cout<<campo.getJugador(1).getCard(0).getNombre()<<endl;
    //std::cout<<"Carta del jugador2: Nombre:"<<campo.getJugador(1).getCard(0).getNombre()<< "simbolo: "<<campo.getJugador(1).getCard(0).getSimbolo()<<endl;
    //std::cout<<campo.getJugador(1).getCard(0).getNombre()<<campo.getJugador(2).getCard(0).getSimbolo()<<endl;
    //std::cout<<campo.getJugador(2).getCard(0).getNombre()<<endl;


    //std::cout<<campo->getJugador(1).getCard(0).getNombre()<<endl;
    //std::cout<<campoJuego.getCartaRonda1Jugador(1).getNombre()<<endl;


}

EscogerJugador::~EscogerJugador()
{
    delete ui;
}



void EscogerJugador::on_btnMazo_clicked()
{
    //std::cout<<"hola mundo"<<endl;
    //QString qs = QString::fromLocal8Bit(campoJuego.getCartaRonda1Jugador(1).getRutaImagenCarta().c_str());
    //QPixmap pix(qs);
    //QIcon icono(pix);

    //ui->btnJugador1->setIcon(campoJuego.getCartaRonda1Jugador(1).getIcono());
    //ui->btnJugador1->setIcon(QIcon(QPixmap(":/cards/cards/q_bastos.png")));//campoJuego.getCartaRonda1Jugador(1).getIcono());

}

void EscogerJugador::on_btnJugador1_clicked()
{
    QPixmap pix(":/cards/cards/9_oros.png");
    //QPixmap pix(getRutaImagenCarta());
    QIcon iconoCarta(pix);
    ui->btnJugador1->setIcon(iconoCarta);
}
