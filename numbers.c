#include "list.h"
#include <stdio.h>

void read_option_from_menu(char *option)
{
  printf("Main Menu\n---------\n");
  printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", OPTION_A, OPTION_B, OPTION_C, OPTION_D, OPTION_E, OPTION_F, OPTION_G);
  printf("%s\n%s\n%s\n%s\n%s\n%s\n", OPTION_H, OPTION_I, OPTION_J, OPTION_K, OPTION_L, OPTION_M);
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

  case 'd':
    read_input(&value, VALUE_MSG);
    add_unique(list, value);
    break;

  case 'e':
    remove_from_start(list);
    break;

  case 'f':
    remove_from_end(list);
    break;

  case 'g':
    read_input(&position, POSITION_MSG);
    remove_at(list, position);
    break;

  case 'h':
    read_input(&value, VALUE_MSG);
    remove_first_occurrence(list, value);
    break;

  case 'i':
    read_input(&value, VALUE_MSG);
    remove_all_occurrences(list, value);
    break;
  
  case 'j':
    clear_list(list);
    break;

  case 'k':
    read_input(&value, VALUE_MSG);
    check_number_exists(list, value);
    break;

  case 'l':
    display(list);
    break;

  case 'm':
    destroy_list(list);
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