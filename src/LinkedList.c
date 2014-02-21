#include "LinkedLIst.h"
#include <stdio.h>
#include <malloc.h>

LinkedList  *createLinkedList()
{

	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void List_Add(int newdata , LinkedList *list)
{
	int i;
	Element *newElement= malloc(sizeof (Element));
	if(list->head == NULL)
	{
		list->head = list->tail = newElement;
	}
	else
	{
		//Get the latest element block by reference to the tail
		list->tail->next = newElement;
		list->tail = newElement;
	}
		list->length = list->length+1;
		newElement->next = NULL;
		newElement->data = newdata;
		
}

Element *List_removeLast(LinkedList *list)
{
	if(list->head == NULL && list->tail == NULL)
	return NULL;
	else if(list->head==list->tail)
	return list->tail;
}