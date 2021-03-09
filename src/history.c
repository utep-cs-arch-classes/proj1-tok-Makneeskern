#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *history = (List*) malloc(sizeof(List));
  history->root = (Item*) malloc(sizeof(Item));
  history->root->id = -1;
  return history;
}

void add_history(List *list, char *str){
  int counter = 0;
  Item *current_entry = list->root;
  while(current_entry->id != -1){
    current_entry = current_entry->next;
    counter++;
  }
  current_entry->id = counter;
  current_entry->str = str;
  current_entry->next = (Item*) malloc(sizeof(Item));
  current_entry->next->id = -1;
}

char *get_history(List *list, int selected_id){
  Item *current_entry = list->root;
  while(current_entry->id != -1){
    if(current_entry->id == selected_id){
      return current_entry->str;
    }
    current_entry = current_entry->next;
  }
  printf("Invalid ID entered.");
  return "\0";
}

void print_history(List *list){
  Item current_entry = *(list->root);
  while(current_entry.next != NULL){
    printf("%s\n", current_entry.str);
    current_entry = *(current_entry.next);
  }
}

void free_history(List *list){
  free(list);
}
