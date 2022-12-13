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
	char *buf, *token, *argv[10];
	size_t bufsize = 0;
	int input_len, i = 1;
	(void)envp, (void)av;

	if (ac < 1)
		return (-1);
	while (1)
	{
		prompt_user();
		input_len = getline(&buf, &bufsize, stdin);
		if (input_len == -1)
			exit (1);
		else
		{
			if (buf[input_len - 1] == '\n')
				buf[input_len - 1] = '\0';
			token = malloc(20);
			token = strtok(buf, " ");
			argv[0] = malloc(20);
			argv[0] = _strcat("/bin/", token);
			while (token != NULL)
			{
				token = strtok(buf, " ");
				argv[i] = malloc(20);
				argv[i] = token;
				i++;
			}
			argv[i + 1] = malloc(20);
			argv[i + 1] = NULL;
			execve(argv[0], argv, NULL);
			write(1, "\n", 1);
		}
	}
	free(buf);
	return (0);
}
