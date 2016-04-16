#include "juego.h"
#include "ui_juego.h"
#include "carta.h"

#include <QtCore>
#include <QtDebug>

#include "qdialog.h"

//Atributos para manejar el reloj del juego
int segundos = 0;
int minutos = 0;
int horas = 0;

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);


    //Inicialización de la variable reloj que está declarada en juego.h
    reloj = new QTimer(this);

    //Método que conecta 2 objetos, en este caso el reloj y this (el widget) con sus respectivas señales:
    //reloj: Señal = timeout() ------  this(widget): Señal = miSlot (método que recibe el timeout)

    connect(reloj,SIGNAL(timeout()),this,SLOT(correrReloj()));
    reloj->start(1000);//Aquí es donde se pone a circular el reloj con un intervalo de 1000 milisegundos
}

void Juego::correrReloj(){ //Acá se programa el método miSlot el cual es un Slot que recibe la señal "timeout()" del reloj

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


 //Descripción: Función que retorna el nombre del archivo .png donde se va a mostrar el ícono en el botón del juego
 //Entradas: Una carta de tipo Carta
 //Salidas: Un QString con el nombre del archivo que se va a utilizar para ponerle un ícono al botón

string Juego::generarPathIcono(Carta carta){

    string nombre = carta.getNombre();
    string color = carta.getColor();
    string simbolo = carta.getSimbolo();

    string filePath = ":/cards/cards/";
    if(carta.getNombre() == "joker"){
        filePath.append(nombre);
        filePath.append("_");
        filePath.append(color);
        filePath.append(".png");
    }
    else{
        filePath.append(nombre);
        filePath.append("_");
        filePath.append(simbolo);
        filePath.append(".png");
    }
    return filePath;
}

//-------------------------------------- ACCIONES DE LOS BOTONES (DON'T TOUCH THEM :) )-------------------------

void Juego::on_btnMatriz1_clicked()
{
    qDebug()<<"Boton 1 de la matriz";
    //ui->btnMatriz1->setIcon();
    qDebug() << "";//url(:/other/cards/undo.png);//qApp->applicationDirPath().remove("/build-JuegoDracula-Desktop_Qt_5_5_1_clang_64bit-Debug/JuegoDracula.app/Contents/MacOS");
}

void Juego::on_btnMatriz2_clicked()
{
    qDebug()<<"Boton 2 de la matriz";
}

void Juego::on_btnMatriz3_clicked()
{
    qDebug()<<"Boton 3 de la matriz";
}

void Juego::on_btnMatriz4_clicked()
{
    qDebug()<<"Boton 4 de la matriz";
}

void Juego::on_btnMatriz5_clicked()
{
    qDebug()<<"Boton 5 de la matriz";
}

void Juego::on_btnMatriz6_clicked()
{
    qDebug()<<"Boton 6 de la matriz";
}

void Juego::on_btnMatriz7_clicked()
{
    qDebug()<<"Boton 7 de la matriz";
}

void Juego::on_btnMatriz8_clicked()
{
    qDebug()<<"Boton 8 de la matriz";
}

void Juego::on_btnMatriz9_clicked()
{
    qDebug()<<"Boton 9 de la matriz";
}



//------------------------------------ FIN DE LAS ACCIONES DE LOS BOTONES --------------------------------------
