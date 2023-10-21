#include "main.h"

int _strcmp(char *s1, char *s2);
void print_err(char *av, int count, char *command);
void e_error(char *av, int count, char *tmp_command);
void sh_error(void);

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
    int i;

    if (str_length(s1) != str_length(s2))
        return (-1);

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
            return (-1);
    }

    return (0);
}

/**
 * print_err - Prints a message error when a command is not found.
 * @count: A counter keeping track of the number of commands run on the shell.
 * @av: The name of the program running the shell.
 * @command: The specific command not being found.
 */
void print_err(char *av, int count, char *command)
{
    print_str(av, 1);
    print_str(": ", 1);
    print_number(count);
    print_str(": ", 1);
    print_str(command, 1);
}

/**
 * e_error - Prints exec errors.
 * @av: The name of the program running the shell.
 * @count: Keeps track of how many commands have been entered.
 * @tmp_command: The command that failed.
 */
void e_error(char *av, int count, char *tmp_command)
{
    print_err(av, count, tmp_command);
    print_str(": ", 1);
    perror("");
    exit(1);
}

/**
 * sh_error - Prints and execs a simple error.
 * Return: always void.
 */
void sh_error(void)
{
    perror("Fatal Error");
    exit(100);
}
