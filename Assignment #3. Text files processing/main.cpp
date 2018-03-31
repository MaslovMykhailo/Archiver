#include "rating.h"
#include "read_file.h"
#include <iostream>

using namespace std;

int main() {
    Rating* Current = read_file(const_cast<char *>("students.csv"));

    for (int i = 0 ; i < Current->size ; i++) {
        cout << Current->surnames[i] << ' '
             << Current->subjects[i][0] << ' '
             << Current->subjects[i][1] << ' '
             << Current->subjects[i][2] << ' '
             << Current->subjects[i][3] << ' '
             << Current->subjects[i][4] << ' '
             << Current->isContract[i]
             << endl;
    }

    delete Current;

    return 0;
}