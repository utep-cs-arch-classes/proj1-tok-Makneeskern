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
  char *copy = (char *) malloc(sizeof(char) * len);
  for(;counter < len && *inStr != 0; counter++){
    *(copy + counter) = *(inStr + counter);
  }
  *(copy + len) = '\0';
  return copy;
}

char **tokenize(char* str){
  char holder = 'A';
  char *middleman = &holder;
  char **ptr = &middleman;
  return ptr;
}

void print_tokens(char **tokens){
  int counter = 0;
  while(*(tokens + counter) != 0){
    printf("%s\n",*(tokens + counter));
  }
}

void free_tokens(char **tokens){
}
