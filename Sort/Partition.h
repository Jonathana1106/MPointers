//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_PARTITION_H
#define MPOINTERS_PARTITION_H

#include "Swap.h"
#include "../MPointer/MPointer.h"

using namespace mpointer;


int partition(MPointer<int> array[], int low, int high) {

    MPointer<int> pivot = array[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (&array[j] <= &pivot) {
            i++;
            temp = &array[j];
            *array[j] = &array[i];
            *array[i] = temp;
        }
    }
    temp = &array[high];
    *array[high] = &array[i + 1];
    *array[i + 1] = temp;
    return (i + 1);
}

#endif //MPOINTERS_PARTITION_H