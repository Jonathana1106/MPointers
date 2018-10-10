//
// Created by jonathan on 28/09/18.
//

#ifndef MPOINTERS_BUBBLESORT_H
#define MPOINTERS_BUBBLESORT_H

#include <cstdio>
#include "iostream"
#include "Swap.h"
#include "../MPointer/MPointer.h"

using namespace mpointer;
using namespace std;

/**
 * Metodo que se encarga de realizar un ordenamiento mediante el algoritmo BubbleSort.
 * @param arr
 * @param n
 */
void bubbleSort(MPointer<int> array[], int n) {
    int i, j;
    bool swapped;
    int temp;

    for (i = 0; i < n - 1; i++) {
        swapped = true;
        for (j = 0; j < n - i - 1; j++) {
            if (&array[j] >= &array[j+1]) {
                temp = &array[j];
                *array[j] = &array[j+1];
                *array[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

#endif //MPOINTERS_BUBBLESORT_H