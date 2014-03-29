#ifndef Stack_H
#define Stack_H

typedef struct
{
	void *topOfStack;
}Stack;

Stack *createStack();
void *pop(Stack);
void push(Stack,void *data);
#endif // Stack_H
