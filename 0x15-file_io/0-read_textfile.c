#include "main.h"
#include <stdlib.h>

/**
 *read_textfile - Reads and prints it to the POSIX standard output.
 *@filename1: File name.
 *@letters1: Number of letters to print.
 *Description - read_textfile: Function that reads a text file and print.
 *Return: Null if it failes.
 */

ssize_t read_textfile(const char *filename1, size_t letters1)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters1);
	if (buffer == NULL)
		return (0);

	o = open(filename1, O_RDONLY);
	r = read(o, buffer, letters1);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}

