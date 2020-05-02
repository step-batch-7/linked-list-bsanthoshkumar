#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List_ptr create_list()
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  return list;
}

Node_ptr create_newnode(int value)
{
  Node_ptr newnode = malloc(sizeof(Node));
  newnode->value = value;
  newnode->next = NULL;
  return newnode;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr newnode = create_newnode(value);
  if(list->head == NULL )
  {
    list->head = newnode;
  } else {
    list->last->next = newnode;
  }
  list->last = newnode;
  list->count++;

  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr newnode = create_newnode(value);
  newnode->next = list->head;
  list->head = newnode;
  if(list->last ==  NULL)
  {
    list->last = newnode;
  }
  list->count++;

  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if(position < 0 || position > list->count)
  {
    return Failure;
  }
  if(position == 0)
  {
    return add_to_start(list, value);
  }

  int temp = 1;
  Prev_Current_Pair *pair = malloc(sizeof(Prev_Current_Pair));
  pair->prev = list->head;
  pair->current = list->head;

  while(temp <= position) {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    temp++;
  }

  Node_ptr newnode = create_newnode(value);
  pair->prev->next = newnode;
  newnode->next = pair->current;
  list->count++;

  return Success;
}

Status add_unique(List_ptr list, int value)
{
  if(list->last != NULL && list->last->value == value)
  {
    return Failure;
  }

  return add_to_end(list, value);
}

void display(List_ptr list)
{
  if(list->head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("List : ");
  Node_ptr current = list->head;
  while(current != NULL)
  {
    printf("%d ",current->value);
    current = current->next;
  }
  printf("\n");
}

Status remove_from_start(List_ptr list)
{
  if(list->head == NULL)
  {
    return Failure;
  }

  Node_ptr node = list->head;
  list->head = list->head->next;
  if(list->count == 1)
  {
    list->last = list->head;
  }
  free(node);

  return Success; 
}