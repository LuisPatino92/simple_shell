#include "shell.h"

/**
 * non_interactive_mode - executes one comman passed as pipeline to STDIN
 */

void non_interactive_mode(void)
{
	char **command;
	int loop = 0, built_in_check = 1;

	command = _getline();
	if (command == NULL)
		exit(0);
	built_in_check = built_ins(command, loop);
	if (built_in_check == 0)
	{
		exit(0);
	}
	interpeter(command, loop);
	free_dp(command);
}
