#include "main.h" 

/**
 *read_textfile -  Reads and prints to the POSIX standard output.
 *@filename1: file name.
 *@letter1: number of letters to print.
 *Description - read_textfile: reads a text file and prints.
 *Return: null if it failes.
 */
ssize_t read_textfile(const char* filename1, size_t letter1)
{
ssize_t o, r, w;
char* bff1;

if (filename1 == NULL)
return (0);

bff1 = malloc(sizeof(char) * letter1);
if (bff1 == NULL)
return (0);

o = open(filename1, O_RDONLY);
r = read(o, bff1, letter1);
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
