#include "shell.h"

/**
 * interactive_mode - Interactive commandline interpeter
 */

void interactive_mode(void)
{
	char **command;
	int loop = 0, built_in_check = 1;

	signal(SIGINT, signal_handler);

	while (++loop)
	{
		show_prompt();
		command = _getline();
		if (command == NULL)
			continue;
		built_in_check = built_ins(command, loop);
		if (built_in_check == 0)
		{
			continue;
		}
		interpeter(command, loop);
		free_dp(command);
	}
}

/**
 * show_prompt - Shows a prompt on the stdout
 */

void show_prompt(void)
{
	char *identifier = "[\033[31m#FAKE SHELL\033[37m] /.../";
	char *current;
	int i, j, k = 0, last_index;

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), "PWD=", 4))
		{
			for (j = 0; *(*(environ + i) + j); j++)
				if (*(*(environ + i) + j) == 47)
					last_index = j;

			k = (_strlen(identifier)) + (_strlen(*(environ + i) + last_index + 1)) + 4;

			current = malloc(k * sizeof(char));
			if (current == NULL)
				return;

			for (k = 0; k < _strlen(identifier); k++)
				*(current + k) = *(identifier + k);

			for (j = 0; j < _strlen((*(environ + i) + last_index + 1)); j++)
				*(current + k + j) = (*(*(environ + i) + last_index + 1 + j));

			*(current + k + j) = 32;
			*(current + k + j + 1) = 36;
			*(current + k + j + 2) = 32;
			*(current + k + j + 3) = 0;
			break;
		}
	}

	write(STDOUT_FILENO, current, _strlen(current));
	free(current);
}
