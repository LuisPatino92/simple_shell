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
	write(STDIN_FILENO, "\n", 1);
	show_prompt();
}

/**
 * signal_handler - Funtion to handling signal
 *
 * @signal: Posix of entry signal
 */

void show_error(char **command, int loop)
{

	

}
