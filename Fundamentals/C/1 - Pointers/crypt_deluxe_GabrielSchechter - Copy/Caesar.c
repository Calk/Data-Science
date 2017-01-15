#include "Caesar.h"
#include <string.h>

#define NUMBER_OF_LETTERS ('Z' - 'A' + 1)

//Encrypt Method
char EncryptChar(char c, int shiftBy)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		/* c is upper case */
		/* Get the ordinal value of c: */
		c -= 'A';
		c += shiftBy + NUMBER_OF_LETTERS;
		c %= NUMBER_OF_LETTERS;
		c += 'A';
	}
	else if ((c >= 'a') && (c <= 'z'))
	{
		/* c is lower case */
		/* Get the ordinal value of c: */
		c -= 'a';
		c += shiftBy + NUMBER_OF_LETTERS;
		c %= NUMBER_OF_LETTERS;
		c += 'a';
	}
	/* else - c is not alpha, ignore */

	return c;
}

int GetOrdinalValue(char lastChar)
{
	if ((lastChar >= 'A') && (lastChar <= 'Z'))
		lastChar -= 'A';
	else if ((lastChar >= 'a') && (lastChar <= 'z'))
		lastChar -= 'a';
	
	return lastChar;
}

BOOL CaesarEncrypt(char *dst, const char *src, int shiftBy)
{
	BOOL result = 0;

	if (dst && src && (shiftBy > -NUMBER_OF_LETTERS) && (shiftBy < NUMBER_OF_LETTERS))
	{
		result = 1; /* pessimistic assumption */

		//Shift by standard shift the first letter
		*dst = EncryptChar(*src, shiftBy);
		*src++;
		*dst++;

		//Capture Ordinal value of last original letter
		char lastChar = "";
		lastChar = src[(strlen(src) - 1)];
		int lastCharValue = 0;

		//Just check if we want to decrypt or encrypt
		if (shiftBy < 0)
		{
			//shiftby is negative in this case.
			char lastCharWithoutShift = EncryptChar(lastChar, shiftBy);
			lastCharValue = GetOrdinalValue(lastCharWithoutShift);
			lastCharValue /= 2;
			shiftBy -= lastCharValue;
		}
		else
		{
			lastCharValue = GetOrdinalValue(lastChar);
			shiftBy += lastCharValue;
		}

		//Shift adding ordinal to the rest of the characters
		for (; *src; ++src, ++dst)
		{
			//First Shift
			*dst = EncryptChar(*src, shiftBy);
		}

		(*dst) = '\0';
	}

	return result;
}

