#include "unity.h"
#include "LinkedList.h"

void setUp (){}
void tearDown (){}

void test_createLinkedList_should_return_LinkedList_object()
{
	LinkedList *list;
	
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	
}

void test_List_add_should_add_a_new_element_to_the_LinkedList()
{
	LinkedList *list;
	list= createLinkedList();
	List_add(8,list);  	//Add data 8 to the linked list.
	TEST_ASSERT_EQUAL(8,list->head->data);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_EQUAL(list->head,list->tail);	//Since there is only one data in the linked list, head and tail will contain same address.
	TEST_ASSERT_NULL(list->head->next);
}
/*
Helper function to dump Linked List
*/
/*
void dumpLinkedList(LinkedList *list)
{
	Element *elem;
	printf("head:%p,tail:%p,length:%d\n",list->head,list->tail,list->length);
	for (elem = list->head;elem!=NULL;elem=elem->next)
	{
		printf("data:%d,addr:%p\n",elem->data,elem);
	}
}


void test_no_test_but_playing_around()
{
	LinkedList *list = createLinkedList();
	/*
	Element arrayElem[3]={{&arrayElem[1],1},
						{&arrayElem[2],2},
						{NULL,3}};
	*/
	//The following is the alternative way to initialize.
	//To prevent data been initialize wrongly.
/*	
	Element arrayElem[3]={{.next=&arrayElem[1],.data=1},
						{.next=&arrayElem[2],.data=2},
						{.next=NULL,.data=3}};
	list->head = &arrayElem[0];
	list->length =3;
	list->tail = &arrayElem[2];
	
	dumpLinkedList(list);

}
*/
