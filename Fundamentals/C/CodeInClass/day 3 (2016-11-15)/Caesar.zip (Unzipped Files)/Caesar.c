#include "Caesar.h"

#define NUMBER_OF_LETTERS ('Z' - 'A' + 1)

/*
 * Encrypt capital letters only.
 */
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
	/* else - c is lower case or not alpha, ignore */

	return c;
}

BOOL CaesarEncrypt(char *dst, const char *src, int shiftBy)
{
	BOOL result = 0;

	if (dst && src && (shiftBy > -NUMBER_OF_LETTERS) && (shiftBy < NUMBER_OF_LETTERS))
	{
		result = 1; /* pessimistic assumption */
		for (; *src; ++src, ++dst)
		{
			*dst = EncryptChar(*src, shiftBy);
		}

		(*dst) = '\0';
	}

	return result;
}