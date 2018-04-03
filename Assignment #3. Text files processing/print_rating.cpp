#include "print_rating.h"

void print_rating(Rating* Cur, int count) {
    for (int i = 0 ; i < count ; i++) {
        std::cout << Cur->surnames[i] << " - "
                  << Cur->averageRating[i] << std::endl;
    }

    std::cout << std::endl << "Мінімальний бал для стипендії: "
              << Cur -> averageRating[count - 1] << std::endl;

    return;
}