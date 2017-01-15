#include <stdio.h>
#include "Caesar.h"

struct _SafeArray
{
	int arraySize;
	int* innerArray;
};
typedef struct _SafeArray SafeArray;

SafeArray CreateSafeArray(int sizeOfArray)
{
	//Create new safe array
	SafeArray newSafeArray;
	newSafeArray.arraySize = sizeOfArray;
	newSafeArray.innerArray = malloc((sizeof(int) * sizeOfArray));

	return newSafeArray;
}

void DestroySafeArray(SafeArray *safeArray)
{
	//Destroy the safe array
	free(safeArray->innerArray);
	safeArray = NULL;
}

int GetElementAtIndex(SafeArray * safeArray, int indexOf)
{
	// Function for Retrieving an element from the safe array
	int upperBoundary = safeArray->arraySize;
	if (indexOf < 0 || indexOf > upperBoundary - 1)
	{
		printf("Index %i is out of boundary\n", indexOf);
	}
	else
	{
		int itemRetrieved = safeArray->innerArray[indexOf];
		printf("Element %i retrieved at index %i\n", itemRetrieved, indexOf);
		return itemRetrieved;
	}
}

void SetElementAtIndex(SafeArray * safeArray, int indexOf, int newElement)
{
	// Function for Inserting an element into the safe array
	int upperBoundary = safeArray->arraySize;
	if (indexOf < 0 || indexOf > upperBoundary - 1)
	{
		printf("Index %i is out of boundary\n", indexOf);
	}
	else
	{
		printf("Element %i inserted at index %i\n", newElement, indexOf);
		safeArray->innerArray[indexOf] = newElement;
	}
}

void ReziseArray(SafeArray * safeArray, int newSize)
{
	//Function for resizing array without losing elements
	printf("SafeArray now has size %i \n", newSize);
	safeArray->arraySize = newSize;
	int* newArray = safeArray->innerArray;
	realloc(newArray, (sizeof(int) * newSize));
	safeArray->innerArray = newArray;
}

void AppendArray(SafeArray *destinationArray, SafeArray *arrayToAppend)
{
	//Function for appending a new safeArray to an destination safeArray
	int sizeOfNewArray = arrayToAppend->arraySize;
	int sizeOfDestinyArray = destinationArray->arraySize;
	ReziseArray(destinationArray, sizeOfDestinyArray + sizeOfNewArray);

	//Copy data from arrayToAppend to 
	for (size_t i = 0; i < sizeOfNewArray; i++)
	{
		int temp = GetElementAtIndex(arrayToAppend, i);
		SetElementAtIndex(destinationArray, sizeOfDestinyArray + i, temp);
	}
}

int main()
{
	//Test Appending method for safe arrays
	SafeArray destArray = CreateSafeArray(5);
	SafeArray arrayToAppend = CreateSafeArray(5);

	SetElementAtIndex(&destArray, 0, 1);
	SetElementAtIndex(&destArray, 1, 2);
	SetElementAtIndex(&destArray, 2, 3);
	SetElementAtIndex(&destArray, 3, 4);
	SetElementAtIndex(&destArray, 4, 5);

	SetElementAtIndex(&arrayToAppend, 0, 6);
	SetElementAtIndex(&arrayToAppend, 1, 7);
	SetElementAtIndex(&arrayToAppend, 2, 8);
	SetElementAtIndex(&arrayToAppend, 3, 9);
	SetElementAtIndex(&arrayToAppend, 4, 10);

	AppendArray(&destArray, &arrayToAppend);

	GetElementAtIndex(&destArray, 0);
	GetElementAtIndex(&destArray, 2);
	GetElementAtIndex(&destArray, 4);
	GetElementAtIndex(&destArray, 6);
	GetElementAtIndex(&destArray, 8);
	GetElementAtIndex(&destArray, 9);

	DestroySafeArray(&destArray);
	DestroySafeArray(&arrayToAppend);

	return 0;
}