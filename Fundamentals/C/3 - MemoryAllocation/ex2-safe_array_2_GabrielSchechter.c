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
	if (indexOf < 0 || indexOf > upperBoundary-1)
	{
		printf("Index %i is out of boundary\n", indexOf);
	}
	else
	{
		int itemRetrieved = safeArray->innerArray[indexOf];
		printf("Element %i retrieved at index %i\n",itemRetrieved, indexOf);
		return itemRetrieved;
	}
}

void SetElementAtIndex(SafeArray * safeArray, int indexOf, int newElement)
{
	// Function for Retrieving an element from the safe array
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

int main()
{
	SafeArray safeArray = CreateSafeArray(10);

	SetElementAtIndex(&safeArray, 0, 10);
	SetElementAtIndex(&safeArray, 1, 20);
	SetElementAtIndex(&safeArray, 2, 30);
	SetElementAtIndex(&safeArray, 9, 30);
	SetElementAtIndex(&safeArray, -1, 30);
	SetElementAtIndex(&safeArray, 20, 30);

	int ret1 = GetElementAtIndex(&safeArray, 0);
	int ret2 = GetElementAtIndex(&safeArray, 9);
	int ret3 = GetElementAtIndex(&safeArray, -1);
	int ret4 = GetElementAtIndex(&safeArray, 20);

	ReziseArray(&safeArray, 30);
	SetElementAtIndex(&safeArray, 20, 30);
	ret4 = GetElementAtIndex(&safeArray, 20);

	return 0;
}