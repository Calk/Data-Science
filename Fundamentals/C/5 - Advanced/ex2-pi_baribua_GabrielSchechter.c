#include <stdio.h>
#include <setjmp.h>

int CalculateSquare(int* numberToSquare)
{
	if (numberToSquare != NULL)
	{
		int temp = *numberToSquare;
		*numberToSquare = temp*temp;
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	int first1 = 2;
	printf("original value: %i", first1);
	CalculateSquare(&first1);
	printf("squared value: %i", first1);

	int first2 = 3;
	printf("original value: %i", first2);
	CalculateSquare(&first2);
	printf("squared value: %i", first2);

	int temp = 0;
}