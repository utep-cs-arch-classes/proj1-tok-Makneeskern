#include <stdio.h>

int main(void){
  char input = getchar();
  while(input != EOF){
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