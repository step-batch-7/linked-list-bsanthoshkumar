#ifndef __LIST_H
#define __LIST_H

#define OPTION_A "(a) add a number to the end of the list"
#define OPTION_B "(b) add a number to the start of the list"
#define OPTION_C "(c) insert a number at a given position in the list"
#define OPTION_D "(d) add a unique item on the list at the end(if it alreay exists, do not insert)"
#define OPTION_E "(e) remove a number from the beginning of the list"
#define OPTION_F "(f) remove a number from the end of the list"
#define OPTION_G "(g) remove a number from a given position in the list"
#define OPTION_H "(h) remove first occurrence of a number"
#define OPTION_J "(j) clear the whole list"
#define OPTION_K "(k) check if a number exists in the list"
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

typedef struct {
  Node_ptr prev;
  Node_ptr current;
} Prev_Current_Pair;

typedef Prev_Current_Pair *Prev_Current_Pair_ptr;

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

void check_number_exists(List_ptr, int value);

#endif