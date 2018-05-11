#ifndef ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H
#define ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H


#include <string>
#include <map>
#include <list>

struct Node {
    int pos;
    char next;

    Node(int , char);
};

void lz_algorithm_encode(char, std::list<Node*>*);

#endif //ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H
