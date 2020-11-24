#include "shell.h"

/**
 * interpeter - Interprets a command
 *
 * @command: The command to be interpreted
 * @loop: Counter of how many loops since started
 */

void interpeter(char **command, int loop)
{
	char *executable;
	pid_t child_detect;

	executable = get_valid_exe(*command);
	if (executable == NULL)
	{
		child_detect = fork();
		wait(NULL);

		if (child_detect == 0)
			show_error(command, loop);
	}
	else
	{
		execute(executable, command);

	}
	free(executable);
}

/**
 * get_valid_exe - finds for a valid command to execute
 *
 * @command: The command to be interpreted
 *
 * Return: The valid path to execute, NULL if invalid
 */

char *get_valid_exe(char *command)
{
	struct stat info_file;
	char *valid_exe = NULL, **path_tok = NULL, *possible_path;
	int i;

	if (include_path(command))
	{
		if (stat(command, &info_file) == 0)
		{
			valid_exe = write_word(command, 32);
			return (valid_exe);
		}
		else
		{
			return (NULL);
		}
	}

	path_tok = path_tokenizer();

	for (i = 0; *(path_tok + i); i++)
	{
		possible_path = connect(*(path_tok + i), command);
		if (stat(possible_path, &info_file) == 0)
		{
			valid_exe = write_word(possible_path, 32);
			free(possible_path);
			free_dp(path_tok);
			return (valid_exe);
		}
		free(possible_path);
	}
	free_dp(path_tok);
	return (NULL);
}

/**
 * include_path - Checks if command is a path
 *
 * @command: The command to be checked
 *
 * Return: 1 if is a path 0 if is not a path
 */

int include_path(char *command)
{
	int i;

	for (i = 0; *(command + i); i++)
		if (*(command + i) == 47)
			return (1);
	return (0);
}

/**
 * path_tokenizer - Tokenizes the path
 *
 * Return: The path tokenized
 */

char **path_tokenizer(void)
{
	char *path_string = NULL, **path_tok = NULL;
	int i = 0;

	for (i = 0; *(environ + i); i++)
		if (_strncmp(*(environ + i), "PATH=", 5))
			path_string = *(environ + i) + 5;

	path_tok = _strtok(path_string, 58);

	return (path_tok);
}

/**
 * connect - connect two strings
 *
 * @msj1: mesagge 1
 * @msj2: mesagge 2
 *
 * Return: The joined string
 */

char *connect(char *msj1, char *msj2)
{
	char *ptr = NULL;
	int lenght_Full = 0, len1 = 0, len2 = 0, i, j;

	len1 = _strlen(msj1);
	len2 = _strlen(msj2);
	lenght_Full = len1 + len2;

	ptr = malloc(sizeof(char) * (lenght_Full + 2));

	if (!ptr)
	return (NULL);

	for (i = 0; i <= len1; i++)
	{
		if (msj1[i] == 0)
			ptr[i] = 47;
		else
		ptr[i] = msj1[i];
	}

	for (j = 0; i <= (lenght_Full + 1); i++, j++)
	{
		if (msj2[0] == '/' && j == 0)
		{
			++j;
			ptr[i] = msj2[j];
		}
		else
		{
			ptr[i] = msj2[j];
		}
	}
	return (ptr);
}
