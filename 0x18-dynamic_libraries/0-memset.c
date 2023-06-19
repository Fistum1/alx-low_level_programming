#include "main.h"

/**
 * _memset - that fills memory with a constant byte
 * @s: A pointer to the memory.
 * @c: The buffer character to fill.
 * @n: The size of bytes to be filled.
 * description _memset: a function that fills memory with a constant byte
 * Return: char.
 */

char *_memset(char *s, char b, unsigned int n)
{
long unsigned int i;
char *mem = s;

for (i = 0; i < n; i++)
	mem[i] = b;
return (mem);
}
