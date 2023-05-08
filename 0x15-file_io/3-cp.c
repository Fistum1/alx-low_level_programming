#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char* create_buffer(char* file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: Name of the file buffer is storing chars.
 * Return: A ptr to the newly-allocated buffer.
 */

char* create_buffer(char* file1)
{
	char* buffer1;

	buffer1 = malloc(sizeof(char) * 1024);

	if (buffer1 == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file1);
		exit(99);
	}

	return (buffer1);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd1)
{
	int c;

	c = close(fd1);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: Number of arguments supplied to the program.
 * @argv: Array of ptrs to the arguments.
 *
 * Return: 0 on success.
 
 */
int main(int argc1, char* argv1[])
{
	int from, to, r, w;
	char* buffer1;

	if (argc1 != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer1 = create_buffer(argv1[2]);
	from = open(argv1[1], O_RDONLY);
	r = read(from, buffer1, 1024);
	to = open(argv1[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv1[1]);
			free(buffer1);
			exit(98);
		}

		w = write(to, buffer1, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv1[2]);
			free(buffer1);
			exit(99);
		}

		r = read(from, buffer1, 1024);
		to = open(argv1[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer1);
	close_file(from);
	close_file(to);

	return (0);
}
