#pragma once

#include <stdio.h>
#include <ctype.h>
#include "Ceasar.h"

void EncryptCeasar(char* dest, const char * src)
{
	if (*src)
	{
		for (; *src; ++src, ++dest)
		{
			//TODO fix uppercase and lowercase
			if (toupper(*src) >= 'A' &&  toupper(*src) <= 'Z')
			{
				switch (tolower(*src))
				{
				case 'x':
					(*dest) = 'a';
					break;
				case 'y':
					(*dest) = 'b';
					break;
				case 'z':
					(*dest) = 'c';
					break;
				default:
					(*dest) = tolower(*src) + 3;
					break;
				}
			}
			else
			{
				*dest = *src;
			}
		}

		(*dest) = '\0';
	}
}

void DecryptCesar(char* dest, const char *src)
{
	if (*src)
	{
		for (; *src; ++src, ++dest)
		{
			if (toupper(*src) >= 'A' &&  toupper(*src) <= 'Z')
			{
				switch (tolower(*src))
				{
				case 'a':
					(*dest) = 'x';
					break;
				case 'b':
					(*dest) = 'y';
					break;
				case 'c':
					(*dest) = 'z';
					break;
				default:
					(*dest) = tolower(*src) - 3;
					break;
				}
			}
			else
			{
				*dest = *src;
			}
		}
		(*dest) = '\0';
	}
}