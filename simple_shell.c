#include "main.h"

/**
 * signal_handler_func - handles ^C signal interupt
 * @unused: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void signal_handler_func(int unused)
{
	(void)unused;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}
/**
 * main - main function for the shell
 * @argc: number of arguments passed to main, unused
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int i;
	unsigned int is_pipe = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = make_env_fun(environment);

	signal(SIGINT, signal_handler_func);

	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts("Kachi_shell$ ");
	sig_flag = 0;

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;
		vars.commands = tokenizer(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.array_tokens = tokenizer(vars.commands[i], " \t\r\n\a");
			if (vars.array_tokens && vars.array_tokens[0])
				if (is_builtins(&vars) == NULL)
				{
					fork_func(vars);
				}
			free(vars.array_tokens);
		}
		free(vars.buffer);
		free(vars.commands);
		if (is_pipe == 0)
			_puts("Kachi_shell$ ");
		vars.buffer = NULL;
	}
	free_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
