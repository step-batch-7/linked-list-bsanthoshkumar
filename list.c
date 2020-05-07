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
  if (list->head == NULL)
  {
    list->head = newnode;
  }
  else
  {
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
  if (list->last == NULL)
  {
    list->last = newnode;
  }
  list->count++;

  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position < 0 || position > list->count)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }

  int temp = 1;
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->head;

  while (temp <= position)
  {
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
  Node_ptr current = list->head;
  while (current != NULL)
  {
    if (current->value == value)
    {
      return Failure;
    }
    current = current->next;
  }

  return add_to_end(list, value);
}

void display(List_ptr list)
{
  if (list->head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("List : ");
  Node_ptr current = list->head;
  while (current != NULL)
  {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

Status remove_from_start(List_ptr list)
{
  if (list->head == NULL)
  {
    return Failure;
  }

  Node_ptr node = list->head;
  list->head = list->head->next;
  if (list->count == 1)
  {
    list->last = list->head;
  }
  list->count--;
  free(node);

  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->last == NULL)
  {
    return Failure;
  }

  if (list->count == 1)
  {
    return remove_from_start(list);
  }

  Node_ptr current = list->head;
  while (current->next != list->last)
  {
    current = current->next;
  }

  list->last = current;
  current = current->next;
  list->last->next = NULL;
  list->count--;
  free(current);

  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (position < 0 || position >= list->count)
  {
    return Failure;
  }

  if (position == 0)
  {
    return remove_from_start(list);
  }

  int temp = 1;
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->head;

  while (temp <= position)
  {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    temp++;
  }

  pair->prev->next = pair->current->next;
  if (pair->prev->next == NULL)
  {
    list->last = pair->prev;
  }

  free(pair->current);
  list->count--;

  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int position = 0;
  Node_ptr current = list->head;
  while (current != NULL)
  {
    if (current->value == value)
    {
      return remove_at(list, position);
    }
    current = current->next;
    position++;
  }

  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  int removed_count = 0;
  int result = Success;
  while (result != Failure)
  {
    result = remove_first_occurrence(list, value);
    result &&removed_count++;
  }

  if (removed_count == 0)
  {
    return Failure;
  }

  return Success;
}

Status clear_list(List_ptr list)
{
  if (list->head == NULL)
  {
    return Failure;
  }

  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->head;
  while (pair->current != NULL)
  {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    free(pair->prev);
  }

  list->head = NULL;
  list->last = NULL;

  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}

void check_number_exists(List_ptr list, int value)
{
  int count = 0;
  Node_ptr current = list->head;
  while (current != NULL)
  {
    if (current->value == value)
    {
      printf("%d is present in the list at position %d\n", value, count);
      return;
    }
    current = current->next;
    count++;
  }
  printf("%d is not present in the list\n", value);
}