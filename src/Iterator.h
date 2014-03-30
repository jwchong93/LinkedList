#ifndef Iterator_H
#define Iterator_H
#include "LinkedList.h"

typedef struct {
	LinkedList *list;
	Element *current;
	Element *(*next)(Element *);
} Iterator;

Iterator *getIterator(LinkedList *list);
Element *getNext(Element *current);

#endif // Iterator_H
