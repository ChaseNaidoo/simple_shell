#ifndef _MAIN_H
#define _MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const *s2);
int _strlen(const char *s);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);

#endif
