/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_function.c
*/

#include "my_macros.h"
#include <unistd.h>

int setenv_function(void)
{
    write(1, "setenv\n", 7);
    return SUCCESS;
}
