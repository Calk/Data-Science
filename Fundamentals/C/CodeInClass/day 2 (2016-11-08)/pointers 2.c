#include <stdio.h>
#define DIM1 2
#define DIM2 3

size_t StringLength_suboptimal(char *string)
{
	size_t index = 0;
	for (; string[index] != '\0'; ++index)
		;

	return index;
}

size_t StringLength(char *string)
{
	char *current = string;

	for (; *current != '\0'; ++current)
		;

	return current - string;
}

void main(void)
{
	/*
	char s1[] = "Hello";
	char s2[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	size_t length = StringLength(s1);
	*/

	int arr[] = { 10, 20, 30, 40, 50 };
	int *p = arr; /* <==> p = &arr */
	//++p; /* <==> p += sizeof(*p) */

	int *median = arr + 2;
	int num = median[-2]; /* access deviations */

	/* Pointer arithmetic: */
	char str[] = "Hello everyone how are you";
	char *beginningOfSecondWord = str + 6;
	char *endOfSecondWord = str + 14;

	size_t lengthOfSecondWord = endOfSecondWord - beginningOfSecondWord;

	int matrix[DIM1][DIM2] = { {10, 20, 30}, {40, 50, 60} };

	/* Naive iteration: */
	/*
	for (size_t i = 0; i < DIM1; ++i)
	{
		for (size_t j = 0; j < DIM2; ++j)
		{
			printf("%d\n", matrix[i][j]);
		}
	}
	*/

	int *vector = *matrix;//matrix[0]; //&(matrix[0][0]);
	int *limit = vector + DIM1 * DIM2;

	for (; vector < limit; ++vector)
	{
		printf("%d\n", *vector);
	}

	//int m[][2] = { {1, 2}, {3, 4}, {5, 6} };
	//int m[][3] = { {1, 2, 3}, 4, {5} };
	void *pVoid = limit;
	float f;
	pVoid = &f;
	limit = pVoid;
}
