#ifndef SHELL_MAIN
#define SHELL_MAIN
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct history - An structure for each command readed
 * @str: string
 * @counter: number of imputs
 * @next: Next element
 */

typedef struct history
{
	char *str;
	int counter;
	struct history *next;

} history_t;

/**fixing**/
/**** Estructura con las posibles variables que vamos a usar ****/
/**
 * struct variables - variables
 * @array_tokens: array of tokens(arguments)
  * @buffer: buffer of command
  * @status: to handle exit status
  * @argv: gets arguments at opening of shell
  * @counter: counts commands entered
  * @env: has enviroment
  * @commands: have commands.
  * @history: structure
  * @invert: structure
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	history_t *history;
	history_t *invert;

} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

char *str_dup(char *strtodup);
int str_compare(char *strcmp1, char *strcmp2);
char *str_cat(char *strc1, char *strc2);
ssize_t _puts(char *str);
int str_length(char *str);
void print_str(char *str, int new_line);
int _write_char(char c);
int print_number(int n);

void (*is_builtins(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);
void new_help(vars_t *vars);
void new_cd(vars_t *vars);

char **tokenizer(char *buffer, char *delimiter);
unsigned int is_match(char c, const char *str);
char **realloc_func(char **ptr, size_t *size);
char *strtok_func(char *str, const char *delim);

char **tokenize(int token_count, char *line, const char *delimiter);
char **token_str(char *line, const char *delimiter, int token_count);
int token_counter(char *line, const char *delimiter);

void check_for_path(vars_t *vars);

void _puts_error(char *str);
void prints_error_msg(vars_t *vars, char *msg);
char *conv_int_func(unsigned int count);

int _atoi(char *str);


char **make_env_fun(char **env);
void free_env(char **env);

void n_exit(vars_t *vars);
void my_h_func(vars_t *vars);
void my_h_dir(vars_t *vars);
void my_h_env(vars_t *vars);
void n_h_history(vars_t *vars);
void h_unalias(vars_t *vars);
void h_unset(vars_t *vars);
void h_unsetenv(vars_t *vars);
void h_setenv(vars_t *vars);
void h_alias(vars_t *vars);
void h_ease(vars_t *vars);

void new_setenv(vars_t *vars);
void add_key(vars_t *vars);
char *add_value(char *key, char *value);
char **find_key(char **env, char *key);
void setenv_cd(char **args, vars_t *vars);
void chdir_to_env(vars_t *vars, char *str);

void fork_func(vars_t vars);
char *sh_path(vars_t vars, char *command);
int path_idx(vars_t vars, char *str);
char **token_path(vars_t vars, int index, char *str);
char *s_directories(char **path_tokens, char *command);
char *b_path(char *directory, char *command);

void print_err(char *av, int count, char *command);
void e_error(char *av, int count, char *tmp_command);
void sh_error(void);
void show_dir(vars_t *vars);
void show_dir2(vars_t *vars);

void sh_history(vars_t *vars);
void *add_nodeint(history_t **head, char *str);
void free_hist_func(history_t *head);
ssize_t _puts3(char *str);
void custom_print(char *str);

void sh_e_o_file(char *buffer);
unsigned int sig_flag;
#endif /* SHELL_MAIN */
