#include "shell.h"

/**
 * built_ins - Checks if a command is a built-in
 *
 * @command: The command to be compared
 * @loop: The loop counter to show errors
 *
 * Return: 0 if some built in executed, 1 otherwise
 */

int built_ins(char **command, __attribute__((unused))int loop)
{
	int i;

	if (!_strcmp(*(command), "exit"))
	{
		free_dp(command);
		exit(0);
	}

	if (!_strcmp(*(command), "env"))
	{
		for (i = 0; *(environ + i); i++)
		{
			write(STDOUT_FILENO, *(environ + i), _strlen(*(environ + i)));
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	return (1);
}
