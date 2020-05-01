#include "list.h"
#include <stdio.h>

void read_option_from_menu(char *option)
{
  printf("Main Menu\n---------\n");
  printf("%s\n%s\n",OPTION_A,OPTION_M);
  scanf("%c", option);
  while ((getchar()) != '\n');
}

void read_input(int *input, char *msg)
{
  printf("%s", msg);
  scanf("%d", input);
}

void perform_operation(char option, List_ptr list)
{
  int value;
  switch (option)
  {
  case 'a':
    read_input(&value, VALUE_MSG);
    add_to_end(list, value);
    break;
  case 'm':
    break;
  default:
    break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  char option;
  read_option_from_menu(&option);

  while (option != 'm')
  {
    perform_operation(option, list);
    read_option_from_menu(&option);
  }
  
  return 0;
}