#include "k_shell.h"
/**
 * helper2 - help builtin command history
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void helper2(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (str_compr(vars->array_tokens[1], "history") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/history";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			p_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				p_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		more_help_func(vars);
}
/**
 * more_help_func - help builtin command unalias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void more_help_func(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (str_compr(vars->array_tokens[1], "unalias") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unalias";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			p_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				p_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
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
	int fd, r;
	char *s;

	if (str_compr(vars->array_tokens[1], "unset") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unset";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			p_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				p_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
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
	int fd, r;
	char *s;

	if (str_compr(vars->array_tokens[1], "unsetenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unsetenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			p_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				p_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
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
	int fd, r;
	char *s;

	if (str_compr(vars->array_tokens[1], "setenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/setenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			p_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_message("\n");
			if (r == -1)
			{
				p_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_alias(vars);
}
