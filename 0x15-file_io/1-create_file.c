#include "main.h"

/**
 * create_file - File creator.
 * @filename: Ptr to the name of the file to create.
 * @text_content: Ptr to a string to write to the file.
 * return: If the function fails - -1.
 */

int create_file(const char *filename, char *text_content)
{
	int ox, wx, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	ox = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wx = write(ox, text_content, len);

	if (ox == -1 || wx == -1)
		return (-1);

	close(ox);

	return (1);
}
