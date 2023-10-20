```c
#include "main.h"

/**
 * print_cd_1 - Outputs an error message when the cd argument is invalid
 *              e.g., cd -asd22
 * @vars: Pointer to vars_t structure
 * Return: void
 * Prints a message in the format shown below.
 */
void print_cd_1(vars_t *vars)
{
    print_str("-bash: cd: ", 1);
    print_str(vars->array_tokens[1], 1);
    print_str(": invalid option", 0);
    print_str("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cd_2 - Outputs an error message when the cd argument doesn't exist.
 *              e.g., cd das7d32
 * @vars: Pointer to vars_t structure
 * Return: void
 * Prints a message in the format shown below.
 */
void print_cd_2(vars_t *vars)
{
    print_str("-bash: cd: ", 1);
    print_str(vars->array_tokens[1], 1);
    print_str(": Not a directory", 0);
}
```