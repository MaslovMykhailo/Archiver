#ifndef ASSIGNMENT_4_DATA_STRUCTURES_QUEUE_H
#define ASSIGNMENT_4_DATA_STRUCTURES_QUEUE_H


class Queue {
private:
    int tail;
    int head;
    int size;
    char **queue;
public:
    Queue(int);
    void enqueue(char*);
    char* dequeue();
    bool isEmpty();
    int getSize();
    void show();
    ~Queue();
};


#endif //ASSIGNMENT_4_DATA_STRUCTURES_QUEUE_H
