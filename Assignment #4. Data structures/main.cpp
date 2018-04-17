#include "Stack.h"
#include "Queue.h"
#include "Shunting-yard.h"
#include "Calculate-expression.h"
#include "Get-expression.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if (argc > 1) {
        cout << "Result: " << calculate_expr(shunting_yard(get_expr(argv))) << endl;
    } else {
        cout << "Invalid expression!" << endl;
    }
    return 0;
}