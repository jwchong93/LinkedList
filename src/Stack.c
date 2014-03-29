#include "Stack.h"
#include <malloc.h>
#include "LinkedList.h"

/*
#############################################################################################################
# This following is a stack work based on Linked List.														#
# Here is some comments on how to use it.																	#
# 																											#
# First,a stack must be created before push and pop been use. Please use createStack() to finish this.		#
# If you want to add element inside, use push () , if want to remove use pop().								#
# Remember to call destroyStack() before you end your program (To prevent memory leak)						#
# 																											#
#############################################################################################################
*/

/*
	Create a new Stack
	
	Input: none
	
	Output: none
	
	Return: newStack		A new created stack that used to store pushed data.
*/
Stack *createStack()
{
	LinkedList *list = createLinkedList();
	Stack *newStack = (Stack*)list;
	newStack->topOfStack = list->head;
	return newStack;
}

/*
	Push new data into the stack
	
	Input: stack			Which will store the data.
			data			The address of the data that need to be store inside the stack
	
	Output: none
	
	Return: none
*/
void push(Stack *stack, void * data)
{
	LinkedList *list = (LinkedList*)stack;
	Element *newElement = malloc(sizeof(Element));
	newElement->data = data;
	List_addFirst(newElement,list);
}

/*
	Pop out the first element in the stack
	
	Input: stack			Which stored the wanted data.
	
	Output: none
	
	Return: elem->data		Which data that store inside the element
*/
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

/*
	Destroy all the element inside the stack
	
	Input: stack			Stack that going to be destroyed
	
	Output: none
	
	Return: none
*/
void destroyStack(Stack *stack)
{
	LinkedList *list = (LinkedList*)stack;
	List_DestroyList(list);
}