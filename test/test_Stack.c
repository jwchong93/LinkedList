#include "unity.h"
#include "Stack.h"
#include <malloc.h>
#include "LinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_createStack_will_create_a_stack_which_the_TOS_is_NULL()
{
	Stack *newStack = createStack();
	TEST_ASSERT_NOT_NULL(newStack);
	TEST_ASSERT_NULL(newStack->topOfStack);
	free(newStack);
}

void test_push_should_push_in_the_data_address_into_the_stack()
{
	Stack *newStack = createStack();
	int num1=100,num2=200;
	
	Element testElement1;
	testElement1.data = &num1;
	Element testElement2;
	testElement1.data = &num2;
	
	TEST_ASSERT_NOT_NULL(newStack);
	TEST_ASSERT_NULL(newStack->topOfStack);
	
	push(newStack,&testElement1);
	//Make sure the address of testElement1 is on topOfStack
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->data);
	TEST_ASSERT_NOT_NULL(newStack->topOfStack);
	
	//Try to push one more and test.
	push(newStack,&testElement2);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->data);
	destroyStack(newStack);
}

void test_pop_will_pop_accordingly()
{
	Stack *newStack = createStack();
	int num1=100,num2=200;
	
	Element testElement1;
	testElement1.data = &num1;
	Element testElement2;
	testElement1.data = &num2;
	Element *tempElement;
	push(newStack,&testElement1);
	push(newStack,&testElement2);
	
	//testElement2 should come out 1st. 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement2,tempElement);
	
	//Follow by testElement1
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement1,tempElement);
	destroyStack(newStack);
}

void test_pop_will_return_error_while_the_stack_is_empty()
{
	Stack *newStack = createStack();
	Element *tempElement;
	//testElement2 should come out 1st. 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_NULL(tempElement);

	destroyStack(newStack);
}

void test_stack_will_follow_FILO_rule_for_three_elements()
{
	Stack *newStack = createStack();
	int num1=100,num2=200,num3=300;
	Element *tempElement;
	
	Element testElement1;
	testElement1.data = &num1;
	Element testElement2;
	testElement1.data = &num2;
	Element testElement3;
	testElement1.data = &num3;
	
	TEST_ASSERT_NOT_NULL(newStack);
	TEST_ASSERT_NULL(newStack->topOfStack);
	
	push(newStack,&testElement1);
	//Make sure the address of testElement1 is on topOfStack
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->data);
	
	//Try to push one more and test.
	push(newStack,&testElement2);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->data);
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->next->data);
	
	//Push the last one.
	push(newStack,&testElement3);
	TEST_ASSERT_EQUAL(&testElement3,newStack->topOfStack->data);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->next->data);
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->next->next->data);
	
	
	//testElement3 should come out 1st. 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement3,tempElement);
	
	//Follow by testElement2 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement2,tempElement);
	
	//Lastly testElement1
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement1,tempElement);
	destroyStack(newStack);
}

void test_stack_will_follow_FILO_rule_for_four_elements()
{
	Stack *newStack = createStack();
	int num1=100,num2=200,num3=300,num4=400;
	Element *tempElement;
	
	Element testElement1;
	testElement1.data = &num1;
	Element testElement2;
	testElement1.data = &num2;
	Element testElement3;
	testElement1.data = &num3;
	Element testElement4;
	testElement1.data = &num4;
	
	TEST_ASSERT_NOT_NULL(newStack);
	TEST_ASSERT_NULL(newStack->topOfStack);
	
	push(newStack,&testElement1);
	//Make sure the address of testElement1 is on topOfStack
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->data);
	
	//Try to push one more and test.
	push(newStack,&testElement2);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->data);
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->next->data);

	
	push(newStack,&testElement3);
	TEST_ASSERT_EQUAL(&testElement3,newStack->topOfStack->data);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->next->data);
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->next->next->data);
	
	push(newStack,&testElement4);
	TEST_ASSERT_EQUAL(&testElement4,newStack->topOfStack->data);
	TEST_ASSERT_EQUAL(&testElement3,newStack->topOfStack->next->data);
	TEST_ASSERT_EQUAL(&testElement2,newStack->topOfStack->next->next->data);
	TEST_ASSERT_EQUAL(&testElement1,newStack->topOfStack->next->next->next->data);
	
	
	//testElement4 should come out 1st. 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement4,tempElement);
	
	
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement3,tempElement);
	
	//Follow by testElement2 
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement2,tempElement);
	
	//Lastly testElement1
	tempElement = (Element*)pop(newStack);
	TEST_ASSERT_EQUAL(&testElement1,tempElement);
	destroyStack(newStack);
}

void test_stack_will_follow_FILO_rule_for_four_int_address()
{
	Stack *newStack = createStack();
	int num1=100,num2=200,num3=300,num4=400;
	int *testNum;
	push(newStack,&num1);
	push(newStack,&num2);
	push(newStack,&num3);
	push(newStack,&num4);
	
	testNum = pop(newStack);
	TEST_ASSERT_EQUAL(400,*testNum);
	testNum = pop(newStack);
	TEST_ASSERT_EQUAL(300,*testNum);
	testNum = pop(newStack);
	TEST_ASSERT_EQUAL(200,*testNum);
	testNum = pop(newStack);
	TEST_ASSERT_EQUAL(100,*testNum);
	destroyStack(newStack);
}
void test_stack_will_follow_FILO_rule_with_1000_elements()
{
	Stack *newStack = createStack();
	Element testElement[1000];
	Element *tempElement;
	
	int i;
	for(i=0;i<1000;i++)
	{
		push(newStack,&testElement[i]);
	}
	for(i=999;i>=0;i--)
	{
		tempElement = (Element*)pop(newStack);
		TEST_ASSERT_EQUAL(&testElement[i],tempElement);
	}
	destroyStack(newStack);
}






