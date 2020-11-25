#include "shell.h"

/**
 * non_interactive_mode - executes one comman passed as pipeline to STDIN
 */

void non_interactive_mode(void)
{
	char buf[2048], *buffer = NULL, **command = NULL;
	ssize_t bytes_readed;
	int i;

	bytes_readed = read(STDIN_FILENO, buf, 2048);

	if (buf[0] == 10)
		exit (0);

	buffer = _calloc(bytes_readed, sizeof(char));
	if (buffer == NULL)
		return;

	for (i = 0; i < bytes_readed; i++)
		*(buffer + i) = *(buf + i);
	*(buffer + i - 1) = 0;

	command = _strtok(buffer, 32);
	if (command == NULL)
	{
		free(buffer);
		free_dp(command);
		return;
	}

	free(buffer);
	interpeter(command, 1);
	free_dp(command);
}
