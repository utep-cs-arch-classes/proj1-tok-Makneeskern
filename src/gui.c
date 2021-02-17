#include <stdio.h>

int main(void){
  printf("$ ");
  char input = getchar();
  while(1){
    while(input != '\0'){
      if (input == '|'){return 1;}
      putchar(input);
      input = getchar();
    }
    putchar('\n');
  }
  putchar('\n');
}
