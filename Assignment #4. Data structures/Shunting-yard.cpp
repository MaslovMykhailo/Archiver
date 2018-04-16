#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Stack.h"
#include "Queue.h"

using namespace std;

Queue* shunting_yard(char* expr){
  char *str = new char;
  int j = 0;
  for (int i = 0; i < strlen(expr); i++){
    if (expr[i] != ' '){
      str[j] = expr[i];
      j++;
    }
  }
  Stack *stack = new Stack(strlen(str));
  Queue *que = new Queue(strlen(str) + 1);
  char *num = new char;
  int k = 0;
  int i = 0;
  bool is = false;
  while (i < strlen(str)){
    if ((int)str[i] >= 48 && (int)str[i] <= 57){
      num[k] = str[i];
      k++;
      is = true;
    } else {
      if (is) {
        char *res = new char;
        strcpy(res, num);
        que -> enqueue(res);
        for (int j = 0; j < strlen(num); j++){
          num[j] = ' ';
        }
        k = 0;
        is = false;
      }
      if (str[i] == '(') stack -> push('(');
      if (str[i] == ')'){
        while (!stack -> isEmpty()){
          char *swap = new char;
          swap[0] = stack -> pop();
          if (swap[0] == '(') break;
          que -> enqueue(swap);
        }
      }
      else if (str[i] == '-' || str[i] == '+'){
        while(!stack -> isEmpty()){
          char *swap = new char;
          swap[0] = stack -> pop();
          if (swap[0] == '+' || swap[0] == '-' || swap[0] == '('){
            stack -> push(swap[0]);
            break;
          }
          que -> enqueue(swap);
        }
        stack -> push(str[i]);
      }
      else if (str[i] == '*' || str[i] == '/'){
        while(!stack -> isEmpty()){
          char *swap = new char;
          swap[0] = stack -> pop();
          if (swap[0] == '+' || swap[0] == '-' || swap[0] == '('){
            stack -> push(swap[0]);
            break;
          }
          que -> enqueue(swap);
        }
        stack -> push(str[i]);
      }
      else if (str[i] == '^'){
        stack -> push(str[i]);
      }
    }
    i++;
  }
  if (is){
    char *res = new char;
    strcpy(res, num);
    que -> enqueue(res);
  }
  while (!stack -> isEmpty()){
    char *swap = new char;
    swap[0] = stack -> pop();
    que -> enqueue(swap);
  }
  return que;
}

// int main(int argc, char* argv[]){
//   char expr[] = "(3 + 4) * (5 ^ 6)";
//   Queue *q = shunting_yard(expr);
//   q -> show();
// }
