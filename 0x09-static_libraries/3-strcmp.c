#include "main.h"

/**
* _strcmp - Copy paste strings
* @s1: 1st string
* @s2: 2nd string
*
* Return: result
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int result = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (*(s1 + i) == *(s2 + i))
			i++;
		else if (*(s1 + i) > *(s2 + i))
		{
			result = 1;
			break;
		}
		else if (*(s1 + i) < *(s2 + i))
		{
			result = -1;
			break;
		}
	}
	return (result);
}
