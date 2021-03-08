#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(void){
  int counter = 0;
  int new_instruction = 0;
  int id_len = 0;
  char *input = (char*) malloc(sizeof(char) * 100);
  char *instruction_start;
  List *history = init_history();
  char **tokens;
  printf("Type \"|C\" to see the full list of commands.\n");
  while(1){
    new_instruction = 0;
    counter = 0;
    printf("$ ");
    while((*(input + counter) = getchar()) != '\n' && counter < 100){
      if(*(input + counter) == '|'){
	instruction_start = input + counter;
	new_instrction = 1;
      }
      counter++;
    }
    add_history(history, input);
    tokens = tokenize(input);
    print_tokens(tokens);
    if (new_instruction == 1){
      new_instruction = input_command(instruction_start);
    }
    switch (new_instruction){
    case -1 :
      //Invalid command
      printf("Sorry, The command you input was unrecognized. For a complete list of valid commands type \"|C\".");
      break;
    case 1:
      //Quit
      printf("Thank you for your time. Have a great day! :)");
      return;
    case 2:
      //free tokens
      free_tokens(tokens);
      printf("Tokens freed!");
      break;
    case 3:
      //print all elements in history
      print_history(history);
      break;
    case 4:
      //print element with X id in History
      id_len = (word_end(instruction_start + 2) - (instruction_start + 2));
      instruction_start = copy_str(instruction_start + 2, id_len);
      instruction_start = get_history(history, (int)instruction_start);
      printf("%s\n", instruction_start);
      break;
    case 5:
      //free History
      free_history(history);
      break;
    }
  }
}

int input_command(char *in){
  if(*(in + 1) == 'C'){
    commands();
  }
  else if(*(in + 1) == 'J'){
    joke();
  }
  else if(*(in + 1) == 'Q'){
    return 1;
  }
  else if(*(in + 1) == 'T'){
    else if(*(in + 2) == 'F'){
      return 2;
    }
    else return -1;
  }
  else if(*(in + 1) == 'H'){
    if(*(in + 2) == 'A'){
      return 3;
    }
    else if(*(in+2) < 58 && *(in+2) > 46){
      return 4;
    }
    else if(*(in + 2) == 'F'){
      return 5;
    }
    else return -1;
  }
  else return -1;
  return 0;
}

void commands(void){
  printf("All commands will only be accepted if the letter of the desired action immediately follows the \"|\" (Bitwise OR).");
  printf("The last instruction in any given input will be the one that gets executed.");
  printf("\"|C\": list commands.\n");
  printf("\"|Q\": Quit program.\n");
  printf("\"|TF\": Free all currently saved tokens.\n");
  printf("\"|HA\": Print all elements currently saved in history.\n");
  printf("\"|HX\": Print item in history with id X. Items are indexe starting at 0.\n");
  printf("\"|HF\": Free all currently saved Items in history.");
  printf("\"|J\": Joke\n");
}

void joke(void){
  printf("The joke is that you believed this command would do anything funny.");
}

void quit(char **tokens, List *history){
  printf("Thank you for participating. Goodbye.");
  free_tokens(tokens);
  free_history(history);
}
