/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** washing_machine.c
*/

#include "minishell.h"
#include "my_macros.h"
#include <stdio.h>
#include <stdlib.h>

void washing_array(char **arr)
{
    if (arr == NULL)
        return;
    for (size_t i = 0; arr[i] != NULL; i += 1)
        free(arr[i]);
    free(arr);
}

int washing_machine(builtin_t *builtin, environment_t *environment)
{
    environment_t *tmp = NULL;

    if (builtin == NULL)
        return SUCCESS;
    for (int i = 0; builtin[i].function != NULL; i += 1)
        free(builtin[i].function);
    free(builtin);
    if (environment != NULL)
        while (environment != NULL) {
            tmp = environment->next;
            free(environment->key);
            free(environment->value);
            free(environment);
            environment = tmp;
        }
    return SUCCESS;
}
