#include "main.h"
#include <unistd.h>
/**
 * _isupper - check if char is upper alphabet
 *@x: char parameter
 * _isupper: checks if it is upper case letter
 * Return: zero or one
 */

int _isupper(int x)
{
	if (x >= 'A' && x <= 'Z')
	return (1);
	else
	return (0);
}
