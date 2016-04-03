#include "juego.h"
#include "ui_juego.h"

#include <QtCore>
#include <QtDebug>

//Atributos para manejar el reloj del juego
int segundos = 0;
int minutos = 10;
int horas = 10;

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);


    //Inicialización de la variable reloj que está declarada en juego.h
    reloj = new QTimer(this);

    //Método que conecta 2 objetos, en este caso el reloj y this (el widget) con sus respectivas señales:
    //reloj: Señal = timeout() ------  this(widget): Señal = miSlot (método que recibe el timeout)

    connect(reloj,SIGNAL(timeout()),this,SLOT(miSlot()));
    reloj->start(1000);//Aquí es donde se pone a circular el reloj con un intervalo de 1000 milisegundos
}

void Juego::miSlot(){ //Acá se programa el método miSlot el cual es un Slot que recibe la señal "timeout()" del reloj

    ui->lblTiempo->setFont(QFont("Arial",36));//Se define una fuente para el label del tiempo en el ui
    //Se concatena un QString con los valores horas:minutos:segundos junto con los dos puntos separadores entre sí
    ui->lblTiempo->setText(QString::number(horas)+ ":" + QString::number(minutos) + ":" + QString::number(segundos));

    //Se incrementa el valor de los segundos para cada vez que llega una señal
    segundos += 1;
    //Se validan los valores de las variables para realizar los cambios y que el valor muestre los números del tiempo
    //iguales a como se usan normalmente. 60 segundos = 1 min ; 60 min = 1 hora.
    if(segundos == 60){
        segundos = 0;
        minutos += 1;
        if(minutos == 60){
            minutos = 0;
            horas += 1;
        }
    }
}

Juego::~Juego()
{
    delete ui;
}
