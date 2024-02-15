/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int unsetenv_function(char **arr, environment_t *environment)
{
    write(1, "unsetenv", 8);
    return SUCCESS;
}
