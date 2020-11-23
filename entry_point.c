#include "shell.h"

/**
 * main - Entry point to simple Command Line interpeter
 *
 * Return: Always 0 success.
 */

int main(void)
{
	signal(SIGINT, signal_handler);

	if (isatty(STDIN_FILENO))
		interactive_mode();
	else
		non_interactive_mode();
	return (0);
}
