#include "shell.h"
/**
 * prompt_user - prompts user for command, "($ash)" is printed on stdout
 */
void prompt_user(void)
{
	write(1, "($ash)", 6);
}
