#include <stdio.c>
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
  while(space_char(*str)){
    str += 1;
  }
  return *str;
}

char *word_end(char *str){
  return 'A';
}

int count_words(char *str){
  return 0;
}

char *copy_str(char *inStr, short len){
  return 'A';
}

char **tokenize(chr* str){
  return 'A';
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
