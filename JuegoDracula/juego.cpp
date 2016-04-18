#include "juego.h"
#include "ui_juego.h"
#include "carta.h"
#include "ganador.h"
#include <QtCore>
#include <QtDebug>

#include "qdialog.h"
#include <iostream>
using namespace std;

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
    rondaActual = 0;
    puntuacionJugador1 = 0;
    puntuacionJugador2 = 0;

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

void Juego::bloquearBotones(QPushButton *boton){
    /**
     * Descripcion: dehabilita espacios los dos jugadores
     * Entrada:
     *  QPushButton boton: el boton que dejar habilitado
     * Salida:
     *  desabilita los botones correspondientes de las manos
     */
    ui->btnCarta1Jugador1->setEnabled(false);
    ui->btnCarta2Jugador1->setEnabled(false);
    ui->btnCarta3Jugador1->setEnabled(false);
    ui->btnCarta4Jugador1->setEnabled(false);
    ui->btnCarta1Jugador2->setEnabled(false);
    ui->btnCarta2Jugador2->setEnabled(false);
    ui->btnCarta3Jugador2->setEnabled(false);
    ui->btnCarta4Jugador2->setEnabled(false);

    boton->setEnabled(true);
}

void Juego::deshabilitarEspacios(int jugadorJugandoActualmente){
    /**
     * Descripcion: dehabilita espacios de el jugador anterior
     * Entrada:
     *  int jugadorJugandoActualmente jugador actual/anterior
     * Salida:
     *  desabilita los botones correspondientes de la mano
     */
    if(jugadorJugandoActualmente == 2){
        ui->btnCarta1Jugador2->setEnabled(false);
        ui->btnCarta2Jugador2->setEnabled(false);
        ui->btnCarta3Jugador2->setEnabled(false);
        ui->btnCarta4Jugador2->setEnabled(false);
    }
    else if(jugadorJugandoActualmente == 1){
        ui->btnCarta1Jugador1->setEnabled(false);
        ui->btnCarta2Jugador1->setEnabled(false);
        ui->btnCarta3Jugador1->setEnabled(false);
        ui->btnCarta4Jugador1->setEnabled(false);
    }
}


void Juego::evaluaCampo(){
    /**
     * Descripcion: Metodo que evalua el campo y actualiza las labels de las puntuaciones
     */

    // columnas, Columns, vertical

    int resultadoColumna1 = campo.evaluaFilaVertical(0);
    ui->lblScoreColumn0->setText(QString::number(resultadoColumna1));
    ui->lblScoreColumn0->setStyleSheet("QLabel { background-color : black; color : white; }");


    int resultadoColumna2 = campo.evaluaFilaVertical(1);
    ui->lblScoreColumn1->setText(QString::number(resultadoColumna2));
    ui->lblScoreColumn1->setStyleSheet("QLabel { background-color : black; color : white; }");

    int resultadoColumna3 = campo.evaluaFilaVertical(2);
    ui->lblScoreColumn2->setText(QString::number(resultadoColumna3));
    ui->lblScoreColumn2->setStyleSheet("QLabel { background-color : black; color : white; }");

    // hileras, row, horizontales

    int resultadoHilera1 = campo.evaluaFilaHorizontal(0);
    ui->lblScoreRow0->setText(QString::number(resultadoHilera1));
    ui->lblScoreRow0->setStyleSheet("QLabel { background-color : black; color : white; }");

    int resultadoHilera2 = campo.evaluaFilaHorizontal(1);
    ui->lblScoreRow1->setText(QString::number(resultadoHilera2));
    ui->lblScoreRow1->setStyleSheet("QLabel { background-color : black; color : white; }");

    int resultadoHilera3 = campo.evaluaFilaHorizontal(2);
    ui->lblScoreRow2->setText(QString::number(resultadoHilera3));
    ui->lblScoreRow2->setStyleSheet("QLabel { background-color : black; color : white; }");


    //Apartir de aqui se calculan las puntuaciones
    int resultadoColumnas;
    int resultadoHileras;


    int arrayHilerasPuntuacion[3] = {resultadoHilera1, resultadoHilera2, resultadoHilera3};

    //Algoritmo de ordenacion bubblesort para ordenar el puntaje arrayHilerasPuntuacion
    for(int e =0; e<3; e++){
        for(int i =0; i<2; i++){
            if(arrayHilerasPuntuacion[i]>arrayHilerasPuntuacion[i+1]){
                int temp = arrayHilerasPuntuacion[i+1];
                arrayHilerasPuntuacion[i+1] = arrayHilerasPuntuacion[i];
                arrayHilerasPuntuacion[i] = temp;
            }
        }
    }

    int arrayColumnasPuntuacion[3] = {resultadoColumna1, resultadoColumna2, resultadoColumna3};

    //Algoritmo de ordenacion bubblesort para ordenar el puntaje arrayColumnasPuntuacion
    for(int e =0; e<3; e++){
        for(int i =0; i<2; i++){
            if(arrayColumnasPuntuacion[i]>arrayColumnasPuntuacion[i+1]){
                int temp = arrayColumnasPuntuacion[i+1];
                arrayColumnasPuntuacion[i+1] = arrayColumnasPuntuacion[i];
                arrayColumnasPuntuacion[i] = temp;
            }
        }
    }

    // Compara las puntuaciones para ver si son iguales para pasar a las siguientes menores
    resultadoColumnas = arrayColumnasPuntuacion[2];
    resultadoHileras = arrayHilerasPuntuacion[2];

    if(resultadoColumnas == resultadoHileras){
        resultadoColumnas = arrayColumnasPuntuacion[1];
        resultadoHileras = arrayHilerasPuntuacion[1];
        if(resultadoColumnas == resultadoHileras){
            resultadoColumnas = arrayColumnasPuntuacion[0];
            resultadoHileras = arrayHilerasPuntuacion[0];
        }
    }

    // Calcula la puntuacion extra y la agrega a su respectivo ganador
    int diferencia;
    if(resultadoColumnas > resultadoHileras){
        diferencia = resultadoColumnas - resultadoHileras;
        resultadoColumnas += diferencia;
    }
    else if(resultadoColumnas < resultadoHileras){
        diferencia = resultadoHileras - resultadoColumnas;
        resultadoHileras += diferencia;
    }
    else{
        diferencia = 0;
    }


    // Actualizar labels de la interfaz
    if(rondaActual == 1){
        ui->lblPuntuacionJugador1ronda1->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda1->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda1->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda1->setStyleSheet("QLabel { background-color : black; color : white; }");

    }
    else if(rondaActual == 2){
        ui->lblPuntuacionJugador1ronda2->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda2->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda2->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda2->setStyleSheet("QLabel { background-color : black; color : white; }");
    }
    else if(rondaActual == 3){
        ui->lblPuntuacionJugador1ronda3->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda3->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda3->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda3->setStyleSheet("QLabel { background-color : black; color : white; }");
    }
    else if(rondaActual == 4){
        ui->lblPuntuacionJugador1ronda4->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda4->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda4->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda4->setStyleSheet("QLabel { background-color : black; color : white; }");
    }
    else if(rondaActual == 5){
        ui->lblPuntuacionJugador1ronda5->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda5->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda5->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda5->setStyleSheet("QLabel { background-color : black; color : white; }");
    }
    else if(rondaActual == 6){
        ui->lblPuntuacionJugador1ronda6->setText(QString::number(resultadoColumnas));
        ui->lblPuntuacionJugador2ronda6->setText(QString::number(resultadoHileras));
        ui->lblPuntuacionJugador1ronda6->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->lblPuntuacionJugador2ronda6->setStyleSheet("QLabel { background-color : black; color : white; }");
    }

    //se agrega la puntuacion final a las puntucaciones de cada jugador
    puntuacionJugador1+=resultadoHileras;
    puntuacionJugador2+=resultadoColumnas;

    ui->lblPuntuacionTotalJugador1->setText(QString::number(puntuacionJugador1));
    ui->lblPuntuacionTotalJugador2->setText(QString::number(puntuacionJugador2));
    ui->lblPuntuacionTotalJugador1->setStyleSheet("QLabel { background-color : black; color : white; }");
    ui->lblPuntuacionTotalJugador2->setStyleSheet("QLabel { background-color : black; color : white; }");

    if(rondaActual == 6){
        if(puntuacionJugador1>puntuacionJugador2){
            Ganador ventana("Felicidades jugador 1 ganaste!!");
            ventana.exec();
        }
        else if(puntuacionJugador1<puntuacionJugador2){
            Ganador ventana("Felicidades jugador 2 ganaste!!");
            ventana.exec();
        }
        else{
            Ganador ventana("Empate");
            ventana.exec();
        }
    }
    ui->btnEvalua->setEnabled(false);
}


void Juego::desbloquearBotonesJugador(int jugador){
    /**
     * Descripción: Habilita los botones del jugador elegido
     * Precondiciones: El parámetro debe ser un número entero entre 1-2
     * Poscondiciones: Sin definir.
     * */
    if(jugador == 1){

        ui->btnCarta1Jugador1->setEnabled(true);
        ui->btnCarta2Jugador1->setEnabled(true);
        ui->btnCarta3Jugador1->setEnabled(true);
        ui->btnCarta4Jugador1->setEnabled(true);

    }
    else{
        ui->btnCarta1Jugador2->setEnabled(true);
        ui->btnCarta2Jugador2->setEnabled(true);
        ui->btnCarta3Jugador2->setEnabled(true);
        ui->btnCarta4Jugador2->setEnabled(true);
    }
}



void Juego::ponerImagenCartasMano(int jugador){
    if(jugador == 1){

        ui->btnCarta1Jugador1->setIcon(campo.getIcono(1, 0));
        ui->btnCarta2Jugador1->setIcon(campo.getIcono(1, 1));
        ui->btnCarta3Jugador1->setIcon(campo.getIcono(1, 2));
        ui->btnCarta4Jugador1->setIcon(campo.getIcono(1, 3));
    }
    else{
        ui->btnCarta1Jugador2->setIcon(campo.getIcono(2, 0));
        ui->btnCarta2Jugador2->setIcon(campo.getIcono(2, 1));
        ui->btnCarta3Jugador2->setIcon(campo.getIcono(2, 2));
        ui->btnCarta4Jugador2->setIcon(campo.getIcono(2, 3));
    }
}


void Juego::habilitarEspaciosIniciales(){

    ui->btnMatriz2->setEnabled(true);
    ui->btnMatriz2->setIcon(QIcon(QPixmap(":cards/cards/ok.png")));
    ui->btnMatriz4->setEnabled(true);
    ui->btnMatriz4->setIcon(QIcon(QPixmap(":cards/cards/ok.png")));
    ui->btnMatriz6->setEnabled(true);
    ui->btnMatriz6->setIcon(QIcon(QPixmap(":cards/cards/ok.png")));
    ui->btnMatriz8->setEnabled(true);
    ui->btnMatriz8->setIcon(QIcon(QPixmap(":cards/cards/ok.png")));

    ui->btnMatriz1->setEnabled(false);
    ui->btnMatriz1->setIcon(QIcon(QPixmap(":cards/cards/no.png")));
    ui->btnMatriz3->setEnabled(false);
    ui->btnMatriz3->setIcon(QIcon(QPixmap(":cards/cards/no.png")));
    ui->btnMatriz7->setEnabled(false);
    ui->btnMatriz7->setIcon(QIcon(QPixmap(":cards/cards/no.png")));
    ui->btnMatriz9->setEnabled(false);
    ui->btnMatriz9->setIcon(QIcon(QPixmap(":cards/cards/no.png")));
}


void Juego::on_btnMazo_clicked()
{
    if(campo.getSizeMazo() > 0){
        campo.reparteCartas(2);
    }


    cout<<"----------------empieza campo de juego tests -----------------"<<endl;
    cout<<"mano 1: \n" +campo.imprimeMano(1)<<endl;
    cout<<"mano 2: \n" + campo.imprimeMano(2)<<endl;
    //cout<<campo.imprimeCampo()<<endl;
    cout<<"----------------termina campo de juego -----------------"<<endl;

    //ui->btnCarta1Jugador1->setIcon(campo.getIcono(1,0));
    //campo.getManoJugador(1).goToPos(0);


    //std::cout<<campo.imprimeMano(1)<<endl;
    //std::cout<<campo.imprimeMano(2)<<endl;

    ponerImagenCartasMano(1);
    ponerImagenCartasMano(2);

    habilitarEspaciosIniciales();

    ui->btnMatriz5->setIcon(campo.getIcono(3,1,1));

    std::cout<<"El mazo tiene "<<campo.getSizeMazo()<<endl;
    rondaActual++;
    //ui->btnMazo->setEnabled(false);

}


void Juego::on_btnCarta1Jugador1_clicked()
{
    cartaActual = 0;
    jugadorActual = 1;
    bloquearBotones(ui->btnCarta1Jugador1);
}

void Juego::on_btnCarta2Jugador1_clicked()
{
    cartaActual = 1;
    jugadorActual = 1;
    bloquearBotones(ui->btnCarta2Jugador1);
}

void Juego::on_btnCarta3Jugador1_clicked()
{
    cartaActual = 2;
    jugadorActual = 1;
    bloquearBotones(ui->btnCarta3Jugador1);
}

void Juego::on_btnCarta4Jugador1_clicked()
{
    cartaActual = 3;
    jugadorActual = 1;
    bloquearBotones(ui->btnCarta4Jugador1);
}

void Juego::on_btnCarta1Jugador2_clicked()
{
    cartaActual = 0;
    jugadorActual = 2;
    bloquearBotones(ui->btnCarta1Jugador2);
}

void Juego::on_btnCarta2Jugador2_clicked()
{
    cartaActual = 1;
    jugadorActual = 2;
    bloquearBotones(ui->btnCarta2Jugador2);
}

void Juego::on_btnCarta3Jugador2_clicked()
{
    cartaActual = 2;
    jugadorActual = 2;
    bloquearBotones(ui->btnCarta3Jugador2);
    //ui->btnCarta3Jugador2->setVisible(false);
}

void Juego::on_btnCarta4Jugador2_clicked()
{
    cartaActual = 3;
    jugadorActual = 2;
    bloquearBotones(ui->btnCarta4Jugador2);
}

//------------------------------------ FIN DE LAS ACCIONES DE LOS BOTONES --------------------------------------


//                                     Botones de la matriz: tienen un patron determinado
void Juego::on_btnMatriz1_clicked()
{
    ui->btnMatriz1->setIcon(campo.getIcono(jugadorActual,cartaActual,1)); // actualiza el icono de la carta
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,0,0);   // mueve la carta en la parte logica para evaluacion
    ponerImagenCartasMano(jugadorActual);   //actualiza iconos
    desbloquearBotonesJugador(1);   //desbloquea botones
    desbloquearBotonesJugador(2);

    if(campo.isFull()){             // si el campo esta lleno se habilita el boton de evaluar puntuaciones/campo
        ui->btnEvalua->setEnabled(true);
    }

    ui->btnMatriz1->setEnabled(false);  // se habilita el boton de la matriz correspondiente
    deshabilitarEspacios(jugadorActual);// deshabilita botones del el jugador actual para el siguiente turno

}

void Juego::on_btnMatriz2_clicked()
{
    ui->btnMatriz2->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,1,0);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }

    //habilitarEspaciosDisponibles();

    if(campo.estaDisponible(0,0) == true){
        ui->btnMatriz1->setEnabled(true);
    }
    if(campo.estaDisponible(0,2) == true){
        ui->btnMatriz3->setEnabled(true);
    }

    ui->btnMatriz2->setEnabled(false);
    deshabilitarEspacios(jugadorActual);
}

void Juego::on_btnMatriz3_clicked()
{
    ui->btnMatriz3->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,2,0);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }

    ui->btnMatriz3->setEnabled(false);
    deshabilitarEspacios(jugadorActual);
}

void Juego::on_btnMatriz4_clicked()
{
    ui->btnMatriz4->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,0,1);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }


    //habilitarEspaciosDisponibles();
    if(campo.estaDisponible(0,0) == true){
        ui->btnMatriz1->setEnabled(true);
    }
    if(campo.estaDisponible(2,0) == true){
        ui->btnMatriz7->setEnabled(true);
    }

    ui->btnMatriz4->setEnabled(false);
    deshabilitarEspacios(jugadorActual);

}

void Juego::on_btnMatriz6_clicked()
{
    ui->btnMatriz6->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,2,1);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }


    //habilitarEspaciosDisponibles();
    if(campo.estaDisponible(0,2) == true){
        ui->btnMatriz3->setEnabled(true);
    }
    if(campo.estaDisponible(2,2) == true){
        ui->btnMatriz9->setEnabled(true);
    }

    ui->btnMatriz6->setEnabled(false);
    deshabilitarEspacios(jugadorActual);

}

void Juego::on_btnMatriz7_clicked()
{
    ui->btnMatriz7->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,0,2);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }


    ui->btnMatriz7->setEnabled(false);
    deshabilitarEspacios(jugadorActual);

}

void Juego::on_btnMatriz8_clicked()
{
    ui->btnMatriz8->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,1,2);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }

    //habilitarEspaciosDisponibles();
    if(campo.estaDisponible(2,0) == true){
        ui->btnMatriz7->setEnabled(true);
    }
    if(campo.estaDisponible(2,2) == true){
        ui->btnMatriz9->setEnabled(true);
    }

    ui->btnMatriz8->setEnabled(false);
    deshabilitarEspacios(jugadorActual);

}


void Juego::on_btnMatriz9_clicked()
{
    ui->btnMatriz9->setIcon(campo.getIcono(jugadorActual,cartaActual,1));
    campo.moverCartaJugadorACampo(jugadorActual,cartaActual,2,2);
    ponerImagenCartasMano(jugadorActual);
    desbloquearBotonesJugador(1);
    desbloquearBotonesJugador(2);

    if(campo.isFull()){
        ui->btnEvalua->setEnabled(true);
    }


    ui->btnMatriz9->setEnabled(false);
    deshabilitarEspacios(jugadorActual);

}


void Juego::on_ImprimeConsola_clicked()
{
    cout<<"----------------empieza campo de juego tests -----------------"<<endl;
    cout<<"mano 1: \n" +campo.imprimeMano(1)<<endl;
    cout<<"mano 2: \n" + campo.imprimeMano(2)<<endl;
    cout<<campo.imprimeCampo()<<endl;
    cout<<campo.isFull()<<endl;
    cout<<"----------------termina campo de juego -----------------"<<endl;
}




void Juego::on_btnEvalua_clicked()
{
    evaluaCampo();
    ui->btnMazo->setEnabled(true);
}
