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

  return Success;
}