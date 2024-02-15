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
int adding_elem_with_setenv(environment_t *environment, char *part_of_env)
{
    environment_t *head = environment;
    environment_t *tmp = malloc(sizeof(environment_t));

    if (tmp == NULL || part_of_env == NULL)
        return FAILURE;
    while (environment->next != NULL)
        environment = environment->next;
    environment->next = tmp;
    tmp->part_of_env = my_strdup(part_of_env);
    tmp->next = NULL;
    environment = head;
    return SUCCESS;
}

static int concatenate_str(char **arr, char *str, size_t len1, size_t len2)
{
    size_t i = 0;
    size_t a = 0;

    if (arr == NULL || str == NULL)
        return FAILURE;
    for (; arr[1][i] != '\0'; i++)
        str[i] = arr[1][i];
    str[i] = '=';
    i += 1;
    if (arr[2] == NULL) {
        str[i] = '\0';
        return SUCCESS;
    }
    for (; arr[2][a] != '\0'; a += 1) {
        str[i] = arr[2][a];
        i++;
    }
    str[i + 1] = '\0';
    return SUCCESS;
}

int setenv_function(char **arr, UNUSED environment_t *environment)
{
    char *str = NULL;
    size_t len1 = 0;
    size_t len2 = 0;

    if (arr == NULL)
        return FAILURE;
    if (arr[1] == NULL)
        return SUCCESS;
    str = malloc(sizeof(char) * (len1 + len2 + 2));
    if (str == NULL)
        return FAILURE;
    concatenate_str(arr, str, len1, len2);
    adding_elem_with_setenv(environment, str);
    return SUCCESS;
}
