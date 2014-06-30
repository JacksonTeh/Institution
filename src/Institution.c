#include "Institution.h"
#include "LinkedList.h"
#include "Stack.h"
#include <stdio.h>
#include "CException.h"

int Institution_reverse(LinkedList *inputList, LinkedList *outputList)
{
	int element = 0;
	Stack *stack = Stack_create();
	Institution *dataRemove, *dataOutput;
	// Institution *dataRemove = (Institution *)List_removeHead(inputList);
	// Stack_push(stack, dataRemove);
	// dataRemove = (Institution *)List_removeHead(inputList);
	// Institution *dataOutput = (Institution *)Stack_pop(stack);
	// List_addTail(outputList, dataOutput);
	
	if((Institution *)List_removeHead(inputList) == NULL)
		return element;
	
	do{
		dataRemove = (Institution *)List_removeHead(inputList);
		Stack_push(stack, dataRemove);
	}while((Institution *)List_removeHead(inputList) != NULL);
	
	do{
		dataOutput = (Institution *)Stack_pop(stack);
		List_addTail(outputList, dataOutput);
		element++;
	}while((Institution *)Stack_pop(stack) != NULL);
	
	return element;
}

int Institution_select(LinkedList *inputList,
					   LinkedList *outputList,
					   void *criterion,
					   int (*compare)(void *, void *))
{
	int element = 0;
	Stack *stack = Stack_create();
	Institution *dataRemove, *dataOutput;
	
	if((Institution *)List_removeHead(inputList) == NULL)
		return element;
	
	//printf("type: %d\n", *type);
	do{
		dataRemove = (Institution *)List_removeHead(inputList);
	//printf("dataRemove->type: %d\n", dataRemove->type);
		if(compare(dataRemove, criterion))
		{
			Stack_push(stack, dataRemove);
			dataOutput = (Institution *)Stack_pop(stack);
			List_addTail(outputList, dataOutput);
			element++;
		}
	}while((Institution *)List_removeHead(inputList) != NULL);
	
	return element;
}

int isUniversityCollege(void *elem1, void *type)
{
	Institution *institution = (Institution *)elem1;
	InstitutionType *UniCollege = (InstitutionType *)type;
	
	//printf("institution->type: %d\n", institution->type);
	//printf("UniCollege: %d\n", *UniCollege);
	
	if(institution->type == *UniCollege)
		return 1;
	return 0;
}

int wasEstablishBefore(void *elem1, void *year)
{
	Institution *institution = (Institution *)elem1;
	int *yearEstablised = (int *)year;
	
	if(institution->yearEstablished > 2014)
		Throw(ERR_YEAR_ESTABLISHMENT);
	
	if(institution->yearEstablished < *yearEstablised)
		return 1;
	return 0;
}