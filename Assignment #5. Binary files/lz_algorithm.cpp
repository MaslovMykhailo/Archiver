#include <iostream>
#include "lz_algorithm.h"

using namespace std;

//string buffer;
//map<std::string,int> dictionary;
//vector<string> vectorDict(1, "");

list<Node*> lz_algorithm_encode(string str) {
    map<string,int> dictionary;
    string buffer;
    list<Node*> answer;

    for (int i = 0 ; i < str.size() ; i++) {
        string cur; cur.push_back(str[i]);
        auto search = dictionary.find(buffer + cur);

        if (search != dictionary.end()) {
            buffer += cur;
        } else {
            answer.push_back(new Node(dictionary[buffer], str[i]));
            dictionary[buffer + cur] = (int)dictionary.size() - 1;
            buffer.clear();
        }
    }

    return answer;
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