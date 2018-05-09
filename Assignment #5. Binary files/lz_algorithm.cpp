#include "lz_algorithm.h"

using namespace std;

string buffer;
map<std::string,int> dictionary;
vector<string> vectorDict(1, "");

string lz_algorithm_encode(string hexStr) {
    string code;

    for (int i = 0 ; i < hexStr.size() ; i++) {
        string cur = to_string(hexStr[i]);
        auto search = dictionary.find(cur);

        if (search != dictionary.end()) {
            buffer += cur;
        } else {
            code += (to_string(dictionary[buffer]) + cur);
            dictionary[buffer + cur] = (int)dictionary.size() + 1;
            buffer = "";
        }
    }

    return code;
}

string lz_algorithm_decode(string codeStr) {
    string result;

    for (int i = 0 ; i < codeStr.size() ; i++) {
        string word = vectorDict[]
    }
}