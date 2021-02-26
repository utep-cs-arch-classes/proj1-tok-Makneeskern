#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == ' ' || c == '\n' || c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != ' ' && c != '\n' && c != '\t' && c != '\0'){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  while(non_space_char(*str)){
    str += 1;
  }
  while(space_char(*str)){
    str += 1;
  }
  return str;
}

char *word_end(char *str){
  if(space_char(*str)){
    str = word_start(str);
  }
  while(non_space_char(*str)){
    str += 1;
  }
  return str;
}

int count_words(char *str){
  int words = 0;
  if(non_space_char(*str)){
    words += 1;
  }
  while(*str != '\0'){
    str = word_start(str);
    words += 1;
  }
  words -= 1;
  return words;
}

char *copy_str(char *inStr, short len){
  short counter = 0;
  char *copy = (char *) malloc(sizeof(char) * len + 1);
  for(;counter < len; counter++){
    *(copy + counter) = *(inStr + counter);
  }
  *(copy + counter) = '\0';
  return copy;
}

char **tokenize(char* str){
  int num_words = count_words(str);
  char **tokens = (char**) malloc(sizeof(char*) * (num_words + 1));
  int counter = 0;
  char *next_word;
  char *copy;
  if(non_space_char(*str)){
    next_word = str;
  }
  else{
    next_word = word_start(str);
  }

  while(counter < num_words){
    copy = copy_str(next_word, word_end(next_word) - next_word);
    *(tokens + counter) = copy;
    printf("%s\n", *(tokens + counter));
    next_word = word_start(next_word);
    counter++;
  }
  *(tokens + counter) = '\0';
  printf("Method complete\n");
}

void print_tokens(char **tokens){
  int words = 0;
  while(*(tokens + words) != 0){
    printf("%s\n", *(tokens + words));
    words++;
  }
}

void free_tokens(char **tokens){
}
