//
// Created by elias on 04/10/18.
//
#include "Simple_list.h"

void Simple_list::insert(Node_s* newNode) {
// Is the first node
    //Node_s temp = *head;

    if (head != nullptr) {
        // The list has more elements
        std::cout << " First head"<< head << std::endl;
        newNode->next = head;
        std::cout << '\n' << "Pointer next of head " << newNode->next << " type " << newNode->next->type << '\n';
        //if(head->next != nullptr)
          //  std::cout << "Pointer to next of head " << head->next << " type " << head->next->type << '\n';
        //newNode->next->previous = newNode;
    }else {
        newNode->next = nullptr;
        std::cout << "First mpointer " << '\n';
        //last = newNode;
    }
    std::cout << "Pointer head " << &newNode << " type ------" << newNode->type << '\n';
    //std::cout << "Pointer head " << head << " type ------" << head->type << '\n';
    head = newNode;
    std::cout << "Pointer head " << &newNode << " type ------" << newNode->type << '\n';
    //std::cout << "Pointer head " << head << " type ------" << head->type << '\n' << "+++++++++++++++++++++++++"<< '\n';
    size++;

}

void Simple_list::remove(Node_s *deleteNode) {
    Node_s* current = head;
    Node_s* next = head->next;

    if(current == deleteNode){
        head = current->next;
        delete current;
        size--;
    }
    else {
        std::cout << "Error" << std::endl;
        while (current != nullptr) {
            if (deleteNode == next) {
                current->next = next->next;
                delete next;
                size--;
            }
            current = current->next;
            next = next->next;
        }
    }
}


Node_s *Simple_list::search(int searched_id) {
    int count=0;
    Node_s* searchele = head;
    while( searchele!= nullptr)
    {
        if(searchele->ID != searched_id)
        {
            searchele=searchele->next;
            count+=1;
        }
        else
            return searchele;
    }
    return nullptr;
}

void Simple_list::print_list() {
    std::cout << "Size: " << size << " Element In The Linked List Are : " << "\n";
    Node_s *disp = head;
    int n = size;
    while(n != 0)
    {
        if(disp->type == "int"){
            std::cout<<" ID "<< disp->ID << " Address de la instancia " << disp->int_mPointer;
        }
        if(disp->type == "char"){
            std::cout<<" ID "<< disp->ID << " Address de la instancia " << disp->char_mPointer;
        }
        if(disp->type == "double"){
            std::cout<<" ID "<< disp->ID << " Address de la instancia " << disp->double_mPointer;
        }

        std::cout << " Instancia del nodo " << disp << " The number of call is " << disp->counter <<"\n";
        //disp->mPointer->show();
        if(disp->next == nullptr || head->next == nullptr)
        {
            disp = nullptr;
            delete(disp);
            break;
        }
        disp = disp->next;
        //break;
        //disp++;
        n--;
    }
}



void Simple_list::run_garbage_collector() {
    Node_s *disp = head;
    int n = size;
    while(n != 0)
    {
        //std::cout << "Error1" << std::endl;
        if(disp->counter == 0){
            remove(disp);
            break;
        }
        if(disp->next == nullptr)
        {
            disp = nullptr;
            delete(disp);
            break;
        }
        disp = disp->next;
        n--;
    }
}

void Simple_list::insert_size(double n) {
}

Simple_list::Simple_list() {
    head = nullptr;
    //last = nullptr;
}

int Simple_list::show_size_list() {
    return size;
}

Node_s::Node_s(int counter, int ID, const std::string &type, int int_data, char char_data, double double_data,
               Node_s *next) : counter(counter), ID(ID), type(type),  int_data(int_data),
                               char_data(char_data), double_data(double_data), next(next) {
    this->int_mPointer = nullptr;
    this->char_mPointer = nullptr;
    this->double_mPointer = nullptr;
}
