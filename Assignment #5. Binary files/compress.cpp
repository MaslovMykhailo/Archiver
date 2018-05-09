#include "compress.h"
#include "lz_algorithm.h"
#include "parse_hex.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void compress(char* fileName) {
    ifstream input (fileName, ios::binary);
    if (input.is_open()) {
        ofstream output ("1.txt", ios::binary);
        if (output.is_open()) {

            // determine input file length
            input.seekg (0, input.end);
            int length = input.tellg();
            input.seekg (0, input.beg);

            char oddChar;

            for (int i = 0 ; i < length ; i++) {
                char symbol;
                input.read(&symbol, sizeof(symbol));

                string hexStr = char_to_hex(symbol);

                string code = lz_algorithm_encode(hexStr);

                string part = hex_to_char(code, oddChar);

                for (int j = 0 ; j < part.size() ; j++) {
                    output.write(&part[j], sizeof(part[j]));
                }
            }

        } else {
            cout << "Can not create compressed file!" << endl;
        }
    } else {
        cout << "Can not open file: " << fileName << "!" << endl;
    }
}