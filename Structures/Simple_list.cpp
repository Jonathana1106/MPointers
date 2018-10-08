//
// Created by elias on 04/10/18.
//
#include "Simple_list.h"

void Simple_list::insert(Node_s *newNode) {
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
        while (current != NULL) {
            if (deleteNode == next) {
                current->next = next->next;
                delete next;
                size--;
            }
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
    int n;
    while(size != 0)
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

        std::cout << " The number of call is " << disp->counter <<"\n";
        //disp->mPointer->show();
        if(disp->next == nullptr || head->next == nullptr || size == n)
        {
            disp = nullptr;
            delete(disp);
            break;
        }
        disp = disp->next;
        //break;
        //disp++;
        n++;
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
