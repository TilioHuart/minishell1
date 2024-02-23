/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv_function.c
*/

#include "my.h"
#include "my_macros.h"
#include "environment.h"
#include <unistd.h>
#include <stdlib.h>

static
void loop_in_env(char **arr, environment_t **environment, size_t const *i)
{
    environment_t *head = *environment;
    environment_t *tmp = NULL;

    while ((*environment)->next->next != NULL) {
        if (my_strcmp((*environment)->next->key, arr[*i]) == 0)
            break;
        (*environment) = (*environment)->next;
    }
    if (my_strcmp((*environment)->next->key, arr[*i]) != 0 &&
        (*environment)->next->next == NULL)
        return;
    tmp = (*environment)->next->next;
    if ((*environment)->next->key != NULL)
        free((*environment)->next->key);
    if ((*environment)->next->value != NULL)
        free((*environment)->next->value);
    if ((*environment)->next != NULL)
        free((*environment)->next);
    (*environment)->next = tmp;
    *environment = head;
}

int unsetenv_function(UNUSED char **arr, UNUSED environment_t *environment)
{
    if (environment == NULL || arr == NULL || arr[0] == NULL)
        return FAILURE;
    for (size_t i = 1; arr[i] != NULL; i += 1) {
        loop_in_env(arr, &environment, &i);
    }
    return SUCCESS;
}
