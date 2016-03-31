#ifndef CARTA_H
#define CARTA_H
#include <stdio.h>
#include <stdlib.h>
 using namespace std;
template <typename E>
class Carta
{
private:
    E * carta; //Arreglo de tipo string que incluirá el color, símbolo y nombre de la carta
    int valor; //Valor numérico entero de la carta
public:
    Carta(E pColor, E pSimbolo, E pNombre, int pValor){
        /**Constructor de la clase carta
        Descripción: Inicializa la clase carta.

        Entradas:

            color: variable de tipo string que representa el color de una carta del naipe.
            símbolo: variable de tipo string que representa el símbolo de una carta del naipe.
            valor: variable de tipo string que representa el valor númerico de una cartadel naipe.

        Salidas: No tiene, solo inicializa la clase carta y los atributos.**/

        carta= new E[3]; //Se crea un arreglo de tres elementos para almacenar la información de la carta.
        carta[0]= pColor; //En la primera posición del arreglo se coloca el color.
        carta[1]= pSimbolo; //En la segunda posición del arreglo se coloca el símbolo.
        carta[2]= pNombre; //En la tercera posición se coloca el valor numérico.
        valor= pValor;
    }

    ~Carta(){
    /**Destructor de la clase carta
    Descripción: Libera la memoria genrada al usar la clase carta.

    Entradas: No tiene.
    Salidas: No tiene.**/

        delete []carta;
        valor = 0;
    }


    E getColor(){
    /**Descripción: Devuelve un string con el color de la carta.

    Entradas: No tiene.
    Salidas: Un string que indica el color de la carta, sea "negro" o "rojo".**/

    return carta[0];
    }

    E getSimbolo(){
    /**Descripción: Devuelve un string con el símbolo de la carta.

    Entradas: No tiene.
    Salidas: Un string que indica el símbolo de la carta sea "corazones", "rombos", "tréboles", "bastos".**/

    return carta[1];
    }

    E getNombre(){
    /**Descripción: Devuelve un string con el símbolo de la carta.

    Entradas: No tiene.
    Salidas: Un string que dice el nombre de la carta.**/



    return carta[2];

    }

    int getValor(){
    /**Descripción: Devuelve un int con el valor numérico de la carta.

      Entradas: No tiene.
      Salida: Un entero que representa el valor numérico de la carta.

      **/
        return valor;
    }

    void setValor(int pValor){
    /**Descripción: Cambia el valor numérico de la carta. Será utilizado
       para validar los puntajes de las cartas.

       Entrada: Un entero por el que se desea cambiar el valor actual de la carta.
       Salida: No tiene. Modifica el valor numérico de la carta.
       **/
        valor = pValor;
    }

    E getCarta(){
    /**Descripción: Devuelve un string que indica el nombre y símbolo de la carta.

       Entradas: No tiene.
       Salida: Un string que indica el nombre y símbolo de la carta.
     **/

        return getNombre()+" de "+ getSimbolo();
    }



};

#endif // CARTA_H
