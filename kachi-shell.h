#ifndef SHELL_H
#define SHELL_H

/*
 *This is simple shell for kachi header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
/*
  *This is simple shell for kachi header file
 */
void display_prompt(void);
void kachi_print(const char *description);
void read_command(char *command, size_t size);
void execute_description(const char *description);

#endif 