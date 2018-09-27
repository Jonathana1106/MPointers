//
// Created by elias on 26/09/18.
//

#ifndef MPOINTERS_SIMPLE_LIST_H
#define MPOINTERS_SIMPLE_LIST_H

#include <iostream>
#include "../MPointer/MPointer.h"
using namespace mpointer;

template <class T>
class Node_s {
public:
    int counter;
    int ID;
    MPointer<T> *mPointer;
    T info;
    double size;
    //Node_s* previous;
    Node_s* next;
};

template <class T>
class Simple_list {
public:

    Node_s<T>* head;
    //Node_s<T>* last;
public:
    Simple_list();

    void insert(Node_s<T>* newNode);
    void remove(Node_s<T>* deleteNode);
    void insert_first(T data);
    void insert_size(double n);
    Node_s<T> *search(T searched);
    int show_size_list();
    void print_list();
private:
};

template<class T>
void Simple_list<T>::insert_first(T  data) {
    Node_s<T> node = new(Node_s<T>);
    node.data = data;
    node.next = nullptr;
    if (head != nullptr) {
        // The list has more elements
        node->next = head;
        node->next->previous = node;
    }else {
        node->next = nullptr;
    }
    head = node;
    head->previous = nullptr;
}

template <class T>
void Simple_list<T>::insert(Node_s<T>* newNode) {
        // Is the first node
        if (head != nullptr) {
            // The list has more elements
            newNode->next = head;
            //newNode->next->previous = newNode;
        }else {
            newNode->next = nullptr;
            //last = newNode;
        }
        head = newNode;
//        head->previous = nullptr;
}

template <class T>
void Simple_list<T>::remove(Node_s<T>* deleteNode) {
    if (deleteNode->previous == nullptr){
        // Is the first node
        if (deleteNode->next == nullptr){
            // List only has one element
            head = nullptr;
        }else {
            // List has more elements
            head = deleteNode->next;
            head->previous = nullptr;
        }
    }else {
        if (deleteNode->next == nullptr){
            // Is the last node
            deleteNode->previous->next = nullptr;
        }else {
            // Middle node
            deleteNode->previous->next = deleteNode->next;
            deleteNode->next->previous = deleteNode->previous;
        }
    }
    delete(deleteNode);
}

template <class T>
Node_s<T> *Simple_list<T>::search(T searched) {
    int count=0;
    Node_s<T> *searchele = head;
    while( searchele!= nullptr)
    {
        if(searchele->data != searched)
        {
            searchele=searchele->next;
            count+=1;
        }
        else
            return searchele;
    }
    return nullptr;
}
template<class T>
Simple_list<T>::Simple_list() {
    head = nullptr;
    //last = nullptr;
}

template<class T>
int Simple_list<T>::show_size_list() {
    std::cout << "The size of the list is : ";
    Node_s<T> *disp_ = head;
    int size = 0;
    while(disp_ != NULL)
    {
        size++;
        if(disp_->next==NULL)
        {
            size++;
            break;
        }
        disp_ = disp_->next;
    }
    return size;
}

template<class T>
void Simple_list<T>::print_list() {
    std::cout << "Element In The Linked List Are : " << head->ID;
    Node_s<T> *disp = head;
    while(disp != nullptr)
    {
        std::cout<<" ID "<< disp->ID << " Address de la instancia " << disp->mPointer;
        std::cout << " ";
        disp->mPointer->show();
        if(disp->next == nullptr || head->next == nullptr)
        {
            disp = nullptr;
            delete(disp);
            break;
        }
        disp = disp->next;
        break;
    }
}

template<class T>
void Simple_list<T>::insert_size(double n) {


}

#endif //MPOINTERS_SIMPLE_LIST_H
