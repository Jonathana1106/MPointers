//
// Created by elias on 24/09/18.
//

#ifndef MPOINTERS_MPOINTERGC_H
#define MPOINTERS_MPOINTERGC_H

#include <tgmath.h>
#include "MPointer.h"
#include "../Estrutures/Simple_list.h"

template <class T>
class MPointerGC {

private:
    mpointer::MPointer<T> addres;
    int ID;
    bool counter_check(int id);
    Simple_list<T> simple_list;

    /*
     * Inicializar con singleton
     * */
    static MPointerGC<T>* instance;
    MPointerGC();

public:
    int generate_ID(mpointer::MPointer<T>);
    bool free_mpointer(int id, mpointer::MPointer<T>);
    int add_count(int id);
    int show_list();

    static MPointerGC<T>* getInstance();
};
template<class T>
MPointerGC<T>* MPointerGC<T>::instance = 0;

template<class T>
int MPointerGC<T>::generate_ID(mpointer::MPointer<T> mPointer) {

    ID = rand() % 100000;
    std::cout << ID << " ID " << std::endl;
    //crear el nodo, asignar el id y la direccion de memoria
    Node_s<T> node_s;
    node_s.ID = ID;
    node_s.mPointer = mPointer.mPointer1;
    node_s.counter = 0;
    mPointer.save_ID(ID);
    simple_list.insert(&node_s);
    simple_list.print_list();

    return ID;
}

template<class T>
bool MPointerGC<T>::counter_check(int id) {
    //ask if the
    return false;
}

template<class T>
bool MPointerGC<T>::free_mpointer(int id, mpointer::MPointer<T> mPointer) {
    // Si las referencias son mas de cero
    //Retorna falso
    if (counter_check(id)){
        return false;
    }
    //delete node of list
    mPointer.~MPointer();
    return true;
}

template<class T>
int MPointerGC<T>::add_count(int id) {
    //buscar nodo con el id
    //sumar conteo de referencias
    return 0;
}

template<class T>
MPointerGC<T>::MPointerGC() {

}

template<class T>
MPointerGC<T> *MPointerGC<T>::getInstance() {
    if(instance == 0){
        instance = new MPointerGC();
    }
    return instance;
}

template<class T>
int MPointerGC<T>::show_list() {
    simple_list.print_list();
    return 0;
}


#endif //MPOINTERS_MPOINTERGC_H
