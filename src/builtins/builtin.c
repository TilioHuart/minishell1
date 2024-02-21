/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** bultin.c
*/

#include "minishell.h"
#include "my_macros.h"
#include "my.h"
#include "builtin.h"
#include "environment.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int init_builtin(builtin_t *builtin)
{
    builtin[0].function = my_strdup("cd");
    builtin[0].pftc = &cd_function;
    builtin[1].function = my_strdup("env");
    builtin[1].pftc = &env_function;
    builtin[2].function = my_strdup("unsetenv");
    builtin[2].pftc = &unsetenv_function;
    builtin[3].function = my_strdup("setenv");
    builtin[3].pftc = &setenv_function;
    builtin[4].function = my_strdup("exit");
    builtin[4].pftc = &exit_function;
    builtin[5].function = NULL;
    builtin[5].pftc = NULL;
    return SUCCESS;
}

static
int find_builtin(builtin_t *builtin, char **arr,
    environment_t *environment, loop_t *loop)
{
    int count = 0;

    for (size_t i = 0; builtin[i].function != NULL; i += 1) {
        if (my_strcmp(builtin[i].function, arr[0]) == 0) {
            builtin[i].pftc(arr, environment, loop);
            count = 1;
        }
    }
    return count;
}

int loop_builtin(builtin_t *builtin, char **arr,
    environment_t *environment, loop_t *loop)
{
    if (builtin == NULL || arr == NULL || arr[0] == NULL)
        return FAILURE;
    if (find_builtin(builtin, arr, environment, loop) == 1)
        return 1;
    return SUCCESS;
}
