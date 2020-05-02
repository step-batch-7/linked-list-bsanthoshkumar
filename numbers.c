#include "list.h"
#include <stdio.h>

void read_option_from_menu(char *option)
{
  printf("Main Menu\n---------\n");
  printf("%s\n%s\n%s\n%s\n%s\n", OPTION_A, OPTION_B, OPTION_C, OPTION_L, OPTION_M);
  scanf("%c", option);
  while ((getchar()) != '\n');
}

void read_input(int *input, char *msg)
{
  printf("%s", msg);
  scanf("%d", input);
  while ((getchar()) != '\n');
}

void perform_operation(char option, List_ptr list)
{
  int value, position;
  switch (option)
  {
  case 'a':
    read_input(&value, VALUE_MSG);
    add_to_end(list, value);
    break;

  case 'b':
    read_input(&value, VALUE_MSG);
    add_to_start(list, value);
    break;

  case 'c':
    read_input(&value, VALUE_MSG);
    read_input(&position, POSITION_MSG);
    insert_at(list, value, position);
    break;

  case 'l':
    display(list);
    break;

  case 'm':
    break;

  default:
    printf("Invalid option\n");
    break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  char option;

  do
  {
    read_option_from_menu(&option);
    perform_operation(option, list);
  } while (option != 'm');
  
  return 0;
}