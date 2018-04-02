#include "rating.h"
#include "write_file.h"
#include "read_file.h"
#include "get_top.h"
#include <iostream>

using namespace std;

int main() {
    Rating* Current = read_file(const_cast<char *>("students.csv"));

    int num = get_top(Current);

    for (int i = 0 ; i < num ; i++) {
        cout << Current->surnames[i] << " - "
             << Current->averageRating[i] << endl;
    }

    cout << endl << "Мінімальний бал для стипендії: "
         << Current -> averageRating[num - 1] << endl;

    write_file((const_cast<char *>("rating.csv")), Current, num);

    delete Current;

    return 0;
}
