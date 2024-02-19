/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** use_functions.c
*/

#include "environment.h"
#include "my_macros.h"
#include "my.h"
#include "which_function.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int use_function(char **arr, environment_t *environment)
{
    char *path = NULL;

    for (size_t i = 0; arr[i] != NULL; i++) {
        my_putstr(arr[i]);
        write(1, "\n", 1);
    }
    path = which_function(arr, environment);
    printf("path = %s\n", path);
    free(path);
    return SUCCESS;
}
