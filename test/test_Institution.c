#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <stdio.h>
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Institution_reverse_should_return_0_if_head_and_tail_link_to_null(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	
	inputList.head = NULL;
	inputList.tail = NULL;
	
	//mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	//run
	result = Institution_reverse(&inputList, &outputList);
	TEST_ASSERT_EQUAL(0, result);
}

void test_Institution_reverse_to_reverse_1_instance_of_institution(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};
	
	inputList.head = &USM;
	inputList.tail = &USM;
	
	//mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	Stack_push_Expect(&instanceStack, &USM);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	List_addTail_Expect(&outputList, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, NULL);
	
	//run
	result = Institution_reverse(&inputList, &outputList);
	TEST_ASSERT_EQUAL(1, result);
}

void test_Institution_reverse_to_reverse_2_instances_of_institution(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};

	Institution INTI = {.name ="INTI",
						.type = College,
						.yearEstablished = 2000};
	
	inputList.head = &USM;
	inputList.tail = &INTI;
	
	//mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	Stack_push_Expect(&instanceStack, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	Stack_push_Expect(&instanceStack, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&instanceStack, &INTI);
	List_addTail_Expect(&outputList, &INTI);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	List_addTail_Expect(&outputList, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, NULL);
	
	//run
	result = Institution_reverse(&inputList, &outputList);
	TEST_ASSERT_EQUAL(2, result);
}

void test_Institution_reverse_to_reverse_3_instances_of_institution(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};

	Institution INTI = {.name ="INTI",
						.type = College,
						.yearEstablished = 2000};
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	inputList.head = &USM;
	inputList.tail = &TARUC;
	
	//mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	Stack_push_Expect(&instanceStack, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	Stack_push_Expect(&instanceStack, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &INTI);
	Stack_pop_ExpectAndReturn(&instanceStack, &INTI);
	List_addTail_Expect(&outputList, &INTI);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	List_addTail_Expect(&outputList, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, NULL);
	
	//run
	result = Institution_reverse(&inputList, &outputList);
	TEST_ASSERT_EQUAL(3, result);
}

void test_isUniversityCollege_should_return_1_to_indicate_same_type_else_otherwise(void)
{
	InstitutionType type = UniversityCollege;
	int result;
	
	//printf("type: %d\n", type);
	
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};

	result = isUniversityCollege(&USM, &type);
	TEST_ASSERT_EQUAL(0, result);
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
						
	//printf("TARUC->type: %d\n", TARUC.type);

	result = isUniversityCollege(&TARUC, &type);
	TEST_ASSERT_EQUAL(1, result);
}

void test_Institution_select_to_select_the_university_college(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	InstitutionType type = UniversityCollege;
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	inputList.head = &TARUC;
	inputList.tail = &TARUC;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, NULL);

	
	//Run
	result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);
	TEST_ASSERT_EQUAL(1, result);
}

void test_Institution_select_to_select_2_university_college(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	InstitutionType type = UniversityCollege;
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	Institution KLMUC = {.name ="KLMUC",
						.type = UniversityCollege,
						.yearEstablished = 2001};
	
	inputList.head = &TARUC;
	inputList.tail = &KLMUC;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &KLMUC);
	List_removeHead_ExpectAndReturn(&inputList, &KLMUC);
	Stack_push_Expect(&instanceStack, &KLMUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &KLMUC);
	List_addTail_Expect(&outputList, &KLMUC);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	//Run
	result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);
	TEST_ASSERT_EQUAL(2, result);
}

void test_Institution_select_to_select_1_university_college_given_3_institution(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	InstitutionType type = UniversityCollege;
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	Institution UMS = {.name ="UMS",
					   .type = University,
					   .yearEstablished = 1980};
	
	Institution INTI = {.name ="INTI",
						.type = College,
						.yearEstablished = 2001};
	
	inputList.head = &TARUC;
	inputList.tail = &INTI;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &UMS);
	List_removeHead_ExpectAndReturn(&inputList, &UMS);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, &INTI);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	//Run
	result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);
	TEST_ASSERT_EQUAL(1, result);
}

void test_wasEstablishBefore_should_return_1_to_indicate_institution_establised_before_1980_else_otherwise(void)
{
	int year = 1980;
	int result;
	
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};

	result = wasEstablishBefore(&USM, &year);
	TEST_ASSERT_EQUAL(1, result);
	
	Institution INTI = {.name ="INTI",
						.type = College,
						.yearEstablished = 2001};

	result = wasEstablishBefore(&INTI, &year);
	TEST_ASSERT_EQUAL(0, result);
}

void test_wasEstablishBefore_should_raise_an_exeption_if_year_establishment_more_than_2014(void)
{
	int year = 1980;
	int result;
	CEXCEPTION_T err;
	
	Institution MYC = {.name ="MYC",
						.type = College,
						.yearEstablished = 2016};
	Try
	{
		wasEstablishBefore(&MYC, &year);
		TEST_FAIL_MESSAGE("Should generate an exception due year establishment more than 2014");
	}Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_YEAR_ESTABLISHMENT, err, "Expected ERR_YEAR_ESTABLISHMENT exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
}

void test_Institution_select_should_return_0_if_head_and_tail_link_to_null(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	int type;
	
	inputList.head = NULL;
	inputList.tail = NULL;
	
	//mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	//run
	result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);
	TEST_ASSERT_EQUAL(0, result);
}

void test_Institution_select_to_select_the_institution_establised_before_1980(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	int year = 1980;
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	inputList.head = &TARUC;
	inputList.tail = &TARUC;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, NULL);

	//Run
	result = Institution_select(&inputList, &outputList, &year, wasEstablishBefore);
	TEST_ASSERT_EQUAL(1, result);
}

void test_Institution_select_to_select_2_institution_establised_before_1980(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	int year = 1980;
	
	Institution TARUC = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 1970};
	
	Institution USM = {.name = "USM",
					   .type = University,
					   .yearEstablished = 1900};
	
	inputList.head = &TARUC;
	inputList.tail = &USM;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
	Stack_push_Expect(&instanceStack, &TARUC);
	Stack_pop_ExpectAndReturn(&instanceStack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	List_removeHead_ExpectAndReturn(&inputList, &USM);
	Stack_push_Expect(&instanceStack, &USM);
	Stack_pop_ExpectAndReturn(&instanceStack, &USM);
	List_addTail_Expect(&outputList, &USM);
	List_removeHead_ExpectAndReturn(&inputList, NULL);

	//Run
	result = Institution_select(&inputList, &outputList, &year, wasEstablishBefore);
	TEST_ASSERT_EQUAL(2, result);
}

void test_Institution_select_should_raise_an_exeption_if_year_establishment_more_than_2014(void)
{
	int result;
	LinkedList inputList;
	LinkedList outputList;
	Stack instanceStack;
	int year = 1980;
	CEXCEPTION_T err;
	
	Institution MYU = {.name ="TARUC",
						.type = UniversityCollege,
						.yearEstablished = 2015};
	
	inputList.head = &MYU;
	inputList.tail = &MYU;
	
	//Mock
	Stack_create_ExpectAndReturn(&instanceStack);
	List_removeHead_ExpectAndReturn(&inputList, &MYU);
	List_removeHead_ExpectAndReturn(&inputList, &MYU);

	//Run
	Try
	{
		result = Institution_select(&inputList, &outputList, &year, wasEstablishBefore);
		TEST_FAIL_MESSAGE("Should generate an exception due year establishment more than 2014");
	}Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_YEAR_ESTABLISHMENT, err, "Expected ERR_YEAR_ESTABLISHMENT exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
}