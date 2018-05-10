#include "compress.h"
#include "lz_algorithm.h"
#include "parse_hex.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

void compress(char* fileName) {
    ifstream input (fileName, ios::binary);
    if (input.is_open()) {

        // determine length of file
        input.seekg (0, input.end);
        int length = input.tellg();
        input.seekg (0, input.beg);

        string data;

        for (int i = 0 ; i < length ; i++) {
            char symbol;
            input.read(&symbol, sizeof(symbol));

//            int charCode = (int)symbol;
//            data += bitset<8>(charCode).to_string();
            data += symbol;
        }

        cout << data << endl;

        list<Node*> answer = lz_algorithm_encode(data);
        for (auto it = answer.begin() ; it != answer.end() ; ++it) {
            cout << (*it)->pos << ' ' << (*it)->next << ' ';
        }
        cout << endl << answer.size();
    } else {
        cout << "Can not open file: " << fileName << "!" << endl;
    }
}