#include "shell.h"

/**
 * _getline - Reads the command from STDIN and tokenizes it
 *
 * Return: The tokenized command
 */

char **_getline(void)
{
	ssize_t readed;
	char buf[4096], **command = NULL, *buffer = NULL;
	int i = 0, k = 0;

	do {
		readed = read(STDIN_FILENO, buf + i, 1);
		i++;
		if (readed == 0 && i == 1 || readed == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (readed == 0)
			i--;
	} while (*(buf + i - 1) != 10);
	if (*buf == 10)
		return (NULL);
	for (k = 0; *(buf + k) != 10; k++)
		;
	*(buf + k) = 0;
	for (i = 0; *(buf + i) != 0; i++)
	{
		if (*(buf + i) != 32 && *(buf + i) != 10)
			break;
		else if (*(buf + i + 1) == 0)
			return (NULL);
	}
	buffer = malloc((k + 1) * sizeof(char));
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
