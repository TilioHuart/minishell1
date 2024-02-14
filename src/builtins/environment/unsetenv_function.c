/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include <unistd.h>

int unsetenv_function(UNUSED environment_t *environment)
{
    write(1, "unsetenv\n", 9);
    return SUCCESS;
}
