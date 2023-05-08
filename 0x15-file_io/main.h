#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
ssize_t read_textfile(const char* filename1, size_t letter1);
int create_file(const char* filename1, char* text_content1);
int append_text_to_file(const char* filename1, char* text_content1);
#endif
