/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_function.c
*/

#include "my_macros.h"
#include <unistd.h>

int env_function(void)
{
    write(1, "env\n", 4);
    return SUCCESS;
}
