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

int env_function(environment_t *environment)
{
    while (environment != NULL) {
        my_putstr(environment->part_of_env);
        write(1, "\n", 1);
        environment = environment->next;
    }
    return SUCCESS;
}
