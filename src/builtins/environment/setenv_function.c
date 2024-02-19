/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static
void assign_values_to_list(environment_t *environment,
    char *const *arr, environment_t *tmp)
{
    if (environment->next != NULL) {
        if (environment->next->key != NULL)
            free(environment->next->key);
        if (environment->next->value != NULL)
            free(environment->next->value);
        free(environment->next);
    }
    environment->next = tmp;
    tmp->key = my_strdup(arr[1]);
    tmp->value = my_strdup(arr[2]);
}

static
int adding_elem_with_setenv(environment_t *environment, char **arr)
{
    environment_t *head = environment;
    environment_t *tmp = malloc(sizeof(environment_t));
    environment_t *tmp2 = NULL;

    if (tmp == NULL || arr == NULL)
        return FAILURE;
    while (environment->next != NULL) {
        if (my_strcmp(environment->next->key, arr[1]) == 0) {
            tmp2 = environment->next->next;
            break;
        }
        environment = environment->next;
    }
    assign_values_to_list(environment, arr, tmp);
    tmp->next = tmp2;
    environment = head;
    return SUCCESS;
}

int setenv_function(char **arr, UNUSED environment_t *environment)
{
    if (arr == NULL)
        return FAILURE;
    if (arr[1] == NULL)
        return SUCCESS;
    adding_elem_with_setenv(environment, arr);
    return SUCCESS;
}
