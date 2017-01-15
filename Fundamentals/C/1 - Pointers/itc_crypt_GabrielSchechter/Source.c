#include <stdio.h>
#include "Caesar.h"

#define BUF_SIZE 20

void main()
{
	int success = 0;

	do
	{
		//- key(integer) : Number used as the shift parameter
		//- mode(character) : Should be either ‘e’ for encryption, or ‘d’ for decryption
		//- text(string of at most 20 characters) : Plaintext when in encryption mode, ciphertext in decryption mode.
		printf("Enter the key, the mode and the text: \n");

		int shift_value;
		char answer;
		char input[BUF_SIZE], output[BUF_SIZE];
		if (3 != scanf_s("%i %c %s", &shift_value, &answer, 1, input, BUF_SIZE))
		{
			/* error */
			return;
		}

		switch (answer)
		{
		case 'e':
		case 'E':
			success = 1;
			CaesarEncrypt(output, input, shift_value);
			printf("You encrypted message is: %s\n", output);
			break;

		case 'd':
		case 'D':
			success = 1;
			CaesarEncrypt(output, input, -shift_value);
			printf("You decrypted message is: %s\n", output);
			break;

		default:
			printf("Invalid command: \"%c\".\n", answer);
		}
	} while (!success);
}