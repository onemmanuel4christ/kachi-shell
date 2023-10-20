#include "k_shell.h"

/**
 * p_error - print a string to sdandart error
 * @str: string to print.
 * Return: void
 */

void p_error(char *str)
{
	long num, len;

	num = str_length(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)

	{
		err_print_func("fatal error");
		exit(100);
	}
}

/**** imprime mensage de error con ciertor parametros ****/
/**
 * prints_error_msg - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */

void prints_error_msg(vars_t *vars, char *msg)
{
	char *count;

	p_error(vars->argv[0]);
	p_error(": ");

	/*aqui croe una funcion para convertir un entero a string*/
	count = integer_converter(vars->counter);
	p_error(count);
	free(count);
	p_error(": ");
	p_error(vars->array_tokens[0]);
	if (msg)
	{
		p_error(msg);
	}
	else
		err_print_func("");
}

/**
 * integer_converter - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */

char *integer_converter(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;

	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;

	numstr = malloc(sizeof(char) * (digits + 1));

	if (numstr == NULL)
	{
		err_print_func("Fatal Error");
		exit(100);
	}

	numstr[digits] = '\0';

	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}

/**
 * _atoi - converts a string into an integer
 * @str: string to convert
 *
 * Return: the integer value, or -1 if an error occurs
 */
int _atoi(char *str)
{
	unsigned int i, digits;
	int num = 0, num_test;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] - '0';
		if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > digits)
		return (-1);
	return (num);
}
