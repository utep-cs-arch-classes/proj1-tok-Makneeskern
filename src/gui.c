#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(void){
  int counter = 0;
  char *input = (char*) malloc(sizeof(char) * 100);

  while(counter < 100 && (*(input + counter) = getchar()) != '\n'){
    counter++;
  }

  *(input + counter+ 1) = '\0';
  char **tokens = tokenize(input);

  print_tokens(tokens);

  List *history = init_history();
  counter = 0;
  while(*(tokens + counter) != 0){
    add_history(history, *(tokens + counter));
    counter++;
  }

  printf("Everything went off without a hitch...\nhopefully.");
}
