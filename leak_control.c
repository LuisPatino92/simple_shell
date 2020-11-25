#include "shell.h"

/**
 * free_dp - Frees a Double Pointer
 *
 * @to_free: Double pointer to be freed
 */

void free_dp(char **to_free)
{
	int i;

	for (i = 0; *(to_free + i); i++)
		free(*(to_free + i));

	free(*(to_free + i));
	free(to_free);
}

/**
 * signal_handler - Funtion to handling signal
 *
 * @signal: Posix of entry signal
 */

void signal_handler(__attribute__((unused)) int signal)
{
	write(STDERR_FILENO, "\n", 1);
	show_prompt();
}

/**
 * show_error - shows and error and exits with satus 127
 *
 * @command: Tokenized command line
 * @loop: Counter of how many loops there are since started
 */

void show_error(char **command, int loop)
{
	error_msg(command, loop);
	free_dp(command);
	exit(127);
}

/**
 * error_msg - Makes and shows the error msg wit appropiate format
 *
 * @command: Tokenized command line
 * @loop: Counter of how many loops there are since started
 */

void error_msg(char **command, int loop)
{
	char aux_buf[2048], *num = NULL, *aux_error = "not found\n", *exe_name = NULL;
	int i = 0, j = 0;

	exe_name = get_exe_name();

	for (i = 0; *(exe_name + i); i++)
		aux_buf[i] =  *(exe_name + i);

	aux_buf[i++] = 58;
	aux_buf[i++] = 32;

	num = int_to_string(loop);

	for (j = 0; *(num + j); i++, j++)
		aux_buf[i] = *(num + j);

	aux_buf[i++] = 58;
	aux_buf[i++] = 32;

	for (j = 0; *(*(command + 0) + j); j++, i++)
		aux_buf[i] = *(*(command + 0) + j);

	aux_buf[i++] = 58;
	aux_buf[i++] = 32;

	for (j = 0; *(aux_error + j); j++, i++)
		aux_buf[i] = *(aux_error + j);

	aux_buf[i] = 0;

	write(STDERR_FILENO, aux_buf, _strlen(aux_buf));
	free(num);
}

/**
 * get_exe_name - Takes the name of the executable from the enviroment
 *
 * Return: The name of the executable
 */

char *get_exe_name(void)
{
	char *exe_name;
	int i;

	for (i = 0; *(environ + i); i++)
		if (_strncmp(*(environ + i), "_=", 2))
			exe_name = *(environ + i) + 2;

	return (exe_name);
}
