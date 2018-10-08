#include "MPointer/MPointer.h"
#include "MPointer/MPointerGC.h"
#include "Sort/BubbleSort.h"
#include "Sort/InsertionSort.h"
#include "Sort/QuickSort.h"
#include "Sort/PrintSort.h"
#include <pthread.h>

using namespace mpointer;

void *turn_on_GC(void*);
void *shell_mpointer(void* ptr);
MPointerGC *mPointerGC;

int main() {

    int rc, rc2;
    const char *message1 = "Thread 1";
    pthread_t threads[1], threads2[1];
    pthread_attr_t attr;


    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    mPointerGC = MPointerGC::getInstance();
    std::cout << mPointerGC << " Instance in main of GC "<< "\n";
    rc = pthread_create(&threads[1], NULL, turn_on_GC,(void*)message1);
    //rc = pthread_t.pthread_create(&threads[1], attr, mPointerGC->show_list(i), i );

    if (rc) {
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    rc2 = pthread_create(&threads2[1], NULL, shell_mpointer,(void*)message1);
    //rc = pthread_t.pthread_create(&threads[1], attr, mPointerGC->show_list(i), i );

    if (rc2) {
        cout << "Error:unable to create thread," << rc2 << endl;
        exit(-1);
    }

    pthread_join(threads[1] , NULL);

    pthread_join(threads2[1], NULL);

    std::cout << mPointerGC << " Instance in main of GC "<< "\n";
    exit(EXIT_SUCCESS);
/*
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
    cout << "\n";*/





    return 0;
}

void *turn_on_GC(void* ptr) {

    mPointerGC->turn_on_GC();
    //MPointerGC::turn_on_GC;
}

void *shell_mpointer(void* ptr){

    //MPointer<double> myPtr{};
    //myPtr.New();

    //myPtr.New();

    MPointer<int> myPtr2{};

    myPtr2.New();

    MPointer<int> myPtr3{};

    myPtr3.New();

    MPointer<char> myPtr4{};

    myPtr4.New();

    MPointer<double> myPtr5{};

    myPtr5.New();

/////////////////////////////////////////////////////////
//////////////////Caution////////////////////////////////
//    MPointer<int> myPtr2 = MPointer<int>::New();
/////////////////////////////////////////////////////////


    *myPtr2 = 5;

    //myPtr.operator=(12);

    //int valor = &myPtr;

    *myPtr3 = 8;

    //MPointerGC<int> *mPointerGC = MPointerGC<int>::getInstance();

    int id1, id2, id3;
    //id1 = mPointerGC->generate_ID(myPtr2);
    //id2 = mPointerGC->generate_ID(myPtr3);
    //id3 = mPointerGC->generate_ID(myPtr5);
    //mPointerGC->generate_ID(myPtr4);

    std::cout << mPointerGC << "\n";
    //mPointerGC->free_mpointer(id1, myPtr2);

    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr4 = myPtr2;
    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr5 = myPtr2;


    //myPtr.show();

    //myPtr2.show();

    //myPtr3.show();


    /*  std::cout << mPointerGC << "\n" << "\n"
                << valor
                << "\n"
                << &myPtr
                << "\n"
                << myPtr.operator&();
  */
    std::cout << "---------------------------------------------------" << "\n";
    //mPointerGC->show_list(1);
}

//g++ -pthread /home/elias/Escritorio/Proyecto1_J_G_respaldo/main.cpp /home/elias/Escritorio/Proyecto1_J_G_respaldo/Structures/Simple_list.cpp /home/elias/Escritorio/Proyecto1_J_G_respaldo/MPointer/MPointer.cpp /home/elias/Escritorio/Proyecto1_J_G_respaldo/MPointer/MPointerGC.cpp -o mpointer