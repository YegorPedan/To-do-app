#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void push_number_to_stack(stack *st, int number) {
  stackNode *new_node = (stackNode *)malloc(sizeof(stackNode));
  new_node->itemContent.number = number;
  new_node->itemContent.operation = NULL;
  new_node->next = st->head;
  st->head = new_node; 
}

void push_operation_to_stack(stack *st, char* operation) {
  stackNode *new_node = (stackNode *)malloc(sizeof(stackNode));
  new_node->itemContent.number = 0;
  new_node->itemContent.operation = operation;
  new_node->next = st->head;
  st->head = new_node; 
}

stackItem pop_from_stack(stack *st) {
  stackItem tmp = st->head->itemContent;
  stackNode *tmp_node = st->head;
  st->head = st->head->next;
  free(tmp_node);
  return tmp;
}

void display_stack(stack *st) {
  stackNode *tmp = st->head;
  while (tmp != NULL) {
    if (tmp->itemContent.operation == NULL) {
      printf("%d -> ", tmp->itemContent.number);
    } else {
      printf("%s -> ", tmp->itemContent.operation);
    }
    tmp = tmp->next;
  }
}
