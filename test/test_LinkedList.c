#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>
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
	int num1=8,num2=9,num3=14;
	Element *testElement = malloc(sizeof(Element));
	Element *testElement2 = malloc(sizeof(Element));
	Element *testElement3 = malloc(sizeof(Element));
	testElement->data =&num1;  //Add the data 8 to the element.
	List_Add(testElement,list);  	//Add the element to linked list.
	TEST_ASSERT_EQUAL(8,*(int*)list->head->data);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_EQUAL(list->head,list->tail);	//Since there is only one data in the linked list, head and tail will contain same address.
	TEST_ASSERT_NULL(list->head->next);
	
	//Add one more data to the linked list, where the data =9
	testElement2->data =&num2;
	List_Add(testElement2,list); 
	TEST_ASSERT_EQUAL(9,*(int*)list->tail->data);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NULL(list->tail->next);
	
	//Add the third data to the list
	testElement3->data =&num3;
	List_Add(testElement3,list); 
	TEST_ASSERT_EQUAL(14,*(int*)list->tail->data);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NULL(list->tail->next);
}



void test_List_removeLast_should_return_the_last_element_of_LinkedList()
{
	LinkedList *list = createLinkedList();
	Element *tempElement;
	Element *testElement = malloc(sizeof(Element));
	Element *testElement2 = malloc(sizeof(Element));
	Element *testElement3 = malloc(sizeof(Element));
	int num1=1,num2=2,num3=3;
	//Test when the linked list was nothing inside.
	tempElement = List_removeLast(list);
	TEST_ASSERT_NULL(tempElement);
	TEST_ASSERT_EQUAL(0,list->length);
	
	//Add one data to the linked list and remove the data.
	testElement->data=&num1;
	List_Add(testElement,list); 
	tempElement = List_removeLast(list);
	TEST_ASSERT_NOT_NULL(tempElement);			//The pointer must contain the last element.
	TEST_ASSERT_EQUAL(1,*(int*)tempElement->data);		//The data should be the last data added to the linked list.
	TEST_ASSERT_EQUAL(0,list->length);			//Since the only one data is removed , the length should be 0.
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);				//Head and tail will point to NULL since no data inside.
	
	//Add two data to the linked list 
	testElement->data=&num1;
	List_Add(testElement,list); 
	testElement2->data=&num2;
	List_Add(testElement2,list); 
	tempElement = List_removeLast(list);
	TEST_ASSERT_EQUAL(2,*(int*)tempElement->data);		//The element that returned should show the last data.
	TEST_ASSERT_EQUAL(1,list->length);			//The length should be 1 , because only one data been removed.
	TEST_ASSERT_EQUAL(list->head,list->tail);  //Test that the tail will point to the last remained data or not.
	tempElement = List_removeLast(list);
	TEST_ASSERT_EQUAL(1,*(int*)tempElement->data);
	TEST_ASSERT_EQUAL(0,list->length);

			
	//Add three data to the linked list 
	testElement->data=&num1;
	List_Add(testElement,list);	
	testElement2->data=&num2;
	List_Add(testElement2,list);
	testElement3->data=&num3;
	List_Add(testElement3,list);
	tempElement = List_removeLast(list);
	TEST_ASSERT_EQUAL(3,*(int*)tempElement->data);		//The element that returned should show the last data.
	TEST_ASSERT_EQUAL(2,list->length);			//The length should be 1 , because only one data been removed.
	TEST_ASSERT_EQUAL(list->head->next,list->tail);  //Test that the tail will point to the last remained data or not.
	tempElement = List_removeLast(list);
	TEST_ASSERT_EQUAL(2,*(int*)tempElement->data);
	TEST_ASSERT_EQUAL(1,list->length);
	tempElement = List_removeLast(list);
	TEST_ASSERT_EQUAL(1,*(int*)tempElement->data);
	TEST_ASSERT_EQUAL(0,list->length);
	
	//Try to remove again and check the returned data is NULL or not.
	tempElement=List_removeLast(list);
	TEST_ASSERT_NULL(tempElement);
	TEST_ASSERT_EQUAL(0,list->length);
	tempElement=List_removeLast(list);
	TEST_ASSERT_NULL(tempElement);
	TEST_ASSERT_EQUAL(0,list->length);

	
	
}

void test_List_addFirst_should_add_element_the_the_first_location_of_the_LinkedList()
{
	Element *testElement = malloc(sizeof(Element));
	Element *testElement2 = malloc(sizeof(Element));
	Element *testElement3 = malloc(sizeof(Element));
	Element *tempElement = malloc(sizeof(Element));
	LinkedList *list = createLinkedList();
	int num1 =8 , num2=18,num3=118;
	//Make sure element will store in the linked list. 
	testElement->data =&num1;
	List_addFirst(testElement,list);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_EQUAL(8,*(int*)list->head->data);
	TEST_ASSERT_EQUAL(8,*(int*)list->tail->data);
	//Since only one element inside the linked list, tail should point to the same location.
	TEST_ASSERT_EQUAL(list->head,list->tail);
	
	//Add one more element into the linked list. 
	testElement2->data = &num2;
	List_addFirst(testElement2,list);
	TEST_ASSERT_EQUAL(2,list->length);
	
	//Try to remove the first input, which data=8;
	tempElement=List_removeLast(list);
	TEST_ASSERT_EQUAL(8,*(int*)tempElement->data);
	tempElement=List_removeLast(list);
	TEST_ASSERT_EQUAL(18,*(int*)tempElement->data);
	
	//Add three data into the linked list.
	testElement3->data=&num3;
	List_addFirst(testElement,list);
	TEST_ASSERT_EQUAL(1,list->length);
	List_addFirst(testElement2,list);
	TEST_ASSERT_EQUAL(2,list->length);
	List_addFirst(testElement3,list);
	TEST_ASSERT_EQUAL(3,list->length);
	
	//Try to remove all the data and test the sequence.
	tempElement=List_removeLast(list);
	TEST_ASSERT_EQUAL(8,*(int*)tempElement->data);
	tempElement=List_removeLast(list);
	TEST_ASSERT_EQUAL(18,*(int*)tempElement->data);
	tempElement=List_removeLast(list);
	TEST_ASSERT_EQUAL(118,*(int*)tempElement->data);
	
}

void test_List_removeFirst_should_remove_the_first_data_in_the_linked_list()
{
	Element *testElement = malloc(sizeof(Element));
	Element *testElement2 = malloc(sizeof(Element));
	Element *testElement3 = malloc(sizeof(Element));
	Element *tempElement = malloc(sizeof(Element));
	LinkedList *list = createLinkedList();
	int num1=1,num2=2,num3=3;
	//If there are no data, function should return NULL.
	tempElement = List_removeFirst(list);
	TEST_ASSERT_NULL(tempElement);
	
	//Add three element into the linked list.
	testElement->data =&num1;
	List_Add(testElement,list);
	testElement2->data =&num2;
	List_Add(testElement2,list); 
	testElement3->data =&num3;
	List_Add(testElement3,list);
	
	//Remove the first data and test the data is equal = 1(first data) or not.
	tempElement = List_removeFirst(list);
	TEST_ASSERT_NOT_NULL(tempElement);
	TEST_ASSERT_EQUAL(1,*(int*)tempElement->data);
	TEST_ASSERT_EQUAL(2,list->length);
	tempElement = List_removeFirst(list);
	TEST_ASSERT_EQUAL(2,*(int*)tempElement->data);   //Test the returned data is 2(second position).
	TEST_ASSERT_EQUAL(1,list->length);
	tempElement = List_removeFirst(list);
	TEST_ASSERT_EQUAL(3,*(int*)tempElement->data);
	TEST_ASSERT_EQUAL(0,list->length);
	
	//Since there is no data left, the function should return a NULL
	tempElement = List_removeFirst(list);
	TEST_ASSERT_NULL(tempElement);
	TEST_ASSERT_EQUAL(0,list->length);	
	tempElement = List_removeFirst(list);
	TEST_ASSERT_NULL(tempElement);
	TEST_ASSERT_EQUAL(0,list->length);
	
}

