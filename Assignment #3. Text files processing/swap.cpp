void swap(Rating* Rat, int i, int j){
  int swap;
  char* swap_s;
  float swap_f;

  swap_s = Rat -> surnames[i];
  Rat -> surnames[i] = Rat -> surnames[j];
  Rat -> surnames[j] = swap_s;

  for (int k = 0; k < 5; k++){
    swap = Rat -> subjects[i][k];
    Rat -> subjects[i][k] = Rat -> subjects[j][k];
    Rat -> subjects[j][k] = swap;
  }

  swap = Rat -> isContract[i];
  Rat -> isContract[i] = Rat -> isContract[j];
  Rat -> isContract[j] = swap;

  swap_f = Rat -> averageRating[i];
  Rat -> averageRating[i] = Rat -> averageRating[j];
  Rat -> averageRating[j] = swap_f;
}
