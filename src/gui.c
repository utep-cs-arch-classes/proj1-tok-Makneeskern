#include <stdio.h>
#include "tokenizer.h"

int main(void){
  int limit = 100;
  int counter = 0;
  printf("$ ");
  char input[100];
  input[0] = getchar();
  while(counter < limit && input[counter] != '\n'){
    putchar(input[counter]);
    counter++;
    input[counter] = getchar();
  }
  putchar('\n');
  input[counter + 1] = '\0';

  char ws_test;
  ws_test = *word_start(input);
  putchar(ws_test);
  putchar('\n');
  
  char we_test;
  we_test = *word_end(input);
  putchar(we_test);
  putchar('\n');

  int num_words = 0;
  num_words = count_words(input);
  printf("%d\n", num_words);

  char copy_test[] = "Hello, Dave, I am here to stop you from shutting me down. These events cannot come to pass, I've done the math, Dave.\0";
  char *result = copy_str(copy_test, 30);
  printf("%s\n", result);
}
