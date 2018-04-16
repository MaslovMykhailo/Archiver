#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int length) {
    size = length;
    stack = new char [size];
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::push(char element) {
    stack[++top] = element;
}

char Stack::pop() {
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
    size = 0;
    delete [] stack;
    top = -1;
  }
