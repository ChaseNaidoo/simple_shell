#include "main.h"

/**
 * execute_command - executes shell commands
 *
 * @argv: argument vector
 *
 * Return: (no return)
 *
 */
void execute_command(char **argv)
{
	pid_t child_pid;
	char *path_env_ptr;
	char *command_path = NULL;
	char *error_message = NULL;
	int should_free_command_path = 0;
	int status;

	if (argv == NULL || argv[0] == NULL)
	{
	return;
	}
	if (_strcmp(argv[0], "hbtn_ls") == 0)
	{
	command_path = find_command_path("hbtn_ls");

	if (command_path == NULL)
		{
		write(STDERR_FILENO, "hbtn_ls: command not found\n", 27);
		return;
		}
	should_free_command_path = 1;
	}
	else if (argv[0][0] == '/')
	{
	command_path = argv[0];
	}
	else
	{
	path_env_ptr = get_path_env();

	if (path_env_ptr == NULL)
	{
	perror("PATH environment variable not set.\n");
	return;
	}
	command_path = find_command_path(argv[0]);

	free(path_env_ptr);

	if (command_path == NULL)
	{
	error_message = malloc((_strlen(argv[0]) + _strlen(": command not found\n") + 1) * sizeof(char));

	if (error_message == NULL)
		{
		perror("Memory allocation failed.\n");
		return;
		}
	_strcpy(error_message, argv[0]);
	_strcat(error_message, ": command not found\n");
	write(STDERR_FILENO, error_message, _strlen(error_message));
	free(error_message);
	return;
	}
	should_free_command_path = 1;
	}
	child_pid = fork();

	if (child_pid == -1)
	{
	perror("Fork failed");

	if (should_free_command_path)
	free(command_path);
	return;
	}
	else if (child_pid == 0)
	{
	execve(command_path, argv, environ);
	perror("Execution failed");
	exit(EXIT_FAILURE);
	}
	else
	{
	waitpid(child_pid, &status, 0);

	if (WIFEXITED(status))
	{
	int exit_status = WEXITSTATUS(status);

	if (argv[1] != NULL)
		{
		if (_strcmp(argv[1], "&&") == 0)
			{
			if (exit_status == 0 && argv[2] != NULL)
				{
				execute_command(argv + 2);
				}
			}
		else if (_strcmp(argv[1], "||") == 0)
			{
			if (exit_status != 0 && argv[2] != NULL)
				{
				execute_command(argv + 2);
				}
			}
		}
	}
	if (should_free_command_path)

	free(command_path);
	}
}
