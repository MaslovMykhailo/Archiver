#include "Stack.h"
#include <iostream>

Stack::Stack(int length) {
    size = length;
    stack = new char * [size];
    for (int i = 0 ; i < size ; i++) {
        stack[i] = new char;
    }
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::push(char* element) {
    stack[++top] = element;
}

char* Stack::pop() {
    return stack[top--];
}

void Stack::show() {
    int curElemIndex = top;
    while (curElemIndex >= 0) {
        std::cout << stack[curElemIndex--] << ' ';
    }
    std::cout << std::endl;
}

Stack::~Stack() {
    for (int i = 0 ; i < size ; i++) {
        delete [] stack[i];
    }
    size = 0;
    top = -1;
}