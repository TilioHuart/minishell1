/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** exit.c
*/

#include "environment.h"
#include "minishell.h"
#include "my_macros.h"
#include <stdio.h>
#include <stdlib.h>

static void free_environment(environment_t **environment)
{
    environment_t *tmp = NULL;

    if (*environment != NULL)
        while (*environment != NULL) {
            tmp = (*environment)->next;
            free((*environment)->key);
            free((*environment)->value);
            free(*environment);
            (*environment) = tmp;
        }
}

int exit_function(UNUSED char **arr,
    UNUSED environment_t *environment, loop_t *loop)
{
    free_environment(&environment);
    loop->stop = 1;
    return SUCCESS;
}
