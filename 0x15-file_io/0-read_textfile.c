#include "main.h" 

/**
 *read_textfile -  Reads and prints to the POSIX standard output.
 *@filename: file name.
 *@letters: number of letters to print.
 *Description - read_textfile: reads a text file and prints.
 *Return: null if it failes.
 */
ssize_t read_textfile(const char* filename, size_t letters)
{
ssize_t o, r, w;
char* bff1;

if (filename == NULL)
return (0);

bff1 = malloc(sizeof(char) * letters);
if (bff1 == NULL)
return (0);

o = open(filename, O_RDONLY);
r = read(o, bff1, letters);
w = write(STDOUT_FILENO, bff1, r);

if (o == -1 || r == -1 || w == -1 || w != r)
{
free(bff1);
return (0);
}

free(bff1);
close(o);

return (w);
}


