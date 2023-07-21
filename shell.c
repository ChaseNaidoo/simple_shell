#include "main.h"
#include <unistd.h>

/**
 * main - handles logic of the shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Success (0)
 *
 */
int main(int argc, char *argv[])
{
	char *user_input = NULL;
	ssize_t input_len;
	int input_file = -1;
	char *args[MAX_ARGS];
	int arg_count;
	char buffer[BUFFER_SIZE];
	int interactive_mode = isatty(STDIN_FILENO) && isatty(STDOUT_FILENO);
	size_t input_size = 0;
	char *directory;
	int exit_status = 0;

	if (argc > 1)
	{
	input_file = open(argv[1], O_RDONLY);

	if (input_file == -1)
		{
		perror("Error opening file");
		exit_status = 1;
		}
	}
	while (1)
	{
	if (interactive_mode)
		{
		write(STDOUT_FILENO, "($) ", 4);
		fflush(stdout);
		}
		if (input_file != -1)
			{
			input_len = read(input_file, buffer, BUFFER_SIZE);

			if (input_len <= 0)
			break;

			user_input = _strdup(buffer);
			}
		else
		{
		free(user_input);
		user_input = NULL;
		input_len = getline(&user_input, &input_size, stdin);

		if (input_len == -1)
		break;

		if (input_len > 0 && user_input[input_len - 1] == '\n')

		user_input[input_len - 1] = '\0';
		}

		if (input_len > 1 || (input_len == 1 && user_input[0] != '\n'))
		{
		arg_count = parse_arguments(user_input, args);
		args[arg_count] = NULL;

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
			exit_status = 0;
			break;
			}
			else if (_strncmp(args[0], "exit ", 5) == 0)
			{
			char *exit_status_str = args[0] + 5;

			if (*exit_status_str == '-')
			{
			write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", _strlen("./hsh: 1: exit: Illegal number: "));
			write(STDERR_FILENO, exit_status_str, _strlen(exit_status_str));
			write(STDERR_FILENO, "\n", 1);
			exit_status = 2;
			break;
			}
			else
				{
				exit_status = 0;
				break;
				}
			}
			else if (_strcmp(args[0], "clear") == 0)
			{
			clear_screen();
			continue;
			}
			else if (_strcmp(args[0], "env") == 0)
			{
			_env();
			continue;
			}
			else if (_strncmp(args[0], "cd ", 3) == 0)
			{
			directory = args[0] + 3;
			_cd(directory);
			continue;
			}
			else if (_strcmp(args[0], "./hbtn_ls") == 0)
			{
			char *hbtn_ls_path = find_command_path("hbtn_ls");

			if (hbtn_ls_path == NULL)
			{
			write(STDERR_FILENO, "hbtn_ls: command not found\n", 27);
			continue;
			}
			execute_command(args);

			free(hbtn_ls_path);
			continue;
			}
			execute_command(args);
			}
		}
		continue;
	}
	if (input_file != -1)
	close(input_file);
	free(user_input);
	return (exit_status);
}
