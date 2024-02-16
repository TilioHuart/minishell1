/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_function.c
*/

#include "my_macros.h"
#include "my.h"
#include "environment.h"
#include <unistd.h>

int env_function(UNUSED char **arr, environment_t *environment)
{
    while (environment != NULL) {
        my_putstr(environment->key);
        write(1, "=", 1);
        my_putstr(environment->value);
        write(1, "\n", 1);
        environment = environment->next;
    }
    return SUCCESS;
}
