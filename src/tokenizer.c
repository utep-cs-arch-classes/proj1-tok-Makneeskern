#include <stdio.h>
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
/*
char *copy_str(char *inStr, short len){
  return 'A';
}

char **tokenize(char* str){
  char holder = 'A';
  char **ptr = &holder;
  return ptr;
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
*/
