#include "k_shell.h"

/**
 * new_env - make the shell environment from the environment.
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **new_env(char **env)
{
char **my_env = NULL;

size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	my_env = malloc(sizeof(char *) * (i + 1));
	if (my_env == NULL)
	{
		err_print_func("Error occured");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		my_env[i] = str_dup(env[i]);
	my_env[i] = NULL;
	return (my_env);
}

/**
 * free_env_func - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_env_func(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}

/**
 * change_dir - go to the directory that points the adress of the
 *                the environment variable.
 * @vars: vars variable of struct vars_t
 * @str: name of env var to find.
 * Return: always return void.
 */
void change_dir(vars_t *vars, char *str)
{
	int len, index;

	len = str_length(str);
	index = env_idx_fuct(*vars, str);
	c_directory((vars->env[index]) + len + 1);
}
