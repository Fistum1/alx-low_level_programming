#include "main.h" 


/**
 * 
 *read_textfile -  Reads and prints it to the POSIX standard output.
 *@filename: File name.
 *@letters: Number of letters to print.
 *Description - read_textfile: Function that reads a text file and print.
 *Return: Null if it failes.

 */

ssize_t read_textfile(const char* filename, size_t letters)
{
ssize_t o, r, w;
char* bff;

if (filename == NULL)
return (0);

bff = malloc(sizeof(char) * letters);
if (bff == NULL)
return (0);

o = open(filename, O_RDONLY);
r = read(o, bff, letters);
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
