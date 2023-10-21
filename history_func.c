#include "main.h"

/**
 * *add_nodeint - Add node in the beginning
 * @head: The pointer of the history list.
 * @str: The string received.
 *
 * Return: On success 1
 */

void *add_nodeint(history_t **head, char *str)
{

	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_hist_func(*head);
	}

	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free_hist_func(*head);
	}

	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	copy = *head;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
}

/**
 * free_hist_func - free pointers related with malloc
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void free_hist_func(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->str);

		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * sh_history - Print the list of a single list
 * @vars: structure with variables.
 * Return: The number of elements in the list
 */

void sh_history(vars_t *vars)
{
	history_t *tmp = vars->history;
	history_t *tmp2 = vars->history;
	int i = 0, z = 1;
	unsigned int counter = 0;
	char *count;

	if (vars->array_tokens[1] != NULL)
	{
		prints_error_msg(vars, ": Command not found: ");
		custom_print(vars->array_tokens[1]);
		custom_print("\n");
		return;
	}
	else
	{
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		while (z < i)
		{
			counter++;
			count = conv_int_func(counter);
			custom_print(count);
			custom_print("  ");
			_puts3(tmp2->str);
			tmp2 = tmp2->next;
			z++;
			free(count);
		}
		tmp2 = tmp2->next;
		vars->invert = tmp2;
		free_hist_func(tmp);
		free_hist_func(tmp2);
		return;
	}
}
/*** WRITES STRING TO STDOUT ***/
/**
 * _puts3 - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts3(char *str)
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
/**
 *custom_print - print a string to standart output
 * @str: string to print.
 * Return: void
 */
void custom_print(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}
