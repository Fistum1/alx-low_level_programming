#include "main.h"

/**
 *_memcpy - Copies @n bytes from the memory
 *@dest: to copy @src into.
 *@src:  to copy characters from.
 *@n: The number of bytes to copy from @src.
 * Return: A pointer to the destination buffer @dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *destination = dest;

	const char *source = src;
	for (i = 0; i < n; i++)
		destination[i] = source[i];

	return (dest);
}
