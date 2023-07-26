#ifndef MAIN_H
#define MAIN_H

#define INVALID_MODE_ERROR 2
#define PATH_DELIMITER ":"
#define MAX_ARGS 1024
#define MAX_PATH_LENGTH 3072
#define BUFFER_SIZE 4096
#define MAX_FILES 100

extern char **environ;

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _strlen(const char *s);
int _putenv(char *string);
int parse_arguments(char *input, char **args);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_getenv(const char *name);
void clear_screen(void);
void _memcpy(void *dest, const void *src, size_t n);
void int_to_str(int num, char *str);
void execute_command(char **argv);
void _env(void);
char *get_path_env(void);
void list_files(void);
char *_memset(char *s, char b, unsigned int n);
char *find_command_path(const char *command);
void _cd(const char *directory);
int _atoi(char *s);

#endif
