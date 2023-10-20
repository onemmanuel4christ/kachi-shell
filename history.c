#include "k_shell.h"

/**
 * *add_func - Add node in the beginning
 * @head: The pointer of the history list.
 * @str: The string received.
 *
 * Return: On success 1
 */

void *add_func(history_t **head, char *str)
{

	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
	}

	new->str = str_dup(str);
	if (new->str == NULL)
	{
		free_listint(*head);
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
 * free_listint - free pointers related with malloc
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void free_listint(history_t *head)
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
 * new_history - Print the list of a single list
 * @vars: structure with variables.
 * Return: The number of elements in the list
 */

void new_history(vars_t *vars)
{
	history_t *tmp = vars->history;
	history_t *tmp2 = vars->history;
	int i = 0, z = 1;
	unsigned int counter = 0;
	char *count;

	if (vars->array_tokens[1] != NULL)
	{
		prints_error_msg(vars, ": Command not found: ");
		print_message(vars->array_tokens[1]);
		print_message("\n");
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
			count = integer_converter(counter);
			print_message(count);
			print_message("  ");
			my_print_func3(tmp2->str);
			tmp2 = tmp2->next;
			z++;
			free(count);
		}
		tmp2 = tmp2->next;
		vars->invert = tmp2;
		free_listint(tmp);
		free_listint(tmp2);
		return;
	}
}
/*** WRITES STRING TO STDOUT ***/
/**
 * my_print_func3 - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t my_print_func3(char *str)
{
	ssize_t i, len;

	for (i = 0; str[i]; i++)
		;

	len = write(1, str, i);
	if (len != i)
	{
		err_print_func("Fatal Error");
		return (-1);
	}
	return (len);
}
/**
 *print_message - print a string to standart output
 * @str: string to print.
 * Return: void
 */
void print_message(char *str)
{
	long num, len;

	num = str_length(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		err_print_func("fatal error");
		exit(1);
	}
}
