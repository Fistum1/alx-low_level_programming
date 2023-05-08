#include "main.h" 

/**
 *read_textfile -  Reads and prints to the POSIX standard output.
 *@filename: file name.
 *@letters: number of letters to print.
 *Description - read_textfile: reads a text file and prints.
 *Return: null if it failes.
 */
ssize_t read_textfile(const char* filename1, size_t letter1)
{
ssize_t o, r, w;
char* bff;

if (filename1 == NULL)
return (0);

bff = malloc(sizeof(char) * letter1);
if (bff == NULL)
return (0);

o = open(filename1, O_RDONLY);
r = read(o, bff, letter1);
w = write(STDOUT_FILENO, bff, r);

if (o == -1 || r == -1 || w == -1 || w != r)
{
free(bff);
return (0);
}

free(bff);
close(o);

return (w);
}
