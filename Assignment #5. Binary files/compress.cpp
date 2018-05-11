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

        list<Node *> a1;

        for (int i = 0; i < length; i++) {
            char symbol;
            input.read(&symbol, sizeof(symbol));
//
//            int charCode = (int)symbol;
//            string bits = bitset<8>(charCode).to_string();
//
//            for (int j = 0 ; j < bits.size(); j++) {
//                lz_algorithm_encode(bits[j], &a1);
//            }

            lz_algorithm_encode(symbol, &a1);
        }

//        cout << data << endl;
//        cout << endl;

        ofstream output("output.txt", ios::binary);

        int counter = 0;
        for (auto it = a1.begin() ; it != a1.end() ; ++it) {
//            cout << (*it)->pos << ' ' << (*it)->next << endl;
            int p = (*it)->pos;
            char c = (*it)->next;


            if (counter > 255) {
                string bitStr = bitset<16>(p).to_string();
                string first = bitStr.substr(0, 8);
                string second = bitStr.substr(8, 8);

                int f = bitset<8>(first).to_ulong();
                int s = bitset<8>(second).to_ulong();

//                if (f == 7 && s == 7) cout << "pizda" << endl;
//            cout << f-127 << ' ' << s-127 << endl;

                char fi = (char) f;
                char se = (char) s;

//                cout << f << ' ' << s << endl;

                output.write(&fi, sizeof(fi));
                output.write(&se, sizeof(se));
            } else {
//                cout << p << endl;
                char r = (char)(p-127);
                output.write(&r, sizeof(r));
            }
            output.write(&c, sizeof(c));

            counter++;
        }

        cout << endl << a1.size() << endl;
    } else {
        cout << "Can not open file: " << fileName << "!" << endl;
    }
}