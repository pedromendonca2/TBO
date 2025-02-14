#ifndef STACK_H
#define STACK_H

#include "item.h"

typedef struct stack Stack;

Stack* stack_create();
void stack_destroy(Stack*);
int stack_size(Stack*);
void push(Stack*, Item);
Item pop(Stack*);
Item peek(Stack*);

#endif
