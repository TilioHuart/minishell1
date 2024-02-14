/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include <unistd.h>

int setenv_function(UNUSED environment_t *environment)
{
    write(1, "setenv\n", 7);
    return SUCCESS;
}
