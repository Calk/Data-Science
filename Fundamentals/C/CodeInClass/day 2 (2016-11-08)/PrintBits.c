#include <stdio.h>

/*
 * PRINT_BITS macro description goes here.
 */
#define PRINT_BITS(x) (PrintBits((&(x)), sizeof(x)))

void PrintBits(void *pValue, size_t byteCount)
{
	unsigned char *bytes = (unsigned char *) pValue;

#ifdef LITTLE_ENDIAN
	for (int byteNo = byteCount - 1; byteNo >= 0; --byteNo)
#else
	for (size_t byteNo = 0; byteNo < byteCount; ++byteNo)
#endif
	{
		for (int bitNo = 7; bitNo >= 0; --bitNo)
		{
			printf("%c", (bytes[byteNo] & 1 << bitNo) ? '1' : '0');

			if (bitNo == 4)
			{
				printf(" ");
			}
		}

		printf("\n");
	}

}

void main(void)
{
	int i = 0x01020304;

	printf("%d, in bits:\n", i);
	//PrintBits(&i, sizeof(i));
	PRINT_BITS(i);

	double d = 0.1;
	
	printf("\n%f, in bits:\n", d);
	//printbits(&d, sizeof(d));
	PRINT_BITS(d);
}