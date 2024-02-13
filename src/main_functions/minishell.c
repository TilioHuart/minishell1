/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macros.h"
#include "display_functions.h"
#include "my.h"
#include "recup_function.h"
#include "minishell.h"
#include "builtin.h"
#include "washing_machine.h"

static int call_function(char **arr, builtin_t *builtin)
{
    display_prompt();
    arr = recup_function();
    if (arr == NULL || arr[0] == NULL) {
        washing_machine(builtin);
        return -1;
    }
    if (my_strcmp(arr[0], "exit") == 0) {
        washing_array(arr);
        washing_machine(builtin);
        return 1;
    }
    loop_builtin(builtin, arr);
    washing_array(arr);
    return SUCCESS;
}

static int main_loop(void)
{
    char **arr = NULL;
    builtin_t *builtin = malloc(sizeof(builtin_t) * 5);
    int loop = 0;

    init_builtin(builtin);
    while (1) {
        loop = call_function(arr, builtin);
        if (loop == -1)
            return -1;
        if (loop == 1)
            break;
    }
    return SUCCESS;
}

int minishell(char **env)
{
    if (main_loop() == -1)
        return FAILURE_EPITECH;
    return SUCCESS;
}
