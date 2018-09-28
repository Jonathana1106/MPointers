//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_PRINTSORT_H
#define MPOINTERS_PRINTSORT_H

#include <cstdio>
#include <array>

template<class T>

void printSort(T *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}


#endif //MPOINTERS_PRINTSORT_H