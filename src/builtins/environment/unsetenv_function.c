/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include <unistd.h>

int unsetenv_function(UNUSED char **arr, UNUSED environment_t *environment)
{
    write(1, "unsetenv", 8);
    return SUCCESS;
}
