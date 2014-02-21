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

void List_add(int newdata , LinkedList *list)
{
	Element *newElement= malloc(sizeof (Element));
	list->head = list->tail = newElement;
	list->length = list->length +1;
	newElement->next = NULL;
	newElement->data = newdata;
}