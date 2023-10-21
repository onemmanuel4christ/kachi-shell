#include "main.h"

/**
 * tokenizer - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenizer(char *buffer, char *delimiter)
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
	while ((tokens[i] = strtok_func(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = realloc_func(tokens, &mcount);
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
 * tokenize - tokenizes a buffer with a delimiter just use for for_child
 * @line: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 * @token_count: token count, size.
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(int token_count, char *line, const char *delimiter)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = str_dup(line);
	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok_func(line_cp, delimiter);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = str_dup(token);
		token = strtok_func(NULL, delimiter);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * token_str - token interface
 * @line: line get to be tokenized
 * @delimiter: eny delimiter lie ; % " ", etc.
 * @token_count: token counter.
 * Return: tokens
 **/
char **token_str(char *line, const char *delimiter, int token_count)
{
	vars_t vars;

	token_count = token_counter(line, delimiter);
	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}
	vars.array_tokens = tokenize(token_count, line, delimiter);
	if (vars.array_tokens == NULL)
	{
		free(line);
		return (NULL);
	}

	return (vars.array_tokens);
}

/**
 * token_counter - token's count
 * @line: string.
 * @delimiter: delimiter
 * Return: token's count
 **/
int token_counter(char *line, const char *delimiter)
{
	char *str;
	char *token;
	int i;

	str = str_dup(line);
	if (str == NULL)
		return (-1);
	token = strtok_func(str, delimiter);
	for (i = 0; token != NULL; i++)
		token = strtok_func(NULL, delimiter);
	free(str);
	return (i);
}
