#include "shell.h"

/**
 * _getline - Reads the command from STDIN and tokenizes it
 *
 * Return: The tokenized command or NULL at files
 */

char **_getline(void)
{
	char buf[4096], **command = NULL, *buffer = NULL;
	int i = 0, k = 0;

	do {
		if (read(STDIN_FILENO, buf + i, 1) == 0)
		{
			if (i-- == 0)
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(0);
			}
		}
	} while (*(buf + ++i - 1) != 10);

	if (*buf == 10)
		return (NULL);
	*(buf + i - 1) = 0;
	k = i;
	for (i = 0; *(buf + i) != 0; i++)
	{
		if (*(buf + i) != 32 && *(buf + i) != 10)
			break;
		else if (*(buf + i + 1) == 0)
			return (NULL);
	}
	buffer = malloc(k * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	for (i = 0; *(buf + i); i++)
		*(buffer + i) = *(buf + i);
	*(buffer + i) = 0;
	command = _strtok(buffer, 32);
	if (command == NULL)
		return (NULL);
	free(buffer);
	buffer = NULL;
	return (command);
}

/**
 * _getline_NIM - Reads the command from STDIN and tokenizes it
 *
 * Return: The tokenized command or NULL at files
 */

char **_getline_NIM(void)
{
	char buf[4096], **command_token = NULL, *auxiliar = NULL, **command = NULL;
	int i = 0;
	pid_t child_detect;

	while (read(STDIN_FILENO, buf + i++, 1))
		;

	*(buf + i) = 0;

	command_token = _strtok(buf, 10);

	for (i = 0; *(command_token + i); i++)
	{
		auxiliar = *(command_token + i);
		child_detect = fork();
		wait(NULL);

		if (child_detect == 0)
			break;
	}

	if (child_detect == 0)
		command = _strtok(auxiliar, 32);

	if (child_detect != 0)
	{
		free_dp(command_token);
		return (NULL);
	}

	return (command);
}

