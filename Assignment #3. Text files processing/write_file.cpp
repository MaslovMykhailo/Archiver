#include "write_file.h"
#include <iostream>

void write_file(char fileName[], Rating* CurRating, int num){
  FILE *pFile;
  pFile = fopen(fileName, "w");
  char* result;
  char buffer[10];
  for (int i = 0; i < num; i++){
    result = CurRating -> surnames[i];
    sprintf(buffer, "%.3f", CurRating -> averageRating[]);
    result[strlen(result)] = ' ';
    strcat(result, buffer);
    result[strlen(result)] = '\n';
    fputs(result, pFile);
  }
  fclose(pFile);
}
