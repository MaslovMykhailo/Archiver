#include "Get-expression.h"
#include <cstring>
#include <iostream>
#include <string>

// char* get_expr(char** argv) {
//     int i = 1;
//     char* expr = argv[i++];
//
//     while (argv[i]) {
//         strcat(expr, argv[i++]);
//     }
//
//     return expr;
// }

char* get_expr(char** argv) {
  char *err = new char;

  strcpy(err, "err");

  int i = 1;
  char* expr = argv[i++];

  while (argv[i]) {
      strcat(expr, argv[i++]);
  }

  std::string result = "";
  for (int i = 0; i < strlen(expr); i++){
    if (expr[i] == '('){
      result.push_back(expr[i]);
    } else {
      if (expr[i] == ')'){
        try {
              if (result.length() != 0) result.erase(result.length() - 1);
              else throw 100;
          } catch(int i) {
              return err;
          }
      }
    }
  }
  try {
        if (result.length() != 0) throw 100;
    } catch(int i) {
        return err;
    }

  return expr;
}
