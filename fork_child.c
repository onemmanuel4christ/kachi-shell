#include "shell.h"

/**
 * child_fork - Creates a child in  order to execute another program.
 * @vars: A structure cointaining a array of pointers and a string.
 */
void child_fork(vars_t vars)
{
	pid_t id;
	int status, check;
	struct stat buffer;
	char *tmp_command, *command;

	id = fork();
	if (id != 0)
		wait(&status);
	else
	{
		tmp_command = vars.array_tokens[0];
		command = path_finder_func(vars, vars.array_tokens[0]);
		if (command == NULL)
		{
			/* Looking for file in current directory */
			check = stat(tmp_command, &buffer);
			if (check == -1)
			{
				error_printing(vars.argv[0], vars.counter, tmp_command);
				k_print(": not found", 0);

				exit(100);
			}
			/* file exist in c or has full path */
			command = tmp_command;
		}
		vars.array_tokens[0] = command;
		if (vars.array_tokens[0] != NULL)
		{
			if (execve(vars.array_tokens[0], vars.array_tokens, vars.env) == -1)
				exec_error(vars.argv[0], vars.counter, tmp_command);
		}
	}
}

/**
 * path_finder_func - Acts as an interface for functions that will be able
 * to find the full path of a program.
 * @command: A common command such as ls, echo, pwd, etc..
 * Return: On success a string with the full path of the program.
 * @vars: structure with variables.
 * oterwise returns NULL.
 */
char *path_finder_func(vars_t vars, char *command)
{
	char *str = "PATH";
	char *const_ptr;
	char **path;
	int index, i;
	char *directory;

	index = envi_idx(vars, str);
	path = tokenized(vars, index, str);
	if (path == NULL)
		return (NULL);

	directory = search_dir_func(path, command);
	if (directory == NULL)
	{
		for (i = 0; path[i] != NULL; i++)
			free(path[i]);
		free(path);
		return (NULL);
	}
	const_ptr = build_path_func(directory, command);
	if (const_ptr == NULL)
	{
		for (i = 0; path[i] != NULL; i++)
			free(path[i]);
		free(path);
		return (NULL);
	}
	for (i = 0; path[i] != NULL; i++)
		free(path[i]);
	free(path);
	return (const_ptr);
}

/**
 * envi_idx - Finds the index of an environmental variable.
 * @vars: structure with variables will be used
 * @str: Environmental variable that needs to be found.
 * Return: Upon success returns the inde of the environmental variale
 * otherwise returns -1.
 */
int envi_idx(vars_t vars, char *str)
{
	int i, len, j;

	len = _strlen(str);
	for (i = 0; vars.env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (vars.env[i][j] != str[j])
				break;
		}
		if (j == len && vars.env[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * tokenized - Separates a string of path as an array of
 * strings containing the path directories.
 * @vars: structure with variables will be used
 * @index: index of the path in the environment variables.
 * @str: string to separate and tokenize
 * Return: On success a NLL terminated array of string.
 * otherwise returns NULL.
 */
char **tokenized(vars_t vars, int index, char *str)
{
	char *env_var;
	int token_count = 0, len;
	char **path;
	const char *delim = ":\n";

	len = _strlen(str);

	env_var = vars.env[index] + (len + 1);
	path = token_stru_func(env_var, delim, token_count);
	if (path == NULL)
		return (NULL);

	return (path);
}

/**
 * search_dir_func - Looks through directories stored in path
 * for a specific file aka command.
 * @path: A pointer to array of strings containings de paths
 * contained in the PATH environment variable.
 * @command: Represents a command. i.e. ls, /bin/ls, pwd, etc.
 *
 * Return: On success a string with the directory containing the
 * command file. Otherwise NULL.
 */
char *search_dir_func(char **path, char *command)
{
	int i, s;
	char *c, *buffer;
	size_t size;
	struct stat stat_buffer;

	buffer = NULL;
	size = 0;
	c = getc(buffer, size);
	if (c == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (i = 0; path[i] != NULL; i++)
	{
		s = chdir(path[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(command, &stat_buffer);
		if (s == 0)
		{
			chdir(c);
			free(c);
			return (path[i]);
		}
	}
	chdir(c);
	free(c);
	return (NULL);
}
