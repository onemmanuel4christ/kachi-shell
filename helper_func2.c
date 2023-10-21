#include "main.h"
/**
 * n_h_history - help builtin command history
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void n_h_history(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "history") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/history";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			custom_print("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		h_unalias(vars);
}
/**
 * h_unalias - help builtin command unalias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void h_unalias(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unalias") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unalias";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			custom_print("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		h_unset(vars);
}
/**
 * h_unset - help builtin command unset
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void h_unset(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unset") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unset";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			custom_print("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		h_unsetenv(vars);
}
/**
 * h_unsetenv - help builtin command unsetenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void h_unsetenv(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unsetenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unsetenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			custom_print("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		h_setenv(vars);
}
/**
 * h_setenv - help builtin command setenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void h_setenv(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "setenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/setenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			custom_print("\n");
			if (r == -1)
			{
				_puts_error("Fatal Error");
			return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		h_alias(vars);
}
