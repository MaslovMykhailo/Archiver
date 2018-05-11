#include <iostream>
#include "lz_algorithm.h"

using namespace std;


std::string buffer;
std::map<std::string,int> dictionary;

void lz_algorithm_encode(char c, list<Node*> *answer) {
    string cur; cur.push_back(c);
    auto search = dictionary.find(buffer + cur);

    if (search != dictionary.end()) {
        buffer += cur;
    } else {
        answer->push_back(new Node(dictionary[buffer], c));
        if (dictionary.size() < 65536) dictionary[buffer + cur] = (int)dictionary.size() - 1;
        buffer.clear();
    }
}

Node::Node(int p, char n) {
    pos = p;
    next = n;
}
