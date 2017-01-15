/*This code has the purpose of asking the user for dimensions,
and then printing a rectangle with those dimensions on the screen*/

#include <stdio.h>

#define SUCCESS_ZERO 0
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 256
#define INPUT_ERROR_MESSAGE "Bad Formatted Inputs \n"
#define END_MESSAGE "Program Finished !"

//Function for appending char to a existing string
void AppendCharacter(char *s, char c)
{
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

//Function for printing the Rectangle in the Console given the dimension parameters
int HaveRepeatedChar(char* tempWord)
{
	int counts[256] = { 0 };

	int i;
	size_t len = strlen(tempWord);

	for (i = 0; i < len; i++) {
		counts[(int)(tempWord[i])]++;
	}

	for (i = 0; i < 256; i++) {
		if (counts[i] > 1)
			return TRUE;
	}
	return FALSE;
}

int main(int argc, char *argv[])
{
	for (size_t i = 1; i < argc; i++)
	{
		if (HaveRepeatedChar(argv[i]))
			printf("%s ", argv[i]);
	}

	return SUCCESS_ZERO;
}