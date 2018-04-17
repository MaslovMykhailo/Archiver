#include "Shunting-yard.h"

using namespace std;

Queue* shunting_yard(char* expr) {
  char *str = new char;
  int j = 0;
  for (int i = 0; i < strlen(expr); i++){
    if (expr[i] != ' '){
      str[j] = expr[i];
      j++;
    }
  }
  Stack *stack = new Stack(strlen(str));
  Queue *que = new Queue(strlen(str));
  char *num = new char;
  int k = 0;
  int i = 0;
  bool is = false;
  while (i < strlen(str)){

    if ((int)str[i] >= 48 && (int)str[i] <= 57){
      num[k] = str[i];
      k++; is = true;
    }

    else {
      if (is) {
        char *res = new char;
        strcpy(res, num);
        que -> enqueue(res);
        delete num;
        num = new char;
        k = 0; is = false;
      }

      if (str[i] == '(') stack -> push(new char('('));

      if (str[i] == ')'){
        while (!stack -> isEmpty()){
          char *swap = stack -> pop();
          if (swap[0] == '(') break;
          que -> enqueue(swap);
        }
      }

      else if (str[i] == '-' || str[i] == '+'){
        while(!stack -> isEmpty()){
          char *swap = stack -> pop();
          if (swap[0] == '('){
            stack -> push(swap);
            break;
          }
          que -> enqueue(swap);
        }
        stack -> push(new char (str[i]));
      }

      else if (str[i] == '*' || str[i] == '/'){
        while(!stack -> isEmpty()){
          char *swap = stack -> pop();
          if (swap[0] == '-' || swap[0] == '+'){
            stack -> push(swap);
            break;
          }
          if (swap[0] == '('){
            stack -> push(swap);
            break;
          }
          que -> enqueue(swap);
        }
        stack -> push(new char(str[i]));
      }

      else if (str[i] == '^') stack -> push(new char(str[i]));

    }
    i++;
  }
  if (is){
    char *res = new char;
    strcpy(res, num);
    que -> enqueue(res);
  }
  while (!stack -> isEmpty()){
    char *swap = stack -> pop();
    que -> enqueue(swap);
  }
  return que;
}
