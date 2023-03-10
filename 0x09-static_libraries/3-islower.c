#include "main.h"
/**
 * _islower - checks is it lower
 * @x : input parameter
 * Return: is result
 */
int _islower(int x)
{

	if (x >= 'a' && x <= 'z')
		return (1);
	else
		return (0);
}
