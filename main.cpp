#include <iostream>
#include "cstring"
#include "src/compress.h"
#include "src/decompress.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc > 1) {
        char* mode = argv[1];
        char* inputFileName = argv[2];
        char* outputFileName = argv[3];

        if (std::strcmp(mode, "--compress") == 0) {
            compress(inputFileName, outputFileName);
        }

        if (std::strcmp(mode, "--decompress") == 0) {
            decompress(outputFileName, inputFileName);
        }

    } else {
        cout << "Invalid arguments!" << endl;
    }
    return 0;
}