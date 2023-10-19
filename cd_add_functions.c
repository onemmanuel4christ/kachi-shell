#include "shell.h"

/**
 * print_cd_1 - Prints error when cd argument in invalid
 *              i.e. cd -asd22
 * @vars: vars parameter to include
 * Return: Always return void and print a messaje as shown below.
 */
void print_cd_1(vars_t *vars)
{
	k_print("-bash: cd: ", 1);
	k_print(vars->array_tokens[1], 1);
	k_print(": invalid option", 0);
	k_print("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cd_2 - Prints error message when cd argument doesn'n exist.
 *              i.e. cd das7d32
 * @vars: vars parameter to include
 * Return: Always return void and print a messaje as shown below.
 */
void print_cd_2(vars_t *vars)
{
	k_print("-bash: cd: ", 1);
	k_print(vars->array_tokens[1], 1);
	k_print(": Not a directory", 0);
}
