#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct Element_t
{
	struct Element_t *next;
	int data;
}Element;

typedef struct
{
	Element *head;
	Element *tail;
	int length;
}LinkedList;

LinkedList  *createLinkedList();
void List_Add(int newdata , LinkedList *list);
Element *List_removeLast(LinkedList *list);

#endif //__LINKED_LIST_H__