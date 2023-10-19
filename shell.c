#include "shell.h"

/**
 * handle_signal_fuc - handles the signal interupt
 * @unused: unused variable list
 *
 * Return: void
 */
static void handle_signal_fuc(int unused)
{
	(void)unused;
	if (flag_signal == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}
/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int i;
	unsigned int p = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = make_enviroment(environment);

	signal(SIGINT, handle_signal_fuc);

	if (!isatty(STDIN_FILENO))
		p = 1;
	if (p == 0)
		_puts("$ ");
	flag_signal = 0;

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;
		vars.commands = tokenize_func(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.array_tokens = tokenize_func(vars.commands[i], " \t\r\n\a");
			if (vars.array_tokens && vars.array_tokens[0])
				if (check_for_builtins(&vars) == NULL)
				{
					child_fork(vars);
				}
			free(vars.array_tokens);
		}
		free(vars.buffer);
		free(vars.commands);
		if (p == 0)
			_puts("Kachi_shell$$- ");
		vars.buffer = NULL;
	}
	free_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
