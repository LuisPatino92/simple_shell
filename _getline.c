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
