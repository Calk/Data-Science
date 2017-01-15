#pragma once

#ifndef BOOL
#define BOOL int
#endif

/*
* Encrypts a src string into dst. Assumes dst is preallocated and is
* large enough for the task (should have at least the same size as src, including
* room for null byte terminator).
*
* Decrypt by sending negative shiftBy to CaesarEncrypt.
*/

BOOL CaesarEncrypt(char *dst, const char *src, int shiftBy);
