#include "main.h"

/**
<<<<<<< HEAD
 * parse_arguments - tokenises input string and stores arguments in array
 *
 * @input: input string
 * @args: array to store arguments
=======
 * parse_arguments - Tokenises input string and stores arguments in array
 *
 * @input: input string
 * @args: array to store arugments
>>>>>>> 5db307598998b3bc92b11c6bdb5185edae3b5aa5
 *
 * Return: number of arguments
 *
 */
int parse_arguments(char *input, char **args)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 5db307598998b3bc92b11c6bdb5185edae3b5aa5
}
