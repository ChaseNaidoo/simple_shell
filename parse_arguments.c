#include "main.h"

/**
 * parse_arguments - tokenises input string and stores arguments in array
 *
 * @input: input string
 * @args: array to store arguments
 *
 * Return: number of arguments
 *
 */
int parse_arguments(char *input, char **args)
{
	int count = 0;
	char *token;

	token = strtok(input, " \t\n\r");

	while (token != NULL && count < MAX_ARGS - 1)
	{
	args[count] = token;
	count++;
	token = strtok(NULL, " \t\n\r");
	}
	args[count] = NULL;

	return (count);
}
