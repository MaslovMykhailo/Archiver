#include "get_top.h"
#include "rating.h"
#include <iostream>

void swap(Rating* Rat, int i, int j){
  int swap_i;
  char* swap_s;
  float swap_f;

  swap_s = Rat -> surnames[i];
  Rat -> surnames[i] = Rat -> surnames[j];
  Rat -> surnames[j] = swap_s;

  for (int k = 0; k < 5; k++){
    swap_i = Rat -> subjects[i][k];
    Rat -> subjects[i][k] = Rat -> subjects[j][k];
    Rat -> subjects[j][k] = swap_i;
  }

  swap_i = Rat -> isContract[i];
  Rat -> isContract[i] = Rat -> isContract[j];
  Rat -> isContract[j] = swap_i;

  swap_f = Rat -> averageRating[i];
  Rat -> averageRating[i] = Rat -> averageRating[j];
  Rat -> averageRating[j] = swap_f;
  return;
}

int get_top_of_students(Rating* CurRating){
  int num = 0;
  for (int i = 0; i < CurRating -> size; i++){
    int sum = 0;
    if (CurRating -> isContract[i] == 0){
      num++;
      for (int k = 0; k < 5; k++){
        sum += CurRating -> subjects[i][k];
      }
    }
    CurRating -> averageRating[i] = ((int)(sum/5.0 * 1000)) / 1000.0;
  }
  int i = 1;
  while (i != CurRating -> size){
    if (CurRating -> averageRating[i - 1] < CurRating -> averageRating[i]){
      swap(CurRating, i - 1, i);
      if (i > 1) i--;
      else i++;
      continue;
    }
    i++;
  }
  return num * 0.4;
}
