#include "shell.h"

/**
 * main - creates a prompt reading input, sparses it, executes and waits
 * for another command unless told to exit
 * @ac: number of arguments
 * @av: array of arguments
 * @env: environment variable
 * Return: 0 (success)
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int count = 0, status = 0;
	(void) av;
	signal(SIGINT, handle_signal);
	while (1)
	{	/*printing prompt*/
		prompt_user();
		/*read input and return string*/
		line = read_input();
		/*separates string to get command and arguments*/
		args = sparse_str(line, env);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			count += 1;
			path = search_path(env); /*search for PATH in env var*/
			status = _stat(args, path);
			child_process(av, args, env, status, count);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (0);
}
