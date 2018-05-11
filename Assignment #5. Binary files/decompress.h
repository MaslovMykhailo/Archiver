#ifndef ASSIGNMENT_5_BINARY_FILES_DECOMPRESS_H
#define ASSIGNMENT_5_BINARY_FILES_DECOMPRESS_H


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bitset>

void decompress(char*, char*);

struct phrase{
    char curr;
    phrase* prev;
    phrase(char, phrase*);
    void get_phrase(std::string*);
};

phrase** resize(phrase**, int*);


#endif //ASSIGNMENT_5_BINARY_FILES_DECOMPRESS_H
