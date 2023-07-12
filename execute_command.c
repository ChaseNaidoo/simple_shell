#include "main.h"

/**
 * execute_command - executes shell commands
 *
 * @argv: argument vector
 *
 * Return: (no return)
 */
void execute_command(char **argv)
{
        pid_t child_pid;
        char *path_env_ptr;
        char *command_path;
        char *error_message = NULL;

        if (argv == NULL || argv[0] == NULL)
        {
        return;
        }
        if (argv[0][0] == '/')
        command_path = argv[0];
        else
        {
        path_env_ptr = get_path_env();
        if (path_env_ptr == NULL)
        {
        perror("PATH environment variable not set.\n");
        return;
        }
        command_path = find_command_path(path_env_ptr, argv[0]);

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
        }
        child_pid = fork();

        if (child_pid == -1)
        {
        perror("Fork failed");
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
        int status;

        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        return;
        else
        return;
        }
}
