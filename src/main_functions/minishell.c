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
#include <sys/stat.h>
#include "my_macros.h"
#include "display_functions.h"
#include "my.h"
#include "recup_function.h"
#include "minishell.h"
#include "builtin.h"
#include "washing_machine.h"
#include "environment.h"
#include "use_functions.h"

int if_tty(void)
{
    struct stat tty = { 0 };

    fstat(0, &tty);
    if (S_ISFIFO(tty.st_mode))
        return SUCCESS;
    return FAILURE;
}

static
int call_function(char **arr, builtin_t *builtin,
    environment_t *environment, loop_t *main_loop_struct)
{
    if (if_tty() == FAILURE)
        display_prompt();
    arr = recup_function(main_loop_struct);
    if (arr == NULL) {
        washing_machine(builtin, &environment);
        return -1;
    }
    if (arr[0] == NULL) {
        return SUCCESS;
    }
    if (my_strcmp(arr[0], "exit") == 0) {
        washing_array(&arr);
        washing_machine(builtin, &environment);
        main_loop_struct->stop = 1;
        return 1;
    }
    if (loop_builtin(builtin, arr, environment) == 0)
        use_function(arr, environment);
    washing_array(&arr);
    return SUCCESS;
}

static int main_loop(environment_t *environment, loop_t *main_loop_struct)
{
    char **arr = NULL;
    builtin_t *builtin = malloc(sizeof(builtin_t) * 5);
    int loop = 0;

    init_builtin(builtin);
    while (main_loop_struct->stop == 0) {
        loop = call_function(arr, builtin, environment, main_loop_struct);
        if (loop == -1)
            return -1;
    }
    return SUCCESS;
}

int minishell(char **env)
{
    environment_t *environment = NULL;
    loop_t *main_loop_struct = malloc(sizeof(loop_t));

    main_loop_struct->stop = 0;
    environment = copy_env(env);
    if (main_loop(environment, main_loop_struct) == -1)
        return FAILURE_EPITECH;
    free(main_loop_struct);
    return SUCCESS;
}
