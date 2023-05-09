#include "main.h"
#include <stdlib.h>

/**
 *read_textfile - Reads and prints it to the POSIX standard output.
 *@filename: File name.
 *@letters: Number of letters to print.
 *Description - read_textfile: Function that reads a text file and print.
 *Return: Null if it failes.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t ox, rx, wx;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	ox = open(filename, O_RDONLY);
	rx = read(ox, buffer, letters);
	wx = write(STDOUT_FILENO, buffer, rx);

	if (ox == -1 || rx == -1 || wx == -1 || wx != rx)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(ox);

	return (wx);
}

