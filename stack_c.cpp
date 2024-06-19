#include "stack_c.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_C::Stack_C() {
    stk = new List();
}

Stack_C::~Stack_C() {
    delete stk;
}

void Stack_C::push(int data) {
    stk->insert(data);
    }

int Stack_C::pop() {
    return stk->delete_tail();

}

int Stack_C::get_element_from_top(int idx) {
    if (idx>=stk->get_size() || idx<0) {
    throw runtime_error("Index out of range");
    }
    else {
        Node* current = stk->get_head();
    while (current->next) {
        current=current->next;
    }
    for (int i=0;i<idx+1;i++) {
        current=current->prev;
    }
    int x = current->get_value();
    return x;
}
}
int Stack_C::get_element_from_bottom(int idx) {
    if (idx>=stk->get_size() || idx<0) {
    throw runtime_error("Index out of range");
    }
    else {
    Node* current = stk->get_head();
    for (int i=0; i<idx+1;i++) {
        current=current->next;
    }
    int x = current->get_value();
    return x;
}
}

int Stack_C::add() {
    if (stk->get_size()<2) {
        throw runtime_error("Not Enough Arguements");
    }
    else {
    Node* current = stk->get_head();
    while (current->next) {
        current=current->next;
    }
    int x = current->prev->get_value();
    int y = current->prev->prev->get_value();
    int a = x+y;
    stk->delete_tail();
    stk->delete_tail();
    stk->insert(a);
    return a;
}
}

int Stack_C::subtract() {
    if (stk->get_size()<2) {
        throw runtime_error("Not Enough Arguements");
    }
    else {
    Node* current = stk->get_head();
    while (current->next) {
        current=current->next;
    }
    int x = current->prev->get_value();
    int y = current->prev->prev->get_value();
    int a = y-x;
    stk->delete_tail();
    stk->delete_tail();
    stk->insert(a);
    return a;
}
}

int Stack_C::multiply() {
    if (stk->get_size()<2) {
        throw runtime_error("Not Enough Arguements");
    }
    else {
    Node* current = stk->get_head();
    while (current->next) {
        current=current->next;
    }
    int x = current->prev->get_value();
    int y = current->prev->prev->get_value();
    int a = x*y;
    stk->delete_tail();
    stk->delete_tail();
    stk->insert(a);
    return a;
}
}

int Stack_C::divide() {
    if (stk->get_size()<2) {
        throw runtime_error("Not Enough Arguements");
    }
    Node* current = stk->get_head();
    while (current->next) {
        current=current->next;
    }
    int x = current->prev->get_value();
    int y = current->prev->prev->get_value();
    if (x==0)  {
        throw runtime_error("Divide by Zero Error");
    }
    int a = y/x;
    if (x*y<0 && (y%x)!=0) {
    a=a-1;
    }
    stk->delete_tail();
    stk->delete_tail();
    stk->insert(a);
    return a;
}


void Stack_C::print_stack(bool top_or_bottom) {
    if (top_or_bottom) {
    Node* current = stk->get_head();
    while (current->next!=nullptr) {
        current=current->next;
    }
    while (current->prev->prev) {
        current=current->prev;
        cout<<current->get_value()<<endl;
    }
    }

    else if (!top_or_bottom) {
    Node* current = stk->get_head();
    while (current->next->next) {
        current=current->next;
        cout<<current->get_value()<<endl;
    }
    }
}

List* Stack_C::get_stack() {
    return stk;
}

int Stack_C::get_size() {
    return stk->get_size();
}