#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  if(list->root == NULL){
    list->root = (Item*) malloc(sizeof(Item));
    list->root->next = NULL;
  }
  int counter = 0;
  Item current_entry = *(list->root);
  while(current_entry.next != NULL){
    current_entry = *(current_entry.next);
    counter++;
  }
  current_entry.id = counter;
  current_entry.str = str;
  current_entry.next = (Item*) malloc(sizeof(Item));
  current_entry.next->next = NULL;
}

char *get_history(List *list, int id){
}

void print_history(List *list){
}

void free_history(List *list){
}
