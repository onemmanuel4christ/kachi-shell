#include "k_shell.h"

/**
 * sig_handler - handles ^C signal interupt
 * @unused: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void sig_handler(int unused)
{
	(void)unused;
	if (sig_flag == 0)
		my_print_func("\n$ ");
	else
		my_print_func("\n");
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
	vars.env = new_env(environment);

	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		my_print_func("$ ");
	sig_flag = 0;

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;
		vars.commands = tokenizer(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.array_tokens = tokenizer(vars.commands[i], " \t\r\n\a");
			if (vars.array_tokens && vars.array_tokens[0])
				if (check_for_my_shell_func(&vars) == NULL)
				{
					fork_child(vars);
				}
			free(vars.array_tokens);
		}
		free(vars.buffer);
		free(vars.commands);
		if (is_pipe == 0)
			my_print_func("Kachi_shell$ ");
		vars.buffer = NULL;
	}
	free_env_func(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
