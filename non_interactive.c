#include "shell.h"

/**
 * non_interactive_mode - executes one comman passed as pipeline to STDIN
 */

void non_interactive_mode(void)
{
	char **command;
	int built_in_check = 1, loop = 1;

	command = _getline_NIM();
	if (command == NULL)
		exit(0);
	built_in_check = built_ins(command, loop);
	if (built_in_check == 0)
	{
		free_dp(command);
		exit(0);
	}
	interpeter_nim(command, loop);
	free_dp(command);
}

/**
 * interpeter_nim - Interprets a command in non-interactive mode
 *
 * @command: The command to be interpreted
 * @loop: Counter of how many loops since started
 */

void interpeter_nim(char **command, int loop)
{
	char *executable;

	executable = get_valid_exe(*command);
	if (executable == NULL)
		show_error(command, loop);
	else
		execve(executable, command, environ);
}
