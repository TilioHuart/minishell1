/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_function.c
*/

#include "minishell.h"
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

static int is_alphanum(char *str)
{
    if (str == NULL)
        return FAILURE;
    for (size_t i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))
                continue;
        else
            return FAILURE;
    }
    return SUCCESS;
}

int setenv_function(char **arr, UNUSED environment_t *environment,
    loop_t *loop)
{
    if (arr == NULL)
        return FAILURE;
    if (arr[1] == NULL)
        return SUCCESS;
    if (is_alphanum(arr[1]) == FAILURE) {
        write(2, "setenv", my_strlen("setenv"));
        write(1, ": Variable name must constain alphanumeric characters.\n",
            (my_strlen(": Variable name must constain") +
            my_strlen(" alphanumeric characters.\n")));
        loop->return_value = 1;
    }
    adding_elem_with_setenv(environment, arr);
    return SUCCESS;
}
