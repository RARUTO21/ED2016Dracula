#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>

using namespace std;
template <typename E>


class ArrayList
{
private:
    E* elements;
    int max;
    int size;
    int pos;

public:
    ArrayList(int pMax= DEFAULT_MAX_SIZE){
        elements= new E[pMax];
        max= pMax;
        size = 0;
        pos= 0;
    }
    ~ArrayList(){
        /**
          Descripción: Destructor de la clase.
          **/

        delete []elements;
    }

    void insert(E pElement)throw(runtime_error){
        if (pos==size){
            throw runtime_error ("posición inválida");
        }
        if (size==max){
            throw runtime_error ("Lista llena");
        }
        for (int i=size; i>pos;i--){
            elements[i]= elements[i-1];
        }
        elements[pos+1]=pElement;
        size ++;
    }

    void append(E pElement)throw(runtime_error){
        if (size==max){
            throw runtime_error ("Lista llena");
        }
        elements[size]=pElement;
        size ++;
    }

    E remove()throw(runtime_error){
        if(size==0){
            throw runtime_error ("La lista está vacía");
        }
        E result=elements[pos];
        for(int i=pos;i<size;i++){
            elements[i]==elements[i+1];
        }
        size--;
        return result;
    }

    void clear(){
        pos=0;
        size=0;
        delete []elements;
        elements= new E[max];
    }
    E getElement()throw(runtime_error){
        if(size==0){
            throw runtime_error ("La lista está vacía");
        }
        return elements[pos];
    }

    void goToStart(){
        pos=0;
    }
    void goToEnd(){
        pos= size-1;
    }
    void goToPos(int pPos)throw(runtime_error){
        if(pPos<0 || pPos>=size){
            throw runtime_error ("Posición inválida");
        }
        pos= pPos;
    }

    void previous(){
        if(pos>0){
            pos--;
        }
    }

    void next(){
        if(pos>=size){
            pos++;
        }
    }

    int getPos(){
        return pos;
    }

    int getSize(){
        return size;
    }



};

#endif // ARRAYLIST_H
