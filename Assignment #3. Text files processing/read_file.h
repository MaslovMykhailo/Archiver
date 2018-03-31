#ifndef ASSIGNMENT_3_TEXT_FILES_PROCESSING_READ_FILE_H
#define ASSIGNMENT_3_TEXT_FILES_PROCESSING_READ_FILE_H


#include "string.h"
#include "stdio.h"
#include "rating.h"

Rating* read_file(char*);
void parse_buffer(char*, Rating*, int);

#endif //ASSIGNMENT_3_TEXT_FILES_PROCESSING_READ_FILE_H
