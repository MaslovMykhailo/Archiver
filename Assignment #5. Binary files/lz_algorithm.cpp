#include <iostream>
#include "lz_algorithm.h"

using namespace std;


std::string buffer;
std::map<std::string,int> dictionary;

//vector<string> vectorDict(1, "");

void lz_algorithm_encode(char c, list<Node*> *answer) {
        string cur; cur.push_back(c);
        auto search = dictionary.find(buffer + cur);

        if (search != dictionary.end()) {
            buffer += cur;
        } else {
            answer->push_back(new Node(dictionary[buffer], c));
            dictionary[buffer + cur] = (int)dictionary.size() - 1;
            if (dictionary.size() >= 65536) {
                dictionary.clear();
                cout << c << endl;
            }
            buffer.clear();
        }
}

//string lz_algorithm_decode(string codeStr) {
//    string result;
//
//    string str; str.push_back(codeStr[0]);
//    int i = stoi(str, nullptr, 10);
//
//
//    string word = vectorDict[i] + codeStr[1];
//    result += word;
//    vectorDict.push_back(word);
//
//
//    return result;
//}