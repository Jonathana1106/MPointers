#include <iostream>
#include "MPointer/MPointer.h"

using namespace std;

int main() {

    MPointer<int> myPtr;

    myPtr.New();

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

    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr4 = myPtr2;
    // Me da error lo cual esta bien porque los punteros son de diferente tipo.
    //myPtr5 = myPtr2;


    myPtr.show();

    myPtr2.show();

    myPtr3.show();

    cout << valor;
    cout <<  "\n";
    cout << &myPtr;
    cout <<  "\n";
    cout << myPtr.operator&();


    return 0;
}