/*This code has the purpose of asking the user for dimensions,
and then printing a rectangle with those dimensions on the screen*/

#include <stdio.h>

#define SUCCESS_ZERO 0
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 256
#define INPUT_ERROR_MESSAGE "Bad Formatted Inputs \n"
#define END_MESSAGE "Program Finished !"

int main(int argc, char *argv[])
{
	//The strange thing is that the transformation to hexa only works for number there could be represented within 4 bytes in hexa.

	int input_int;
	if (1 != scanf_s("%i", &input_int))
	{
		/* error */
		return;
	}

	char hex[MAX_LENGTH];
	sprintf(hex, "%x", input_int);
	puts(hex);

	return SUCCESS_ZERO;
}