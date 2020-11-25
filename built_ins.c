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
	if (!_strcmp(*(command), "exit"))
	{
		free_dp(command);
		exit(0);
	}

	return (1);
}
