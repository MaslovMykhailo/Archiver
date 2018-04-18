#include "Stack.h"
#include "Queue.h"
#include "Shunting-yard.h"
#include "Calculate-expression.h"
#include "Get-expression.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if (argc > 1) {
        char* expr = get_expr(argv);
        if (strcmp(expr, "err") == 0) cout << "Braces validation error" << endl;
        else cout << "Result: " << calculate_expr(shunting_yard(expr)) << endl;
    } else {
        cout << "Invalid expression!" << endl;
    }
    return 0;
}
