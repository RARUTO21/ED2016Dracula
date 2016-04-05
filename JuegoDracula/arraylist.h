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
        ArrayList(int pMax = DEFAULT_MAX_SIZE){
            elements = new E[pMax];
            max = pMax;
            size = 0;
            pos = 0;
        }

        ~ArrayList(){
            delete[]elements;
        }

        void insert(E pElement) throw (runtime_error){
            int i = 0;
            if(size == max){
                throw runtime_error ("La lista ya esta llena");
            }

            for(i = size; i > pos; i--){
                elements[i] = elements[i-1];
            }

            elements[i] = pElement;
            size++;

        }

        void append(E pElement)throw(runtime_error){
            if(size == max){
                throw runtime_error ("La lista ya esta llena");
            }

            elements[size] = pElement;
            size++;
        }

        E remove()throw(runtime_error){
            if (size == 0){
                throw runtime_error ("La lista esta vacia");
            }
            if(pos >= size){
                throw runtime_error ("No esta el elemento");
            }

            E result = elements[pos];

            for(int i = pos; i < size-1; i++){
                elements[i] = elements[i+1];
            }
            size--;
            return result;
        }

        void clear(){
            size = 0;
            pos = 0;
        }

        E getElement()throw(runtime_error){
            if (size == 0){
                throw runtime_error ("La lista esta vacia");
            }
            if(pos > size){
                throw runtime_error ("No esta el elemento");
            }
            return elements[pos];
        }

        void goToStart(){
            pos = 0;
        }

        void goToEnd(){
            pos = size;
        }

        void goToPos(int pPos)throw(runtime_error){
            if (pPos >= 0 && pPos <= max){
                pos = pPos;
            }else{
                throw runtime_error("Esa posicion esta fuera de los parametros");
            }
        }

        void previous()throw(runtime_error){
            if (pos == 0){
                throw runtime_error("Esa posicion esta fuera de los parametros");
            }
            pos--;
        }

        void next(){
            if (pos == max){
                throw runtime_error("Esa posicion esta fuera de los parametros");
            }
            pos++;
        }

        int getPos(){
            return pos;
        }

        int getSize(){
            return size;
        }


};

#endif // ARRAYLIST_H
