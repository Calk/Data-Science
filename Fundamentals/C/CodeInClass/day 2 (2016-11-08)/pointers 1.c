#include <stdio.h>

void Absolute(int *pNumber)
{
	if (*pNumber < 0)
	{
		*pNumber = -*pNumber;
	}
}

void Swap(int *a, int *b)
{
	if (a && b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void main(void)
{
	int number1 = 7, number2 = -10;
	int *p = NULL;

	if (p != NULL)
	{
		Swap(p, &number1);
	}
	Swap(&number1, &number2);

	/*
	Absolute(&number1);
	printf("The absolute value is %d\n", number1);
	Absolute(&number2);
	printf("The absolute value is %d\n", number2);
	*/
}
