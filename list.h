#ifndef __LIST_H
#define __LIST_H

#define OPTION_A "(a) add a number to the end of the list"
#define OPTION_L "(l) display the list of numbers"
#define OPTION_M "(m) exit"

#define VALUE_MSG "> Enter a value: "
#define POSITION_MSG "> Enter a position: "

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

void read_option_from_menu(char *);

List_ptr create_list(void);

Status add_to_end(List_ptr, int value);
Status add_to_start(List_ptr, int value);
Status insert_at(List_ptr, int value, int position);
Status add_unique(List_ptr, int value);

void display(List_ptr);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);

Status remove_first_occurrence(List_ptr, int value);
Status remove_all_occurrences(List_ptr, int value);

Status clear_list(List_ptr); // Removes all elements in the list

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif