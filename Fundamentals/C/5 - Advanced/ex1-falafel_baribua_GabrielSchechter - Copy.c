#include <stdio.h>

int GetSquareValue(int originalNumber)
{
	int tempNumber = originalNumber;
	tempNumber *= tempNumber;

	return tempNumber;
}

void main()
{
	int originalTwo = 2;
	int squareOfTwo = GetSquareValue(originalTwo);
	printf("original value: %i ; squared value: %i \n", originalTwo, squareOfTwo);

	int originalThree = 3;
	int squareOfThree = GetSquareValue(originalThree);
	printf("original value: %i ; squared value: %i ", originalThree, squareOfThree);

	int success = 0;
}