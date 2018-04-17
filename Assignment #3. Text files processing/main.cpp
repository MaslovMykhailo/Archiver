#include "rating.h"
#include "write_file.h"
#include "read_file.h"
#include "get_top.h"
#include "print_rating.h"

char* inputFileName = const_cast<char *>("students.csv");
char* outputFileName = const_cast<char *>("rating.csv");

int countOfBestStudents;

int main() {
    Rating* Current = read_file(inputFileName);

    countOfBestStudents = get_top_of_students(Current);

    print_rating(Current, countOfBestStudents);

    write_file(outputFileName, Current, countOfBestStudents);

    delete Current;

    return 0;
}
