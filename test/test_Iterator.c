#include "unity.h"
#include "Iterator.h"
#include <malloc.h>
#include "LinkedList.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_getIterator_should_create_an_iterator_and_point_to_the_LinkedList()
{
	LinkedList *testList = malloc(sizeof(LinkedList));
	Iterator *iter;
	iter = getIterator(testList);
	TEST_ASSERT_NOT_NULL(iter);
	//Make sure Iterator refer to the same linked list.
	TEST_ASSERT_EQUAL(testList,iter->list);
	//And it is points to the head.
	TEST_ASSERT_EQUAL(testList->head,iter->current);
	//Make sure the function pointer point to the function that refer the next element.
	TEST_ASSERT_EQUAL(&getNext,iter->next);
	List_DestroyList(testList);
	destroyIterator(iter);
}


void test_getNext_will_update_the_pointer_point_to_the_next_location()
{
	LinkedList *testList = createLinkedList();
	Element *elem0 = malloc(sizeof(Element));
	Element *elem1 = malloc(sizeof(Element));
	Element *elem2 = malloc(sizeof(Element));
	Element *testElement;
	List_Add(elem0,testList);
	List_Add(elem1,testList);
	List_Add(elem2,testList);
	testElement = testList->head;
	TEST_ASSERT_EQUAL(elem0,testElement);
	testElement = getNext(testElement);
	TEST_ASSERT_EQUAL(elem1,testElement);
	testElement = getNext(testElement);
	TEST_ASSERT_EQUAL(elem2,testElement);
	testElement = getNext(testElement);
	TEST_ASSERT_EQUAL(NULL,testElement);
	List_DestroyList(testList);
	
}

void test_getNext_will_update_the_pointer_point_to_the_next_location_for_1000_elements()
{
	LinkedList *testList = createLinkedList();
	Element elem[1000];
	Element *testElement;
	int i;
	for(i=0;i<1000;i++)
	{
		List_Add(&elem[i],testList);
	
	}
	testElement = testList->head;
	for(i=0;i<1000;i++)
	{
		TEST_ASSERT_EQUAL(&elem[i],testElement);
		testElement = getNext(testElement);	
	}

	TEST_ASSERT_EQUAL(NULL,testElement);
	List_DestroyList(testList);
}

void test_getNext_function_properly_through_iterator()
{
	LinkedList *testList = createLinkedList();
	Iterator *iter;
	Element elem[1000];
	int i;
	for(i=0;i<1000;i++)
	{
		List_Add(&elem[i],testList);
	
	}
	//testElement = testList->head;
	iter = getIterator(testList);
	for(i=0;i<1000;i++)
	{
		TEST_ASSERT_EQUAL(&elem[i],iter->current);
		iter->current = iter->next(iter->current);
	}

	TEST_ASSERT_EQUAL(NULL,iter->current);
	List_DestroyList(testList);
	destroyIterator(iter);
}











