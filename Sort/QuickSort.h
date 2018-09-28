//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_QUICKSORT_H
#define MPOINTERS_QUICKSORT_H


#include "cstdio"
#include "Partition.h"

/**
 * Metodo que se encarga de realizar un ordenamiento mediante el algoritmo QuickSort.
 * @param arr
 * @param low
 * @param high
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#endif //MPOINTERS_QUICKSORT_H