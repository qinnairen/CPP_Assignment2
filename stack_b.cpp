#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_B::Stack_B() {
    capacity = 1024;
    size = 0 ;
    try {
        stk=new int[capacity];
    }
    catch(const bad_alloc &) {
        delete stk;
        throw runtime_error("Out of Memory");
    }
    
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data) {
    if (size==0) {
        stk[0]=data;
        size++;
    }
    else if (size==capacity) {
        int* dummy;
        capacity = capacity*2;
        dummy = new int[capacity];
        for (int i =0;i<size;i++) {
            dummy[i]=stk[i];
        }
        delete[] stk;
        stk=dummy;
        stk[size]=data;
        size++;
    }
    else {
        stk[size]=data;
        size=size+1;
    }
}

int Stack_B::pop() {
    if (size==0) {
        throw runtime_error("Empty Stack");
        return -1;
    }

    if (size<(capacity/4) && capacity>1024) {
        capacity = capacity /2 ;
        int* dummy;
        dummy = new int[capacity];
        for (int i=0;i<size;i++) {
            dummy[i]=stk[i];
        }
        delete[] stk;
        stk = dummy;
        size=size-1;
    }
    else {
        size  = size-1;
    }
    return stk[size];
}

int Stack_B::get_element_from_top(int idx) {
    if (idx>=size || idx<0) {
        throw runtime_error("Index out of range");
    }
    else {
    int x = stk[size-idx-1];
        return x;
}
}

int Stack_B::get_element_from_bottom(int idx) {
    if (idx>=size || idx<0) {
        throw runtime_error("Index out of range");
    }
    else {
    int x = stk[idx];
        return x;
}
}

int Stack_B :: add() {
    int x = stk[size-1] + stk[size-2];
    pop();
    pop();
    push(x);
    return x;
}

int Stack_B :: subtract() {
    if (size==1) {
        throw runtime_error("Not Enough Argeuments");
    }
    else {
    int x = stk[size-2] - stk[size-1];
    pop();
    pop();
    push(x);
    return x;
    }
}

int Stack_B :: multiply() {
    if (size==1) {
        throw runtime_error("Not Enough Arguements");
    }
    else{
    int x = stk[size-1] * stk[size-2];
    pop();
    pop();
    push(x);
    return x;
    }
}

int Stack_B :: divide() {
    if (size<2) {
        throw runtime_error("Not Enough Arguements");
    }
    int a = pop();
    int b = pop();
    if (a==0) {
        throw runtime_error("Divide by Zero Error");
    }
    else {
        int x = b /a;
        if (b*a<0 && b%a!=0) {    
        x=x-1;
        }
        push(x);
        return x;
    }
}

int* Stack_B :: get_stack() {
    int* x = &stk[0];
        return x;
}

int Stack_B :: get_size() {
    return size;
}

void Stack_B::print_stack(bool top_or_bottom) {
    int x = size;
    if (top_or_bottom) {
    for (int i =0; i<x;i++) {
        cout<<stk[size-i-1]<<endl;
    }
    }
    else if (!top_or_bottom) {
        for (int i=0;i<x;i++) {
            cout<<stk[i]<<endl;
        }
    }
}