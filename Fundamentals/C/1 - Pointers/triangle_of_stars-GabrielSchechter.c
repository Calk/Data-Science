/*This code has the purpose of asking the user for dimensions,
and then printing a triangle with those dimensions on the screen*/

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

//Function for removing last char to a existing string
void RemoveLastCharacter(char *s)
{
	int len = strlen(s);
	if (len >= 1)
	{
		s[len - 1] = '\0';
	}
}

//Function for printing the Rectangle in the Console given the dimension parameters
void PrintTriangle(int dim)
{
	//Create the string that will be printed dim2 times
	char line[MAX_LENGTH] = "";

	while (strlen(line) < dim)
	{
		AppendCharacter(line, '*');
		printf("%s\n", line);
	}

	while (strlen(line) > 0)
	{
		RemoveLastCharacter(line);
		printf("%s\n", line);
	}
}

int main()
{
	int dimensions;

	printf("Enter the dimension for the triangle: ");

	//Gather Input From the User and validate the format of it
	if (scanf_s("%i", &dimensions) == 1 || dimensions > MAX_LENGTH)
	{
		//Convert measure for the desired unit
		PrintTriangle(dimensions);
	}
	else
	{
		printf(INPUT_ERROR_MESSAGE);
	}

	return SUCCESS_ZERO;
}





