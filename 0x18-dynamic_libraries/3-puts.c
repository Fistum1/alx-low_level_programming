#include "main.h"

/**
 * _puts - prints the a string
 *@str: char parameter
 * Return: returns nothing
 */

void _puts(char *str)
{
	int s = 0;

	while (*(str + s) != '\0')
	{
	_putchar(*(str + s));
	s++;
	}
	_putchar('\n');
}
