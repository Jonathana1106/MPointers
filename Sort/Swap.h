//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_SWAP_H
#define MPOINTERS_SWAP_H

template<class T>

void swap(T *x, T *y) {

    T temp = *x;
    *x = *y;
    *y = temp;
}

#endif //MPOINTERS_SWAP_H