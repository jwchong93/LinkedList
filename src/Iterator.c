#include "Iterator.h"
#include "LinkedList.h"
#include <malloc.h>

/*
#############################################################################################################
# The follwing is an iterator implementation which view the elements inside a linked list.					#
# Here is some comments on how to use it.																	#
# 																											#
# First,an iteraotr should be created using getIterator()													#
#																											#
# PLEASE MAKE SURE THE LINKED LIST CONTAIN AT LEAST ONE ELEMENT.											#
#																											#
# The function getNext will view the next element in the linked list without remove it from linked list		#
# Remember to call destroyIterator() before you end your program (To prevent memory leak)						#
# 																											#
#############################################################################################################
*/

/*
	Create a new Iterator
	
	Input: list				The target linked list(at least one element)
	
	Output: none
	
	Return: newIterator		A new created Iterator that used to view the data inside.
*/
Iterator *getIterator(LinkedList *list)
{
	Iterator *newIterator = malloc(sizeof(Iterator));
	newIterator->list =list;
	newIterator->current = list->head;
	newIterator->next = &getNext;
	return newIterator;
}

/*
	View the next data of the element
	
	Input: current			pointer to an element
	
	Output: none
	
	Return: temp 			The next location of current
*/

Element *getNext(Element *current)
{
	Element *temp;
	temp=current->next;
	return temp;
}

/*
	Destroy the data inside the iterator 
	
	Input: iter		Iterator that going to be destroyed
	
	Output: none
	
	Return: none
*/
void destroyIterator(Iterator *iter)
{
	List_DestroyList(iter->list);
	free(iter);
}