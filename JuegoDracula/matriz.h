#ifndef MATRIZ_H
#define MATRIZ_H
#include "carta.h"

class Matriz
{
private:
    Carta **matriz;
public:
    Matriz(){
        matriz = new Carta*[3]; // 3 columnas
        for (int rowArray = 0; rowArray < 3; rowArray++){
            matriz[rowArray] = new Carta[3];
            // hace los arrays de las hileras
        }
    }
/*
    ~Matriz(){
        for(int rowArray = 0; rowArray< 3; rowArray++){
            delete[] matriz[rowArray];
            //Borra todos los sub arrays que son las hileras
        }
        delete[] matriz;
    }
*/
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
