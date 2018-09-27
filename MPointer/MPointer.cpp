//
// Created by elias on 27/09/18.
//

#include "MPointer.h"
#include "MPointerGC.h"




template<class T>
mpointer::MPointer<T> mpointer::MPointer<T>::New() {
    {
        MPointerGC<T> *mPointerGC = MPointerGC<T>::getInstance();
        //static T *ptr;
        std::cout << this << " MPointer instancia " << "\n";
        mPointer1 = this;
        std::cout << &mPointer1 << " mpointerrr1" << "\n";
        std::cout << mPointer1 << " mpointerrr2" << "\n";
        ptr = (T *) malloc(sizeof(T));
        ID = mPointerGC->generate_ID(*this);

    }
}

template<class T>
void MPointer<T>::operator=(T ptra) {
    *ptr = ptra;
}

template<class T>
void MPointer<T>::operator=(MPointer<T> mPointer) {
    this->ptr = mPointer.ptr;

}

template<class T>
T MPointer<T>::operator&() {
    return *ptr;
}

template<class T>
T *MPointer<T>::get_addres() {
    return ptr;
}

template<class T>
void MPointer<T>::show() {
    std::cout << "El dato es: " << *ptr << "\n";
}

template<class T>
void MPointer<T>::save_ID(int ID_GC) {
    ID = ID_GC;

}


template mpointer::MPointer<int> mpointer::MPointer<int>::New();
template mpointer::MPointer<char> mpointer::MPointer<char>::New();
template mpointer::MPointer<double > mpointer::MPointer<double>::New();
template void mpointer::MPointer<int>::operator=(int);
template void mpointer::MPointer<char>::operator=(char);
template void mpointer::MPointer<double>::operator=(double);
template void mpointer::MPointer<int>::operator=(mpointer::MPointer<int>);
template void mpointer::MPointer<char>::operator=(mpointer::MPointer<char>);
template void mpointer::MPointer<double>::operator=(mpointer::MPointer<double>);
template int mpointer::MPointer<int>::operator&();
template char mpointer::MPointer<char>::operator&();
template double mpointer::MPointer<double>::operator&();
template int *mpointer::MPointer<int>::get_addres();
template char *mpointer::MPointer<char>::get_addres();
template double *mpointer::MPointer<double>::get_addres();
template void mpointer::MPointer<int>::show();
template void mpointer::MPointer<char>::show();
template void mpointer::MPointer<double>::show();