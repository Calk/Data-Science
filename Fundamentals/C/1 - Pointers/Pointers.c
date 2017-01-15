#include <stdio.h>
#ifndef DIM1
#define DIM1 2
#endif // !DIM1
#ifndef DIM2
#define DIM2 3
#endif // !DIM2

# define PRINT_BITS(x) (PrintBits(&x, sizeof(x)))

void PrintBits(void *pValue, size_t byteCount)
{
	unsigned char * bytes = (unsigned char *)pValue;
	//for (size_t byteNo = 0; byteNo < byteCount; ++byteNo)
	for (int byteNo = byteCount - 1; byteNo >= 0; --byteNo)
	{
		for (int bitNo = 7; bitNo >= 0; --bitNo)
		{
			printf("%c", (bytes[byteNo] & 1 << bitNo) ? '1' : '0');

			if (bitNo % 8 == 0)
			{
				printf(" ");
			}
		}
	}
	printf("\n");
}


// We use reference of our number to change its value directly in the function
void Absolute(int *pNumber)
{
	if (*pNumber < 0)
	{
		*pNumber = -*pNumber;
	}
}

void Swap(int *pNumber1, int *pNumber2)
{
	if (pNumber1 && pNumber2)
	{
		int pTemp = *pNumber1;
		*pNumber1 = *pNumber2;
		*pNumber2 = pTemp;
	}
}

size_t StringLength(char * string)
{
	/*size_t length = 0;
	while (*s != '\0')
	{
		++length;
		++s;
	}

	return length;*/

	/*size_t index;
	for (index = 0; index < s[index] != '\0'; ++index) {}

	return index;*/

	//return strlen(s);

	char * current = string;

	while (*current != '\0')
	{
		current++;
	}
	return current - string;
}

size_t StringLengthSecondWay(char * string)
{
	char * current = string;

	for (; current != '\0'; current++);
	return current - string;
}

void main(void)
{
	char myString1[] = "hello";
	char myString2[] = { 'a', 'b' ,'c', '\0' };
	size_t sizeOfString1 = StringLength("hello");
	size_t sizeOfString2 = StringLength(myString2);

	int test[] = { 1,2,3 };

	printf("my string %s \n", myString2);

	printf("The size of the array1 is %d \n", sizeOfString1);
	printf("The size of the array2 is %d \n", sizeOfString2);

	int number1 = -2, number2 = 10;

	printf("The number1 value is %d\n", number1);
	printf("The number2 value is %d\n", number2);


	Absolute(&number1);
	printf("The absolute value of number1 is %d\n", number1);

	Swap(&number2, &number1);

	int arr[2] = { 120,120 };
	arr[-100];
	printf("The number1 value is %d\n", number1);
	printf("The number2 value is %d\n", number2);

	int * numberTest = arr;

	int brr[2] = { 1 , 2 };
	int * p = brr; /* <==> p = &arr*/
	printf("%d \n", *p);
	++p; /* <==> p += sizeof(*p) Qd on incremente un pointeur ca increment la valeur de l'element pointe */
	printf("%d \n", *p);

	int matrix[DIM1][DIM2] = { { 10,20,30 } ,{ 30,40,50 } };

	/*naive way*/

	for (int i = 0; i < DIM1; i++)
	{
		for (int j = 0; j < DIM2; j++)
		{
			printf("%d \n", matrix[i][j]);
		}
	}

	int * vector = *matrix;// matrix[0] // &(matrix[0][0]); /*We take the address of the derefencing twice pointers to matrix */
	int * limit = vector + DIM1*DIM2;

	// int horribleMatrix[2][3][1] = { { { 1 } , { 1 }, { 1 } } , { { 1 } , { 1 } , { 1 } } };

	for (; vector < limit; ++vector)
	{
		printf("%d \n", *vector);
	}

	int i = 1024;
	//PrintBits(&i,sizeof(i))
	PRINT_BITS(i);


	char c = 'a';
	//PrintBits(&c,sizeof(c))
	PRINT_BITS(c);

	double d = 1.0;
	PRINT_BITS(d);

}