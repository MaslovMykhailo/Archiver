#include <cmath>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "Calculate-expression.h"

char* calculate_expr(Queue* queue) {
    Stack* stack = new Stack(queue->getSize());

    if (!queue->isEmpty()) {
        stack->push(queue->dequeue());
        stack->push(queue->dequeue());

        while (!queue->isEmpty()) {
            char* symbol = queue->dequeue();
            if ((int)symbol[0] >= 48 && (int)symbol[0] <= 57) {
                stack->push(symbol);
            } else {
                char* n2 = stack->pop(); char* n1 = stack->pop();
                stack->push(implement_operator(symbol[0], n1, n2));
            }
        }
    }

    char* result = new char;
    strcpy(result, stack->pop());
    delete stack;

    return result;
}

char* implement_operator(char symbol, char* n1, char* n2) {
    char* ptr;
    double first = strtod(n1, &ptr);
    double second = strtod(n2, &ptr);
    std::stringstream str;

    switch (symbol) {
        case '+': {
            str << first + second;
            break;
        }
        case '-': {
            str << first - second;
            break;
        }
        case '*': {
            str << first * second;
            break;
        }
        case '/': {
            str << first / second;
            break;
        }
        case '^': {
            str << pow(first, second);
            break;
        }
        default: {
            str << ' ';
        }
    }
    char* result = new char;
    strcpy(result, str.str().c_str());
    return result;
}
