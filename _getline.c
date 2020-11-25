#include "shell.h"

/**
 * _getline - Reads the command from STDIN and tokenizes it
 *
 * Return: The tokenized command
 */

char **_getline(void)
{
	ssize_t readed;
	static char buf[2048], **command = NULL, *buffer = NULL;
	int i = 0;

	do {
		readed = read(STDIN_FILENO, buf + i, 1);
		i++;
		if (readed == 0 && i == 1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(98);
		}
		if (readed == 0)
			i--;
	} while (*(buf + i - 1) != 10);

	if (*(buf) == 10)
		return (NULL);

	for (i = 0; *(buf + i) != 10; i++)
		;
	*(buf + i) = 0;

	buffer = _calloc(i + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	for (i = 0; *(buf + i); i++)
		*(buffer + i) = *(buf + i);
	*(buffer + i) = 0;

	command = _strtok(buffer, 32);
	if (command == NULL)
		return (NULL);

	free(buffer);

	return (command);
}
