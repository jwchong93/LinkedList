#include "Stack.h"
#include <malloc.h>
#include "LinkedList.h"

/*
* This following is a stack work based on Linked List.
* Here is some comments on how to use it.
* 
* First,a stack must be created before push and pop been use. Please use createStack() to finish this.
* If you want to add eleemnt inside, use push () , if wanna remove use pop().
* Rememeber to call destroyStack() before u end your program (To prevent memory leak)
* 
*/
Stack *createStack()
{
	LinkedList *list = createLinkedList();
	Stack *newStack = (Stack*)list;
	newStack->topOfStack = list->head;
	return newStack;
}

void push(Stack *stack, void * data)
{
	LinkedList *list = (LinkedList*)stack;
	Element *newElement = malloc(sizeof(Element));
	newElement->data = data;
	List_addFirst(newElement,list);
}

void *pop(Stack*stack)
{
	Element *elem;
	LinkedList *list = (LinkedList*)stack;
	if(list->head==NULL)
	{
		return NULL;
	}
	elem = List_removeFirst(list);
	return elem->data;
}

void destroyStack(Stack *stack)
{
	LinkedList *list = (LinkedList*)stack;
	List_DestroyList(list);
}