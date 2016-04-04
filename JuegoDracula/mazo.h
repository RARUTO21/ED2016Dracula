#ifndef MAZO_H
#define MAZO_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include "Carta.h"
#include "ArrayList.h"
#include <time.h>



using namespace std;

template <typename E>

class Mazo
{
private:

    ArrayList<E> Baraja; //Arreglo que guardará las cartas del naipe
    int size; //Lleva el control del tamaño del mazo.


public:

    Mazo(){
        /*
          Descripción: Constructor de la clase.

          Entradas: No tiene.

          Salidas: No tiene.
          */

        Baraja= new E[54]; //Inicialización del arreglo baraja de 54 elementos.
        size=0;
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
        crearPalo("rojo", "Oros"); //Invoca a la función que agrega las cartas del palo Oros al mazo de cartas.
        crearPalo("rojo", "Corazones"); //Invoca a la función que agrega las cartas del palo Corzaones al mazo de cartas.
        crearPalo("negro", "Bastos"); //Invoca a la función que agrega las cartas del palo Bastos al mazo de cartas.
        crearPalo("negro", "Flores"); //Invoca a la función que agrega las cartas del palo Flores al mazo de cartas.

        Carta<string> joker1("rojo","Joker","Joker rojo",0); //Crea la carta Joker de color rojo.
        Carta<string> joker2("negro","Joker","Joker negro",0); //Crea la carta Joker de color negro.


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
        Carta<string> as(pColor,pSimbolo,"As",1);
        Carta<string> dos(pColor,pSimbolo,"2",2);
        Carta<string> tres(pColor,pSimbolo,"3",3);
        Carta<string> cuatro(pColor,pSimbolo,"4",4);
        Carta<string> cinco(pColor,pSimbolo,"5",5);
        Carta<string> seis(pColor,pSimbolo,"6",6);
        Carta<string> siete(pColor,pSimbolo,"7",7);
        Carta<string> ocho(pColor,pSimbolo,"8",8);
        Carta<string> nueve(pColor,pSimbolo,"9",9);
        Carta<string> diez(pColor,pSimbolo,"10",10);
        Carta<string> j(pColor,pSimbolo,"J",0);
        Carta<string> q(pColor,pSimbolo,"Q",10);
        Carta<string> k(pColor,pSimbolo,"K",10);


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
            E temp1= Baraja[posicion1];
            E temp2= Baraja[posicion2];

            //Intercambio de los dos elementos.
            Baraja[posicion1]= temp2;
            Baraja[posicion2]= temp1;
        }
    }
    
    E sacarCartaInicial(){
        /*
         Descripción: Obtiene una carta.

         Entradas: No tiene.
         Salidas: Una carta.
         */

        srand(time(0));
        int posicion= rand()%53;
        Baraja.goToPos(posicion);
        E result= Baraja.remove();
        Baraja.goToStart();
        size--;

        return result;
        
    }

    void devolverCarta(E pCarta){
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
