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
void PrintRectangle(int dim1, int dim2)
{
	//Create the string that will be printed dim2 times
	char line[MAX_LENGTH] = "";
	for (size_t i = 0; i < dim1; i++)
	{
		AppendCharacter(line, '*');
	}

	//Print the string line dim2 times
	for (size_t i = 0; i < dim2; i++)
	{
		printf("%s\n", line);
	}
}

int main()
{
	int dimension1;
	int dimension2;

	printf("Enter two dimensions for the rectangle: ");

	//Gather Input From the User and validate the format of it
	if (scanf_s("%i %i", &dimension1, &dimension2) == 2 || dimension1 > MAX_LENGTH || dimension2 > MAX_LENGTH)
	{
		//Convert measure for the desired unit
		PrintRectangle(dimension1, dimension2);
	}
	else
	{
		printf(INPUT_ERROR_MESSAGE);
	}

	return SUCCESS_ZERO;
}





