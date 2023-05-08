#include "main.h"
/**
 * create_file - which creates a file.
 * @filename1: pointer to the name of the file.
 * @text_content1: pointer to a string to write to the file.
 * return: If the function fails - -1.
 */

int create_file(const char* filename1, char* text_content1)
{
	int o, w, len = 0;

	if (filename1 == NULL)
		return (-1);
	if (text_content1 != NULL)
	{
		for (len = 0; text_content1[len];)
			len++;
	}
	o = open(filename1, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content1, len);
		if (o == -1 || w == -1)
		return (-1);
	close(o);
	return (1);
}