
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Ceasar.h"

#define MAX_FILE_SIZE 1000
#define BUFFER_SIZE 255
#define MINI_PARAMETER_SIZE 2
#define TRUE 1
#define FALSE 1
#define SUCCESS_EXECUTION 1

char *ReadFromFile(char *nameOfFileToRead)
{
	char inputString[MAX_FILE_SIZE];
	FILE *fileToRead;
	if ((fileToRead = fopen(nameOfFileToRead, "r")) == NULL)
	{
		printf("Error! opening file");
		exit(TRUE);
	}

	// reads text until newline 
	fscanf(fileToRead, "%[^\n]", inputString);

	printf("%s\n", inputString);
	fclose(fileToRead);

	return inputString;
}

void PrintOutput(char* fileToWrite, char * stringToPrint)
{
	FILE *f = fopen(fileToWrite, "w");
	if (f == NULL)
	{
		printf("%s\n", stringToPrint);
		exit(TRUE);
	}

	/* print some text */
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);
	fclose(f);
}

//It is possible to pass arguments in debug mode by goind to project -> properties-> debugging and passing the parameters
void main(int argc, char *argv[])
{
	//Print All the Arguments Entered by the user
	//printf("\nexe name=%s", argv[0]);

	//Get the option from the user (decrypt or encrypt)
	char *option = malloc((argv[1]?strlen(argv[1]):"") + 1);
	option = argv[1];
	if (!option || (strcmp(option, "-d") && strcmp(option, "-e")))
	{
		printf("You should enter -d for decryption or -e for encryption");
		return SUCCESS_EXECUTION;
	}

	
	if (strcmp(option, "-d") || strcmp(option, "-e"))
	{
		printf("You should enter -d for decryption or -e for encryption");
		return SUCCESS_EXECUTION;
	}

	int	success = 0;
	do
	{
		ReadFromFile("input.txt");
		char answer;
		printf("Do you want to encrypt(y) or decrypt(f) ?");
		scanf("%c", &answer);

		char input[BUFFER_SIZE], output[BUFFER_SIZE];
		printf("Please type your message: ");
		scanf_s("%s", &input, BUFFER_SIZE);	//Scanf dont do dynamically allocations
		getchar();

		switch (answer)
		{
		case 'y':
		case 'Y':
			success = 1;
			EncryptCeasar(&output, &input);
			printf("The Encrypted message is %s", output);
			break;

		case 'f':
		case 'F':
			success = 1;
			DecryptCesar(&output, &input);
			printf("The Decrypt message is %s", output);
			break;

		default:
			printf("Invalid Command \n");
			//break;	//When you dont need to put a break, dont use it;
		}
	} while (!success);
	
	/*char *cypher = CypherString(&buffer);
	printf("The Cypher of Ceaser is: %s\n", cypher);*/

	return 0;
}

	
