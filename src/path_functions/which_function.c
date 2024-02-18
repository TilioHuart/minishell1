/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** which_function.c
*/

#include "environment.h"
#include "my_macros.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int loop_in_path(char **arr, environment_t *environment)
{
    for (size_t i = 0; environment->value[i] != '\0'; i++) {
        if (environment->value[i] == ':')
            environment->value[i] = ' ';
    }
    printf("path = %s\n", environment->value);
    return SUCCESS;
}

int which_function(char **arr, environment_t *environment)
{
    environment_t *head = environment;

    if (arr == NULL)
        return FAILURE;
    while (environment->next != NULL) {
        environment = environment->next;
        if (my_strcmp(environment->key, "PATH") == 0)
            break;
    }
    loop_in_path(arr, environment);
    environment = head;
    return SUCCESS;
}
