#include "MPointer/MPointer.h"
#include "MPointer/MPointerGC.h"
#include "Sort/BubbleSort.h"
#include "Sort/InsertionSort.h"
#include "Sort/QuickSort.h"
#include "Sort/PrintSort.h"

using namespace mpointer;

int main() {


    cout << "QuickSort \n";

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printSort(arr, n);
    cout << "\n";


    cout << "InsertionSort. \n";

    int arr2[] = {12, 11, 13, 5, 6};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, m);
    printSort(arr2, m);
    cout << "\n";

    cout << "BubbleSort. \n";

    int array[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int o = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, o);
    printSort(array, o);
    cout << "\n";


    MPointer<double> myPtr;
    myPtr.New();

    //myPtr.New();

    MPointer<int> myPtr2;

    myPtr2.New();

    MPointer<int> myPtr3;

    myPtr3.New();

    MPointer<char> myPtr4;

    myPtr4.New();

    MPointer<double> myPtr5;

    myPtr5.New();

/////////////////////////////////////////////////////////
//////////////////Caution////////////////////////////////
//    MPointer<int> myPtr2 = MPointer<int>::New();
/////////////////////////////////////////////////////////


    *myPtr2 = 5;

    myPtr.operator=(12);

    int valor = &myPtr;

    myPtr3 = myPtr2;

    MPointerGC<int> *mPointerGC = MPointerGC<int>::getInstance();
    MPointerGC<int> *mPointerGC2 = MPointerGC<int>::getInstance();

    int id1, id2, id3;
    id1 = mPointerGC->generate_ID(myPtr2);
    id2 = mPointerGC->generate_ID(myPtr2);
    id3 = mPointerGC->generate_ID(myPtr2);
    mPointerGC->generate_ID(myPtr2);
    mPointerGC->free_mpointer(id1, myPtr2);

    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr4 = myPtr2;
    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr5 = myPtr2;


    myPtr.show();

    myPtr2.show();

    myPtr3.show();


    std::cout << mPointerGC << "\n" << mPointerGC2 << "\n"
              << valor
              << "\n"
              << &myPtr
              << "\n"
              << myPtr.operator&();

    mPointerGC->show_list();


    return 0;
}