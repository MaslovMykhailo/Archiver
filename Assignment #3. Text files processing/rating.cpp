#include "rating.h"

Rating::Rating(int size, int maxStrSize) {
    this->size = size;
    this->surnames = new char * [this->size];
    this->subjects = new int * [this->size];
    for (int i = 0 ; i < this->size ; i++) {
        this->surnames[i] = new char [maxStrSize];
        this->subjects[i] = new int [5];
    }
    this->isContract = new int [this->size];
    this -> averageRating = new float [this->size];
}

Rating::~Rating() {
    for (int i = 0 ; i < this->size ; i++) {
        delete []this->surnames[i];
        delete []this->subjects[i];
    }
    delete []this->isContract;
    delete []this->averageRating;
}
