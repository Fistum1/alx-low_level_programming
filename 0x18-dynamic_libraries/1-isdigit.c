#include "main.h"

/**
 *_isdigit - if input is digit or not
 *@x: is input parameter
 *Return: is one or zero 1 or 0
 */

int _isdigit(int x)
{
	if ((x >= 48) && (x <= 57))
	{
	return (1);
	}
	else
	{
	return (0);
	}
}
