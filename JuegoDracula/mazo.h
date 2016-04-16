#ifndef MAZO_H
#define MAZO_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include "carta.h"
#include "arraylist.h"
#include <time.h>



using namespace std;

class Mazo
{
private:

    ArrayList<Carta> Baraja; //Arreglo que guardará las cartas del naipe
    int size; //Lleva el control del tamaño del mazo.


public:
    Mazo(): Baraja()
    {
        /*
          Descripción: Constructor de la clase.

          Entradas: No tiene.

          Salidas: No tiene.
          */
        //Baraja = new ArrayList<Carta>(54); //Inicialización del arreglo baraja de 54 elementos.
        size = 0;
        crearBaraja(); //Llamado a la función que agregará las cartas a la baraja.
        revolver(); //Llamado  la función que revuelve los elementos de la baraja.


    }

    ~Mazo(){
        /*
          Descripción: Destructor de la clase.
          */
        Baraja.clear();

    }
    void crearBaraja(){
        /*
         Descripción: Agrega 54 elementos de tipo carta para simular un naipe.

         Entradas: No tiene.
         Salidas: No tiene.
         */
        crearPalo("rojo", "oros"); //Invoca a la función que agrega las cartas del palo Oros al mazo de cartas.
        crearPalo("rojo", "corazones"); //Invoca a la función que agrega las cartas del palo Corzaones al mazo de cartas.
        crearPalo("negro", "bastos"); //Invoca a la función que agrega las cartas del palo Bastos al mazo de cartas.
        crearPalo("negro", "flores"); //Invoca a la función que agrega las cartas del palo Flores al mazo de cartas.

        Carta joker1("rojo","","joker",0); //Crea la carta Joker de color rojo.
        Carta joker2("negro","","joker",0); //Crea la carta Joker de color negro.


        //Añade las cartas Joker al mazo.
        Baraja.append(joker1);
        Baraja.append(joker2);

        size = 54;

    }

    void crearPalo(string pColor, string pSimbolo){
        /*
         Descripción: Crea el palo de un símbolo y lo añade al mazo.

         Entradas: String para indicar el color del palo, string para indicar el símbolo del palo.

         Salidas: No tiene.
         */

        //Este bloque crea las cartas de un palo, desde As hasta la K
        Carta as(pColor,pSimbolo,"As",1);
        Carta dos(pColor,pSimbolo,"2",2);
        Carta tres(pColor,pSimbolo,"3",3);
        Carta cuatro(pColor,pSimbolo,"4",4);
        Carta cinco(pColor,pSimbolo,"5",5);
        Carta seis(pColor,pSimbolo,"6",6);
        Carta siete(pColor,pSimbolo,"7",7);
        Carta ocho(pColor,pSimbolo,"8",8);
        Carta nueve(pColor,pSimbolo,"9",9);
        Carta diez(pColor,pSimbolo,"10",10);
        Carta j(pColor,pSimbolo,"j",0);
        Carta q(pColor,pSimbolo,"q",10);
        Carta k(pColor,pSimbolo,"k",10);


        //Las cartas creadas son añadidas al mazo.
        Baraja.append(as);
        Baraja.append(dos);
        Baraja.append(tres);
        Baraja.append(cuatro);
        Baraja.append(cinco);
        Baraja.append(seis);
        Baraja.append(siete);
        Baraja.append(ocho);
        Baraja.append(nueve);
        Baraja.append(diez);
        Baraja.append(j);
        Baraja.append(q);
        Baraja.append(k);

    }

    void revolver(){
        /*
         Descripción: Revuelve las cartas del mazo.

         Entradas: No tiene.
         Salidas: No tiene.
         */

        srand(time(0)); //inicializa el random de acuerdo al tiempo en cero.

        //Ciclo que intercambia cartas hasta que se hayan realizado 27 mezclas.
        for(int mezclas= 27; mezclas>0; mezclas--){

            //variables para obtener dos posiciones aleatorias en el mazo
            int posicion1= rand()%53;
            int posicion2= rand()%53;

            /*Variables temporales para guardar los elementos que se encuentran en las posiciones
            obtenidas anteriormente
            */
            Baraja.goToPos(posicion1);
            Carta temp1= Baraja.getElement();
            Baraja.goToPos(posicion2);
            Carta temp2= Baraja.getElement();

            //Intercambio de los dos elementos.
            Baraja.goToPos(posicion2);
            Baraja.insert(temp1);
            Baraja.goToPos(posicion1);
            Baraja.insert(temp2);
        }
    }
    
    Carta sacarCarta(){
        /*
         Descripción: Obtiene una carta.

         Entradas: No tiene.
         Salidas: Una carta.
         */

        srand(time(0));
        int posicion= rand()%53;
        Baraja.goToPos(posicion);
        Carta result= Baraja.remove();
        Baraja.goToStart();
        size--;

        return result;
        
    }

    void devolverCarta(Carta pCarta){
        /*
         Descripción: Devuelve una carta al mazo, la añade al final del mazo.

         Entradas: un elemento de tipo carta.
         Salidas: No tiene.
         */

        Baraja.append(pCarta);
        size++;
    }

    int getSize(){
        return size;
    }
    

};

#endif // MAZO_H
