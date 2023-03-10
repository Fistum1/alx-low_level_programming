#include "main.h"

/**
* _strspn - Gets the length of a prefix.
* @s: The string to be searched.
* @accept: The prefix to be measured.
* Return: The number of bytes in s which
 */
char *_strpbrk(char *s, char *accept)
{
int i;

while (*s)
{
for (i = 0; accept[i]; i++)
	{
	if (*s == accept[i])
	return (s);
	}
s++;
}
return ('\0');
}
