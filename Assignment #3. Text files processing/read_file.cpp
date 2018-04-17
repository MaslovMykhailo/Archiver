#include "read_file.h"
#include <iostream>

Rating* read_file(char *fileName) {
    FILE *pFile;
    char buffer[125];

    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        perror("Error opening file");
        return NULL;
    }
    else {
        fgets(buffer, 125, pFile);
        int size; sscanf(buffer, "%d", &size);

        Rating* CurRating = new Rating(size, 64);

        for (int i = 0 ; i < size ; i++) {
            fgets(buffer, 125, pFile);
            parse_buffer(buffer, CurRating, i);
        }

        fclose(pFile);
        return CurRating;
    }
}

void parse_buffer(char* buffer, Rating* CurRating, int curIndex) {
    char * ptr1 = strtok(buffer, ",");
    char * ptr2 = ptr1;

    if (ptr1 != NULL) {
        ptr1 = strtok(NULL, ",");
        strncpy(CurRating->surnames[curIndex], ptr2, ptr1 - ptr2);
    }

    char *substr = new char[10];

    for (int i = 0 ; i < 5 ; i++) {
        ptr2 = ptr1;
        ptr1 = strtok(NULL, ",");
        strncpy(substr, ptr2, ptr1 - ptr2);
        int value; sscanf(substr, "%d", &value);
        CurRating->subjects[curIndex][i] = value;
    }

    ptr2 = ptr1;
    while ((*ptr1) != '\0') ptr1++;
    strncpy(substr, ptr2, ptr1 - ptr2);
    CurRating->isContract[curIndex] = strlen(substr) < 6 ? 1 : 0;

    delete []substr;
}
