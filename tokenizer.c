#include "shell.h"
 #include <linux/limits.h>

/**
 * tokenizer - tokenizes a buffer with a delmt
 * @buffer: buffer to tokenize
 * @delmt: delmt to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenizer(char *buffer, char *delmt)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = new_strtok(buffer, delmt)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc(tokens, &mcount);
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
	char *line_cp;

	line_cp = str_dup(line);
	buffer = malloc(sizeof(char *) * (token_tracker + 1));
	if (buffer == NULL)
		return (NULL);
	token = new_strtok(line_cp, delmt);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = str_dup(token);
		token = new_strtok(NULL, delmt);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * token_interface - token interface
 * @line: line get to be tokenized
 * @delmt: eny delmt lie ; % " ", etc.
 * @token_tracker: token counter.
 * Return: tokens
 **/
char **token_interface(char *line, const char *delmt, int token_tracker)
{
	vars_t vars;

	token_tracker = count_token(line, delmt);
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
 * count_token - token's count
 * @line: string.
 * @delmt: delmt
 * Return: token's count
 **/
int count_token(char *line, const char *delmt)
{
	char *str;
	char *token;
	int i;

	str = str_dup(line);
	if (str == NULL)
		return (-1);
	token = new_strtok(str, delmt);
	for (i = 0; token != NULL; i++)
		token = new_strtok(NULL, delmt);
	free(str);
	return (i);
}
