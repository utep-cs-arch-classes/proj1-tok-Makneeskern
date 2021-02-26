#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(void){
  char raw_in[100];
  int counter = 0;

  while(counter < 100 && (raw_in[counter] = getchar()) != '\n'){
    counter++;
  }

  char *input = raw_in;
  *(input + counter+ 1) = '\0';
  char **tokens = (char**)malloc(sizeof(char*) * (count_words(input) + 1));
  tokens = tokenize(input);
  printf("%s\n", *tokens);
}
