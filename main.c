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
	char *buf, *path, *argv[2];
	size_t bufsize = 1024;
	int input_len;
	(void)envp, (void)av;

	buf = malloc(bufsize * sizeof(char));
	path = malloc(2 * bufsize * sizeof(char));
	if (ac < 1)
		return (-1);
	/*prompt user for command then print out the command on stdout*/
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
			/*buf1 = strtok(buf, " ")*/
			/*will add later*/
			/*path = _strcat("/bin/", buf1);
			while (buf2 != NULL)
			{
				buf2 = strtok(buf, "");
				*argv = path;
			*(argv + 1) = NULL;
			execve(argv[0], argv, NULL);*/
			write(1, "\n", 1);
		}
	}
	free(buf);
	return (0);
}
