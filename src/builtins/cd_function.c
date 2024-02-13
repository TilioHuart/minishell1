/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** cd_function.c
*/

#include "my_macros.h"
#include <unistd.h>

int cd_function(void)
{
    write(1, "cd\n", 3);
    return SUCCESS;
}
