#include "shell.h"

/**
 * handle_signal - prints new line and prompt when CTRL + C is passed as input
 * @signal: name of signal
 */
void handle_signal(int signal)
{
	char *prompt = {"\n(ash)$ "}; /*print prompt on newline*/
	(void) signal;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	keepRunning = 0;
	fflush(stdout);
}
