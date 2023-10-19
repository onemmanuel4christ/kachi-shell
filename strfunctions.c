#include "shell.h"


/***** RETURNS A POINTER TO A NEW STRING ******/
/**
 * str_dup - returns pointer to new mem alloc space which contains copy
 * @str_t_dup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *str_dup(char *str_t_dup)
{
	char *copy;

		int len, i;

	if (str_t_dup == 0)
		return (0);

	for (len = 0; str_t_dup[len]; len++);
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = str_t_dup[i];

return (copy);
}


/****** COMPARES TWO STRINGS *****/
/**
 * str_comp - compares two strings
 * @str_t_comp: first string, of two, to be compared in length
 * @str_t_comp_2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int str_comp(char *str_t_comp, char *str_t_comp_2)
{
	int i;

	i = 0;
	while (str_t_comp[i] == str_t_comp_2[i])
	{
		if (str_t_comp[i] == '\0')
			return (0);
		i++;
	}
	return (str_t_comp[i] - str_t_comp_2[i]);
}


/***** CONCATENATES TWO STRINGS *****/
/**
 * str_cat - concatenates two strings
 * @str_t_cat1: first string
 * @str_t_cat2: second string
 * Return: pointer
 */
char *str_cat(char *str_t_cat1, char *str_t_cat2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (str_t_cat1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; str_t_cat1[len1]; len1++)
			;
	}
	if (str_t_cat2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; str_t_cat2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 1;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstring[i] = str_t_cat1[i];
	for (j = 0; j < len2; j++)
		newstring[i + j] = str_t_cat2[j];
	newstring[len1 + len2] = '\0';
	return (newstring);
}


/*** WRITES STRING TO STDOUT ***/
/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t i, len;

	for (i = 0; str[i]; i++)
		;
	len = write(1, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/*** MEASURE THE LENGHT OF A STRING ***/
/**
 * str_len - Calculates the lenght of a string.
 * @str: String that needs length to be found.
 * Return: Upon success returns the length of a string. otherwise 0.
 */
int str_len(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
