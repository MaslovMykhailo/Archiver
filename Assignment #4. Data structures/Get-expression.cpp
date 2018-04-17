#include "Get-expression.h"
#include <cstring>

char* get_expr(char** argv) {
    int i = 1;
    char* expr = argv[i++];

    while (argv[i]) {
        strcat(expr, argv[i++]);
    }

    return expr;
}