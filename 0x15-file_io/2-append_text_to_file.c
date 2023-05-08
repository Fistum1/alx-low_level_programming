#include "main.h"
/**
 * append_text_to_file - Append a text at the end of a file.
 * @filename1: A ptr to the name of the file.
 * @text_content1: The string to add at the end of the file.
 * Return: If the function fails/ filename1 is NULL - -1.
 *         If the file does not have a write permissions - -1.
 */

int append_text_to_file(const char* filename1, char* text_content1)
{
	int o, w, len = 0;

	if (filename1 == NULL)
		return (-1);
	if (text_content1 != NULL)
	{
		for (len = 0; text_content1[len];)
			len++;
	}
	o = open(filename1, O_WRONLY | O_APPEND);
	w = write(o, text_content1, len);
	if (o == -1 || w == -1)
		return (-1);
	close(o);
	return (1);
}
