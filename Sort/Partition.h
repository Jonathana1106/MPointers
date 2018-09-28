//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_PARTITION_H
#define MPOINTERS_PARTITION_H

#include "Swap.h"

template<class T>

T partition(T array[], int low, int high) {

    T pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

#endif //MPOINTERS_PARTITION_H