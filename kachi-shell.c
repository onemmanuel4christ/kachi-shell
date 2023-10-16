#include "kachi-shell.h"
/*
 *shell basic
 */

int main(void) {
    char command[120];
    while (true) {
        display_prompt();
        read_command(command, sizeof(command));
        execute_description(command);
    }





    

    return 0;
}