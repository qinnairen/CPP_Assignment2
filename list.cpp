#include"list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

List::List() {
    size=0;
    sentinel_head = new Node() ;
    sentinel_tail = new Node() ;
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
}

List::~List() {
    Node* current = sentinel_head;
    while (current->next) {
        Node * temp = current->next;
        current = current->next->next;
        sentinel_head->next=current;
        current->prev=sentinel_head;
        delete temp;
    }
    sentinel_head->next=nullptr;
    sentinel_tail->prev=nullptr;
    delete sentinel_head;
    delete sentinel_tail;
}

void List::insert(int v) {
    if (size==0) {
        Node* temp = new Node(v, sentinel_tail, sentinel_head);
        sentinel_head->next = temp;
        sentinel_tail->prev = temp;
        size++;
    }
    else {
        Node* temp = new Node(v, sentinel_tail, sentinel_tail->prev);
        sentinel_tail->prev->next = temp;
        sentinel_tail->prev = temp;
        size++;
    }
}

int List::delete_tail() {
    if (size==0) {
        return 0;
    }

    else{
    Node* temp = sentinel_tail->prev;
    int x =sentinel_tail->prev->get_value();
    sentinel_tail->prev->prev->next=sentinel_tail;
    sentinel_tail->prev=sentinel_tail->prev->prev;
    delete temp;
    size=size-1;
    return x;
    }
}

int List::get_size() {
    return size;
}

Node* List::get_head() {
    Node* x = sentinel_head;
    return x;
}






