#ifndef ASSIGNMENT_4_DATA_STRUCTURES_STACK_H
#define ASSIGNMENT_4_DATA_STRUCTURES_STACK_H


class Stack {
private:
    int size;
    char **stack;
    int top;
public:
    Stack(int);
    bool isEmpty();
    void push(char*);
    char* pop();
    void show();
    ~Stack();
};


#endif //ASSIGNMENT_4_DATA_STRUCTURES_STACK_H
