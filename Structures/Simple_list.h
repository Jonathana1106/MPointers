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
    Node_s(int counter, int ID, const std::string &type, int int_data, char char_data, double double_data,
           Node_s *next);

public:
    int counter = 1;
    int ID;
    std::string type;
    MPointer<int> *int_mPointer = nullptr;
    MPointer<char> *char_mPointer = nullptr;
    MPointer<double> *double_mPointer = nullptr;
    //T info;
    int int_data;
    char char_data;
    double double_data;
    double size;
    //Node_s* previous;
    Node_s* next = nullptr;
};


class Simple_list {
public:

    Node_s* head = nullptr;
    //Node_s<T>* last;

    Simple_list();

    void insert(Node_s* newNode);
    void remove(Node_s* deleteNode);
    void insert_size(double n);
    Node_s *search(int searched_id);
    int show_size_list();
    void print_list();
    void run_garbage_collector();
private:
    int size{};
    std::string last_type;
};



#endif //MPOINTERS_SIMPLE_LIST_H
