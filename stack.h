#ifndef Stack
#define Stack

typedef  struct StackItem{
  int number;
  char *operation;
} stackItem;

typedef struct StackNode {
  stackItem itemContent;
  struct StackNode* next;
} stackNode;

typedef struct Stack {
  stackNode *head;
} stack;

void push_number_to_stack(stack *st, int number);
void display_stack(stack *st);
void push_operation_to_stack(stack *st, char* operation);
stackItem pop_from_stack(stack *st);
# endif
