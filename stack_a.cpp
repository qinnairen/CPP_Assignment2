#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_A::Stack_A() {
    stk[1024]={0};
    size=0;
}

void Stack_A :: push(int data) {
    if (size==1024) {
        throw runtime_error("Stack Full");
        }
        stk[size]=data;
        size++ ;
}

int Stack_A :: pop() {
    if (size==0) {
        throw runtime_error("Empty Stack");
        return 0;
    }
    else {
        int x = stk[size-1];
        size=size - 1;
        return x;
    }
}

int Stack_A :: get_element_from_top(int idx) {
    if (idx>=size || idx<0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    int x = stk[size-idx-1];
    return x;
}

int Stack_A :: get_element_from_bottom(int idx) {
    if (idx>=size || idx<0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    int x = stk[idx];
    return x;
}

int Stack_A :: add() {
    if (size==1 || size==0) {
        throw runtime_error("Not Enough Argeuments");
    }
    else {
        int x = stk[size-1] + stk[size-2];
        pop();
        pop();
        push(x);
        return x;
    }
}

int Stack_A :: subtract() {
    if (size==1 || size==0) {
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

int Stack_A :: multiply() {
    if (size==1 || size==0) {
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

int Stack_A :: divide() {
    if (size==1 || size==0) {
        throw runtime_error("Not Enough Arguements");
    }
    int a = pop();
    int b = pop();
    if (a==0) {
        throw runtime_error("Divide by Zero Error");
    }
    else {    
        int x = b/a ;
        if ((a*b< 0) && (b%a != 0)) {
            x=x-1;
        }
        push(x);
        return x;
    }
}

int* Stack_A :: get_stack() {
    int* x = &stk[0];
        return x;
}

int Stack_A :: get_size() {
    return size;
}

void Stack_A::print_stack(bool top_or_bottom) {
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

