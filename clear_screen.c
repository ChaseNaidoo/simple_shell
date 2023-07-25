#include "main.h"

/**
 * clear_screen - Emulates the system 'clear' function
 *
 * Return: (no return)
 *
 */
void clear_screen(void)
{
  char *term_value = _getenv("TERM");
	const char *clear_sequence;

	if (term_value == NULL)
	{
	if (_setenv("TERM", "xterm", 1) != 0)
		{
		perror("Error setting TERM environment variable");
		return;
		}
	}
	clear_sequence = "\033[H\033[2J";

	if (write(STDOUT_FILENO, clear_sequence, _strlen(clear_sequence)) == -1)
	{
	perror("Error clearing screen");
	return;
	}
}
