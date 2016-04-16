#ifndef MATRIZ_H
#define MATRIZ_H
#include "carta.h"

class Matriz
{
private:
    Carta matriz[3][3];
public:
    Matriz(){}

    void setElement(int row, int column, Carta element){
            matriz[row][column] = element;
    }

    Carta popElement(int row, int column, Carta elementNull){
        Carta element = matriz[row][column];
        matriz[row][column] = elementNull;
        return element;
    }

    Carta getElement(int row, int column){
        return matriz[row][column];
    }
};

#endif // MATRIZ_H
