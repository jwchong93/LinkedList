#ifndef Stack_H
#define Stack_H
#include "LinkedList.h"

typedef struct
{
	Element *topOfStack;
}Stack;

Stack *createStack();
void destroyStack(Stack *stack);
void *pop(Stack*stack);
void push(Stack *stack,Element *data);
#endif // Stack_H
