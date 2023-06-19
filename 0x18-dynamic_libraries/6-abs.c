#include "main.h"
/**
 * _abs - function for absolut numbers
 * Description: absolute checker
 *@x: is used for input parameter
 * Return:0
 */
int _abs(int x)
{
	if (x == 0 || x > 0)
		return (x);
	else
		return (x * -1);
}
