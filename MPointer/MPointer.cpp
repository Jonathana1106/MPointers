//
// Created by elias on 27/09/18.
//

#include "MPointer.h"
#include "MPointerGC.h"



template<class T>
mpointer::MPointer<T> mpointer::MPointer<T>::New() {
    {
        MPointerGC *mPointerGC = MPointerGC::getInstance();
        std::cout << mPointerGC << " Instance in MPointer of GC "<< "\n";
        //static T *ptr;
        T var;
        std::cout << this << " MPointer instancia " << "\n";
        mPointer1 = this;
        //std::cout << &mPointer1 << " mpointerrr1" << "\n";
        //std::cout << mPointer1 << " mpointerrr2" << "\n";
        ptr = (T *) malloc(sizeof(T));
        ID = mPointerGC->generate_ID(this);

    }
}

template<class T>
void MPointer<T>::operator=(T ptra) {
    *ptr = ptra;
}

template<class T>
void MPointer<T>::operator=(MPointer<T> mPointer) {
    MPointerGC *mPointerGC = MPointerGC::getInstance();
    mPointerGC->add_count(mPointer.ID);
    //mPointerGC->change_id(ID, mPointer.ID);
    this->ptr = mPointer.ptr;
    this->reference_ID = mPointer.ID;

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

template<class T>
int MPointer<T>::say_hello() {
    std::cout << "Holaaa" << '\n';
    return 0;
}

template<class T>
void MPointer<T>::destructor() {
    std::cout << "reference to mpointer deleted" << std::endl;
    MPointerGC *mPointerGC = MPointerGC::getInstance();
    this->mPointer1 = nullptr;
    mPointerGC->delete_count(this->ID);
    if(reference_ID != 0){
        mPointerGC->delete_count(reference_ID);
    }
    this->ID = 0;
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
template void mpointer::MPointer<int>::destructor();
template void mpointer::MPointer<char>::destructor();
template void mpointer::MPointer<double>::destructor();