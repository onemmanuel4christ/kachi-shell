#include "k_shell.h"

/**
 * str_comp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int str_comp(char *s1, char *s2)
{
	int i;

	if (str_length(s1) != str_length(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * print_err - Prints a message error when a comand is not found.
 * @count: A counter keeping track of the number of commands run on the shell.
 * @av: The name of the program running the shell.
 * @command: The specific command not being found.
 */
void print_err(char *av, int count, char *command)
{
	kachi_print(av, 1);
	kachi_print(": ", 1);
	print_number(count);
	kachi_print(": ", 1);
	kachi_print(command, 1);
}

/**
 * er_func - Prints exec errors.
 * @av: The name of the program running the shell.
 * @count: Keeps track of how many commands have been entered.
 * @tmp_command: The command that filed.
 */

void er_func(char *av, int count, char *tmp_command)
{
	print_err(av, count, tmp_command);
	kachi_print(": ", 1);
	err_print_func("");
	exit(1);
}

/**
 * err_message - Prints and exec simple error.
 * Return: always void.
 */
void err_message(void)
{
	err_print_func("Fatal Error");
	exit(100);
}
