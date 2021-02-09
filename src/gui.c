#include <stdio.h>

int main(void){
  printf("$ ");
  char input = getchar();
  while(input != '\n'){
    if(input == ' '){
      putchar('\n');
    }
    else{
      putchar(input);
    }
    input = getchar();
  }
  putchar('\n');
  return 0;
}
