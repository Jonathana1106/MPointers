//
// Created by jonathan on 21/09/18.
//

#ifndef MPOINTERS_MPOINTERS_H
#define MPOINTERS_MPOINTERS_H

#include <iostream>

namespace mpointer {

    using namespace std;

    template<class T>
/**
 * Clase que se encarga de crear un puntero de tipo template.
 * @tparam T
 */
    class MPointer {

    private:

        /**
         * Variables de la clase.
         */

        T *ptr; // Puntero template.

        int add; // Direccion de memoria

    public:

        /**
         * Metodo que se encarga de asignar un espacio de memoria a un puntero segun su tipo.
         */
        void New() {
            ptr = (T *) malloc(sizeof(T));
        }

        /**
         * Metodo que se encarga de asignar un valor a un puntero.
         * @param ptra
         */
        void operator=(T ptra) {
            *ptr = ptra;
        }

        /**
         * Metodo que se encarga de verificar si dos punteros son del mismo tipo.
         * @param mPointer
         */
        void operator=(MPointer<T> mPointer) {
            this->ptr = mPointer.ptr;
        }

        //////////////////////////////////////////////////////////////////////////////
        /////////////////////////Caution//////////////////////////////////////////////
//    MPointer<T> operator*(MPointer<T> mPointer) {
//        return mPointer;
//          Indirection requires pointer operand ('MPointer<char>' invalid).
//    }
        //////////////////////////////////////////////////////////////////////////////

        /**
         * Metodo que se encarga de mostrar el valor de un puntero.
         * No se necesita, solo para pruebas.
         */
        void show() {
            cout << "El dato es: ";
            cout << *ptr;
            cout << "\n";
        }

        /**
         * Metodo que se encarga de devolver el valor de un puntero al usar &.
         * @return
         */
        T operator&() {
            return *ptr;
        }
    };

/////////////////////////////////////////////////////
// Aqui si funciona el muy banano.
    template<class T>
/**
 * Metodo que se encarga de devolver un puntero al utilizar *.
 * @tparam T
 * @param mPointer
 * @return
 */
    MPointer<T> operator*(MPointer<T> mPointer) {
        return mPointer;
    }

}

#endif //MPOINTERS_MPOINTERS_H