#include "Shunting-yard.h"

using namespace std;

Queue* shunting_yard(char* expr) {

  char *str = new char;
  int j = 0;

  for (int i = 0; i < strlen(expr); i++) if (expr[i] != ' ') str[j++] = expr[i];


  Stack *stack = new Stack(strlen(str));
  Queue *queue = new Queue(strlen(str));
  char *num = new char;
  char *swap = new char;
  int k = 0; int i = 0;
  bool is_number = false;


  while (i < strlen(str)){

    if (((int)str[i] >= 48 && (int)str[i] <= 57) || (int)str[i] == 46){
      num[k] = str[i];
      k++; is_number = true;
    }

    else {
      if (is_number) {
        char *res = new char;
        strcpy(res, num);
        queue -> enqueue(res);
        delete num;
        num = new char;
        k = 0; is_number = false;
      }

      if (str[i] == '(') stack -> push(new char('('));

      if (str[i] == ')'){
        while (!stack -> isEmpty()){
          swap = stack -> pop();
          if (swap[0] == '(') break;
          queue -> enqueue(swap);
        }
      }

      else if (str[i] == '-' || str[i] == '+'){
        while(!stack -> isEmpty()){
          swap = stack -> pop();
          if (swap[0] == '('){
            stack -> push(swap);
            break;
          }
          queue -> enqueue(swap);
        }
        stack -> push(new char (str[i]));
      }

      else if (str[i] == '*' || str[i] == '/'){
        while(!stack -> isEmpty()){
          swap = stack -> pop();
          if (swap[0] == '-' || swap[0] == '+' || swap[0] == '('){
            stack -> push(swap);
            break;
          }
          queue -> enqueue(swap);
        }
        stack -> push(new char(str[i]));
      }

      else if (str[i] == '^') stack -> push(new char(str[i]));
    }
    i++;
  }

  if (is_number) queue -> enqueue(num);

  while (!stack -> isEmpty()) queue -> enqueue(stack -> pop());

  num = swap = nullptr;
  delete str; delete num; delete swap;
  delete stack;

  return queue;
}
