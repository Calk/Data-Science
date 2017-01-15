#include <stdio.h>
#include <string.h>

#define BUF_MAX 255

int ProcessString(char* stringToProcess, int strLength)
{
	if (strLength >= 2)
	{
		++stringToProcess;
		*stringToProcess = 'a';
	}
}

void main()
{
	char tempString[BUF_MAX];
	strcpy(tempString, "This is tutorialspoint.com");
	int len = strlen(tempString);

	printf("orginal string %s\n", tempString);
	ProcessString(tempString, len);
	printf("processed string %s\n", tempString);
}