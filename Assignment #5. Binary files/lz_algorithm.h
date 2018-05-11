#ifndef ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H
#define ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H


#include <string>
#include <map>
#include <list>

struct Node {
    int pos;
    char next;

    Node(int p, char n) {
        pos = p;
        next = n;
    }
};

//std::string buffer;
//std::map<std::string,int> dictionary;

void lz_algorithm_encode(char, std::list<Node*>*);

//std::string lz_algorithm_decode(std::string);


#endif //ASSIGNMENT_5_BINARY_FILES_LZ_ALGORITHM_H