#include "Stack.h"
#include <malloc.h>
#include "LinkedList.h"

Stack *createStack()
{
	LinkedList *list = createLinkedList();
	Stack *newStack = (Stack*)list;
	newStack->topOfStack = list->head;
	return newStack;
}

void push(Stack *stack, Element * data)
{
	LinkedList *list = (LinkedList*)stack;
	List_addFirst(data,list);
}

void *pop(Stack*stack)
{
	Element *elem;
	LinkedList *list = (LinkedList*)stack;
	elem = List_removeFirst(list);
	return elem;
}

void destroyStack(Stack *stack)
{
	LinkedList *list = (LinkedList*)stack;
	List_DestroyList(list);
}