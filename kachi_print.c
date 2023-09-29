#include "main.h"

void kachi_print(const char *description) {
    write(STDOUT_FILENO, description, strlen(description));
}