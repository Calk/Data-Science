#include <stdio.h>
#include "Caesar.h"

#define BUF_SIZE 1000
#define SHIFT_BY 3

void main()
{
	int success = 0;

	do
	{
		printf("Do you want to encrypt? (y - encrypt, n - decrypt) ");

		char answer;
		scanf_s("%c", &answer, 1);
		// TODO: Fix UI bug.
		printf("Please type your message: ");
		char input[BUF_SIZE], output[BUF_SIZE];
		if (1 != scanf_s("%s", input, BUF_SIZE))
		{
			/* error */
			return;
		}

		//TODO: Basically true/flase, why the switch()?
		switch (answer)
		{
		case 'y':
		case 'Y':
			success = 1;
			CaesarEncrypt(output, input, SHIFT_BY);
			printf("You encrypted message is: %s\n", output);
			break;

		case 'n':
		case 'N':
			success = 1;
			CaesarEncrypt(output, input, -SHIFT_BY);
			printf("You decrypted message is: %s\n", output);
			break;

		default:
			printf("Invalid command: \"%c\".\n", answer);
		}
	} while (!success);
}