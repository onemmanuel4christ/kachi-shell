#include "kachi-shell.h"

void execute_description(const char *description) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
       
        execlp(description, description, (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
       
        wait(NULL);
    }
}