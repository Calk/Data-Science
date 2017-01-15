#include <stdio.h>
#include <string.h>

#define BUF_MAX 255

struct _InputStruct
{
	int len;
	char * tempString;
};
typedef struct _InputStruct InputStruct;

int ProcessString(InputStruct inputStruct)
{
	if (inputStruct.len >= 2)
	{
		++inputStruct.tempString;
		*inputStruct.tempString = 'a';
	}
}

void main()
{
	char bufString[BUF_MAX];
	strcpy(bufString, "This is tutorialspoint.com");
	int len = strlen(bufString);

	InputStruct inputStruct;
	inputStruct.len = len;
	inputStruct.tempString = bufString;

	printf("orginal string %s\n", inputStruct.tempString);
	ProcessString(inputStruct);
	printf("processed string %s\n", inputStruct.tempString);
}