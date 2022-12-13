#include "shell.h"
/**
 * main - control logic for simple_shell operation
 * @ac: argument count
 * @av: argument vector
 * @envp: environment vector
 * Return: 0
 */
int main(int ac, char **av, char *envp[])

{
	char *buf;
	size_t bufsize = 1024;
	int input_len;
	(void)envp, (void)av;

	buf = malloc(bufsize * sizeof(char));
	if (ac < 1)
		return (-1);
	/*prompt user for command then print out the command on stdout*/
	prompt_user();
	input_len = getline(&buf, &bufsize, stdin);
	if (input_len == -1)
		exit (1);
	else
	{
		if (buf[input_len - 1] == '\n')
			buf[input_len - 1] = '\0';
		write(1, buf, bufsize);
		write(1, "\n", 1);
	}
	free(buf);
	return (0);
}
