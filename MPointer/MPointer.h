//
// Created by jonathan on 23/09/18.
//

#ifndef MPOINTERS_MPOINTER_H
#define MPOINTERS_MPOINTER_H

#include <cstdlib>
#include <iostream>

namespace mpointer {
/*
    template<class T>
    class MPointerGC;
*/
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



    public:

        int ID; // Id dado por MPointerGC
        T *ptr; // Puntero template.
        MPointer<T> *mPointer1; // Puntero a la instancia.

        /**
         * Metodo que se encarga de asignar un espacio de memoria a un puntero segun su tipo.
         */
        MPointer<T> New();


        /**
         * Metodo que se encarga de asignar un valor a un puntero.
         * @param ptra
         */
        void operator=(T ptra);

        /**
         * Metodo que se encarga de verificar si dos punteros son del mismo tipo.
         * @param mPointer
         */
        void operator=(MPointer<T> mPointer);

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
        void show();

        /**
         * Metodo que se encarga de devolver el valor de un puntero al usar &.
         * @return
         */
        T operator&();

        /**
         * Obtener dirección de memoria del dato almacenado
         * */
        /*
         * Guardar ID generado en el Mpointer
         * */
        void save_ID(int ID_GC);
        T *get_addres();

        /*
         * Método destrcutor de la clase MPointer
         * */
        //~MPointer(){std::cout << "mpointer deleted" << std::endl;};

        //MPointer<T> operator*(MPointer<T> mPointer);
    };



/////////////////////////////////////////////////////
/**
 * Metodo que se encarga de devolver un puntero al utilizar *.
 * @tparam T
 * @param mPointer
 * @return
 */

    template<class T>
    MPointer<T> operator*(MPointer<T> mPointer) {
        std::cout << mPointer.mPointer1 << " mpointerrr*" << "\n";
        return mPointer;

    }

}


#endif //MPOINTERS_MPOINTER_H
