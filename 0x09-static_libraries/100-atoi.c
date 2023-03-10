#include "main.h"

/**
* _atoi - converts a strings to intiges
* @s: the string parameter
*
* Return: the intiges
*/

int _atoi(char *s)
{
	int size = 0;
	int i, sign = 0;
	unsigned int val = 0;

	while (*(s + size) != '\0')
	{
	size++;
	}

	for (i = 0; i < size; i++)
	{
		if (*(s + i) == 45)
			sign = 1;
		else if (*(s + i) == 43 || *(s + i) == 32)
			sign = 0;
		else if (*(s + i) >= 48 && *(s + i) <= 57)
		{
			val *= 10;
			val = val + (*(s + i) - 48);
		}
	}
		if (sign == 1)
			val *= -1;
	return (val);
}
