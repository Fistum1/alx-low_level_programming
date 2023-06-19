#include "main.h"
/**
 * _strlen - gives the size of string
 *@s: char parameter
 * Return: returns s size
 */

int _strlen(char *s)
{
	int size = 0;

	while (*(s + size) != '\0')
	size++;
	return (size);
}
