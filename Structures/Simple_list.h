//
// Created by elias on 26/09/18.
//

#ifndef MPOINTERS_SIMPLE_LIST_H
#define MPOINTERS_SIMPLE_LIST_H

#include <iostream>
#include "../MPointer/MPointer.h"
using namespace mpointer;


class Node_s {
public:
    int counter = 1;
    int ID;
    std::string type;
    MPointer<int> *int_mPointer;
    MPointer<char> *char_mPointer;
    MPointer<double> *double_mPointer;
    //T info;
    int int_data;
    char char_data;
    double double_data;
    double size;
    //Node_s* previous;
    Node_s* next;
};


class Simple_list {
public:

    Node_s* head;
    //Node_s<T>* last;

    Simple_list();

    void insert(Node_s* newNode);
    void remove(Node_s* deleteNode);
    void insert_size(double n);
    Node_s *search(int searched_id);
    int show_size_list();
    void print_list();
private:
    int size{};
    std::string last_type;
};



#endif //MPOINTERS_SIMPLE_LIST_H
