#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(void){
  int counter = 0;
  char *input = (char*) malloc(sizeof(char) * 100);

  while(counter < 100 && (*(input + counter) = getchar()) != '\n'){
    counter++;
  }

  *(input + counter+ 1) = '\0';
  char **tokens = tokenize(input);

  print_tokens(tokens);

  free_tokens(tokens);
  
}
