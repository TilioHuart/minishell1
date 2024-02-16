/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.c
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macros.h"
#include "display_functions.h"
#include "my.h"
#include "recup_function.h"
#include "minishell.h"
#include "builtin.h"
#include "washing_machine.h"
#include "environment.h"
#include "use_functions.h"

static
int call_function(char **arr, builtin_t *builtin, environment_t *environment)
{
    display_prompt();
    arr = recup_function();
    if (arr == NULL || arr[0] == NULL) {
        washing_machine(builtin, environment);
        return -1;
    }
    if (my_strcmp(arr[0], "exit") == 0) {
        washing_array(arr);
        washing_machine(builtin, environment);
        return 1;
    }
    if (loop_builtin(builtin, arr, environment) == 0)
        use_function(arr, environment);
    washing_array(arr);
    return SUCCESS;
}

static int main_loop(environment_t *environment)
{
    char **arr = NULL;
    builtin_t *builtin = malloc(sizeof(builtin_t) * 5);
    int loop = 0;

    init_builtin(builtin);
    while (1) {
        loop = call_function(arr, builtin, environment);
        if (loop == -1)
            return -1;
        if (loop == 1)
            break;
    }
    return SUCCESS;
}

int minishell(char **env)
{
    environment_t *environment = NULL;

    environment = copy_env(env);
    if (main_loop(environment) == -1)
        return FAILURE_EPITECH;
    return SUCCESS;
}
