/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** use_functions.c
*/

#include "environment.h"
#include "my_macros.h"
#include "my.h"
#include <unistd.h>

int use_function(char **arr, UNUSED environment_t *environment)
{
    for (size_t i = 0; arr[i] != NULL; i++) {
        my_putstr(arr[i]);
        write(1, "\n", 1);
    }
    return SUCCESS;
}
