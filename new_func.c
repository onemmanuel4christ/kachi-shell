#include "k_shell.h"
/**
 * n_cmd - Changes the current working directory .
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
 */
void n_cmd(vars_t *vars)
{
	int index;

	if (vars->array_tokens[1] == NULL)
	{
		index = env_idx_fuct(*vars, "HOME");
		c_directory((vars->env[index]) + 5);
	}
	else if (str_compr(vars->array_tokens[1], "-") == 0)
		kachi_print(vars->array_tokens[1], 0);
	else
		c_directory(vars->array_tokens[1]);
}
