//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_SWAP_H
#define MPOINTERS_SWAP_H

#include "../MPointer/MPointer.h"

using namespace mpointer;

template<class T>

void swap(MPointer<int> *x, MPointer<int> *y) {

    MPointer<int> temp = *x;
    *x = *y;
    *y = temp;
}

#endif //MPOINTERS_SWAP_H