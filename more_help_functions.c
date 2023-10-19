#include "shell.h"
/**
 * new_help_history - help builtin command history
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_history(vars_t *vars)
{
	char *file;
	int file_d, r;
	char *s;

	if (str_comp(vars->array_tokens[1], "history") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/history";
		file_d = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(file_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		file_d = close(file_d);
	}
	else
		new_help_unalias(vars);
}
/**
 * new_help_unalias - help builtin command unalias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unalias(vars_t *vars)
{
	char *file;
	int file_d, r;
	char *s;

	if (str_comp(vars->array_tokens[1], "unalias") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unalias";
		file_d = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(file_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		file_d = close(file_d);
	}
	else
		new_help_unset(vars);
}
/**
 * new_help_unset - help builtin command unset
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unset(vars_t *vars)
{
	char *file;
	int file_d, r;
	char *s;

	if (str_comp(vars->array_tokens[1], "unset") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unset";
		file_d = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(file_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		file_d = close(file_d);
	}
	else
		new_help_unsetenv(vars);
}
/**
 * new_help_unsetenv - help builtin command unsetenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unsetenv(vars_t *vars)
{
	char *file;
	int file_d, r;
	char *s;

	if (str_comp(vars->array_tokens[1], "unsetenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unsetenv";
		file_d = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(file_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		file_d = close(file_d);
	}
	else
		new_help_setenv(vars);
}
/**
 * new_help_setenv - help builtin command setenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_setenv(vars_t *vars)
{
	char *file;
	int file_d, r;
	char *s;

	if (str_comp(vars->array_tokens[1], "setenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/setenv";
		file_d = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(file_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		file_d = close(file_d);
	}
	else
		new_help_alias(vars);
}
