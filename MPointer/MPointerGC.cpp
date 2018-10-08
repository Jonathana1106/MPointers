//
// Created by elias on 04/10/18.
//
#include "MPointerGC.h"
#include <pthread.h>
#include <unistd.h>


MPointerGC* MPointerGC::instance = 0;

void *turn_on_GC(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

bool MPointerGC::counter_check(int id) {
    //ask if the
    return false;
}

bool MPointerGC::free_mpointer(int id, mpointer::MPointer<int> mPointer) {
    // Si las referencias son mas de cero
    //Retorna falso
    if (counter_check(id)){
        return false;
    }
    //delete node of list
    mPointer.~MPointer();
    return true;
}

bool MPointerGC::free_mpointer(int id, mpointer::MPointer<char>mPointer) {
    // Si las referencias son mas de cero
    //Retorna falso
    if (counter_check(id)){
        return false;
    }
    //delete node of list
    mPointer.~MPointer();
    return true;
}

bool MPointerGC::free_mpointer(int id, mpointer::MPointer<double> mPointer) {
    // Si las referencias son mas de cero
    //Retorna falso
    if (counter_check(id)){
        return false;
    }
    //delete node of list
    mPointer.~MPointer();
    return true;
}

int MPointerGC::add_count(int id) {
    //buscar nodo con el id
    //sumar conteo de referencias
    return 0;
}

MPointerGC::MPointerGC() {

}

MPointerGC *MPointerGC::getInstance() {
    if(instance == 0){
        instance = new MPointerGC();
    }
    return instance;
}

int MPointerGC::show_list(int o) {
    simple_list.print_list();
    return 0;
}

int MPointerGC::generate_ID(mpointer::MPointer<int> *mPointer) {
    ID = rand() % 100000;
    std::cout << ID << " ID " << &mPointer;
    std::cout << "\n";
    //crear el nodo, asignar el id y la direccion de memoria
    Node_s node_s;
    node_s.type = "int";
    node_s.ID = ID;
    node_s.int_mPointer = mPointer->mPointer1;
    node_s.counter = 0;
    mPointer->ID = node_s.ID;
    simple_list.insert(&node_s);
    simple_list.print_list();
    return 0;
}

char MPointerGC::generate_ID(mpointer::MPointer<char> *mPointer) {
    ID = rand() % 100000;
    std::cout << ID << " ID " << &mPointer;
    std::cout << "\n";
    //crear el nodo, asignar el id y la direccion de memoria
    Node_s node_s;
    node_s.type = "char";
    node_s.ID = ID;
    node_s.char_mPointer = mPointer->mPointer1;
    node_s.counter = 0;

    mPointer->ID = node_s.ID;
    simple_list.insert(&node_s);
    simple_list.print_list();
    return 0;
}

double MPointerGC::generate_ID(mpointer::MPointer<double> *mPointer) {
    ID = rand() % 100000;
    std::cout << ID << " ID " << &mPointer;
    std::cout << "\n";
    //crear el nodo, asignar el id y la direccion de memoria
    Node_s node_s;
    node_s.type = "double";
    node_s.ID = ID;
    node_s.double_mPointer = mPointer->mPointer1;
    node_s.counter = 0;

    mPointer->ID = node_s.ID;
    simple_list.insert(&node_s);
    simple_list.print_list();
    return 0;
}

void MPointerGC::turn_on_GC() {

    char in;
    for(;;)
    {

        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cout << "Running garbage collector--------------------------" << "\n";
        // Sleep for 50*1000ms
        pthread_mutex_lock(&mutex1);
        simple_list.print_list();
        pthread_mutex_unlock(&mutex1);
        std::cout << "Stopping garbage collector--------------------------" << "\n";
        usleep(10000);
        std::cin >> in;
        if (in == 's')
            break;

    }
    //std::cout << "Running garbage collector" << "\n";
}
