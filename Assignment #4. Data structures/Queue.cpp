#include "Queue.h"
#include <iostream>

Queue::Queue(int length) {
    size = length+1;
    queue = new char * [size];
    for (int i = 0 ; i < size ; i++) queue[i] = new char;
    head = tail = 0;
}

void Queue::enqueue(char* element) {
    queue[tail] = element;
    if (tail == size-1) {
        tail = 0;
    } else {
        tail++;
    }
}

char* Queue::dequeue() {
    char* element = queue[head];
    if (head == size-1) {
        head = 0;
    } else {
        head++;
    }
    return element;
}

bool Queue::isEmpty() {
    return head == tail;
}

void Queue::show() {
    int h = head, t = tail;
    while (h != t) {
        std::cout << queue[h] << ' ';
        if (h == size-1) {
            h = 0;
        } else {
            h++;
        }
    }
    std::cout << std::endl;
}

Queue::~Queue() {
    for (int i = 0 ; i < size ; i++) delete [] queue[i];
    size = 0;
    head = tail = 0;
}

int Queue::getSize() {
    return size-1;
}
