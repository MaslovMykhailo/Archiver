#include "compress.h"
#include "lz_algorithm.h"
#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

void compress(char* inputFileName, char* outputFileName) {
    ifstream input (inputFileName, ios::binary);
    if (input.is_open()) {

        // determine length of file
        input.seekg (0, input.end);
        int length = input.tellg();
        input.seekg (0, input.beg);

        list<Node *> pairs;

        for (int i = 0; i < length; i++) {
            char symbol;
            input.read(&symbol, sizeof(symbol));
            lz_algorithm_encode(symbol, &pairs);
        }
        input.close();

        ofstream output(outputFileName, ios::binary);
        if (output.is_open()) {
            int counter = 0;
            for (auto it = pairs.begin(); it != pairs.end(); ++it) {
                int p = (*it)->pos;
                char c = (*it)->next;

                if (counter > 255) {
                    string bitStr = bitset<16>(p).to_string();
                    string first = bitStr.substr(0, 8);
                    string second = bitStr.substr(8, 8);

                    char f = (char) bitset<8>(first).to_ulong();
                    char s = (char) bitset<8>(second).to_ulong();

                    output.write(&f, sizeof(f));
                    output.write(&s, sizeof(s));
                } else {
                    char r = (char) (p - 127);
                    output.write(&r, sizeof(r));
                }
                output.write(&c, sizeof(c));

                counter++;
            }
            output.close();
        } else {
            cout << "Can not create file: " << outputFileName << endl;
        }
    } else {
        cout << "Can not open file: " << inputFileName << "!" << endl;
    }
}