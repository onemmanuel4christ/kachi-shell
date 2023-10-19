#include "shell.h"
 #include <linux/limits.h>

/**
 * tokenize_func - tokenizes a buffer with a delmt
 * @buffer: buffer to tokenize
 * @delmt: delmt to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize_func(char *buffer, char *delmt)
{
	char **tokens = NULL;
	size_t i = 0, malloc_tracker = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * malloc_tracker);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = t_tok(buffer, delmt)) != NULL)
	{
		i++;
		if (i == malloc_tracker)
		{
			tokens = _realloc(tokens, &malloc_tracker);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}

/**
 * tokenize - tokenizes a buffer with a delmt just use for for_child
 * @line: buffer to tokenize
 * @delmt: delmt to tokenize along
 * @token_tracker: token count, size.
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(int token_tracker, char *line, const char *delmt)
{
	int i;
	char **buffer;
	char *token;
	char *copy;

	copy = str_dup(line);
	buffer = malloc(sizeof(char *) * (token_tracker + 1));
	if (buffer == NULL)
		return (NULL);
	token = t_tok(copy, delmt);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = str_dup(token);
		token = t_tok(NULL, delmt);
	}
	buffer[i] = NULL;
	free(copy);
	return (buffer);
}

/**
 * token_stru_func - token interface
 * @line: line get to be tokenized
 * @delmt: eny delmt lie ; % " ", etc.
 * @token_tracker: token counter.
 * Return: tokens
 **/
char **token_stru_func(char *line, const char *delmt, int token_tracker)
{
	vars_t vars;

	token_tracker = counter(line, delmt);
	if (token_tracker == -1)
	{
		free(line);
		return (NULL);
	}
	vars.array_tokens = tokenize(token_tracker, line, delmt);
	if (vars.array_tokens == NULL)
	{
		free(line);
		return (NULL);
	}

	return (vars.array_tokens);
}

/**
 * counter - token's count
 * @line: string.
 * @delmt: delmt
 * Return: token's count
 **/
int counter(char *line, const char *delmt)
{
	char *str;
	char *token;
	int i;

	str = str_dup(line);
	if (str == NULL)
		return (-1);
	token = t_tok(str, delmt);
	for (i = 0; token != NULL; i++)
		token = t_tok(NULL, delmt);
	free(str);
	return (i);
}
