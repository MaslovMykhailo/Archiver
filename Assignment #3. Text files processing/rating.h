#ifndef ASSIGNMENT_3_TEXT_FILES_PROCESSING_RATING_H
#define ASSIGNMENT_3_TEXT_FILES_PROCESSING_RATING_H


struct Rating {
    Rating(int, int);
    int size;
    char **surnames;
    int **subjects;
    int *isContract;
    float *averageRating;
    ~Rating();
};


#endif //ASSIGNMENT_3_TEXT_FILES_PROCESSING_RATING_H
