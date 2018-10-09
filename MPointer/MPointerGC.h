//
// Created by elias on 24/09/18.
//

#ifndef MPOINTERS_MPOINTERGC_H
#define MPOINTERS_MPOINTERGC_H

#include <tgmath.h>
#include "MPointer.h"
#include "../Structures/Simple_list.h"


class MPointerGC {

private:
    mpointer::MPointer<int> addres_int;
    mpointer::MPointer<char> addres_char;
    mpointer::MPointer<double> addres_double;
    int ID;
    bool counter_check(int id);
    Simple_list simple_list;

    /*
     * Inicializar con singleton
     * */
    static MPointerGC* instance;
    MPointerGC();

public:
    int generate_ID(mpointer::MPointer<int>*);
    int generate_ID(mpointer::MPointer<char>*);
    double generate_ID(mpointer::MPointer<double>*);
    bool free_mpointer(int id, mpointer::MPointer<int>);
    bool free_mpointer(int id, mpointer::MPointer<char>);
    bool free_mpointer(int id, mpointer::MPointer<double>);
    int add_count(int id);
    int delete_count(int id);
    void change_id(int id, int id2);
    int show_list(int o);
    void turn_on_GC();

    static MPointerGC* getInstance();
};


#endif //MPOINTERS_MPOINTERGC_H
