#ifndef MATRIZ_H
#define MATRIZ_H
#include "carta.h"

class Matriz
{
private:
    Carta matriz[3][3]; //un array 3x3 que guardara los elementos carta
    int espaciosVacios;
public:
    Matriz(){
        espaciosVacios = 6;
    }

    void setElement(int row, int column, Carta element){
        /**
         * Entradas:
         *  row: la fila horizontal
         *  column: la fila vertical
         *  element: el elemento a introducir
         */
        matriz[row][column] = element;
        espaciosVacios--;
    }

    Carta popElement(int row, int column, Carta elementNull){
        /**
         * Descripcion:
         *  regresa y borra el elemento de acuerdo a los parametros
         * Entradas:
         *  row: la fila horizontal
         *  column: la fila vertical
         *  element: el elemento vacio a introducir cuando se elimine el resultado
         * Salida:
         *  un elemento de la matriz de acuerdo a los parametros
         */
        Carta element = matriz[row][column];
        matriz[row][column] = elementNull;
        espaciosVacios++;
        return element;
    }

    Carta getElement(int row, int column){
        /**
         * Entradas:
         *  row: la fila horizontal
         *  column: la fila vertical
         * Salida:
         *  un elemento de la matriz de acuerdo a los parametros
         */
        return matriz[row][column];
    }

    bool isFull(){
        if(espaciosVacios == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif // MATRIZ_H
