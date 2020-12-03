#include "shell.h"

/**
 * execute - executes a program
 *
 * @command: The command to be executed (includes path)
 * @args: The arguments of the program to bbe execute
 */

void execute(char *command, char **args)
{
	ssize_t child_detect;

	child_detect = fork();
	wait(NULL);
	if (child_detect == 0)
		execve(command, args, environ);
}
