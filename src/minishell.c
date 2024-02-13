/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_macros.h"
#include "display_functions.h"
#include "my.h"
#include "recup_function.h"

static int main_loop(void)
{
    char **arr = NULL;

    while (1) {
        display_prompt();
        arr = recup_function();
        if (arr == NULL || arr[0] == NULL)
            return -1;
        if (my_strcmp(arr[0], "exit") == 0)
            return SUCCESS;
    }
    return SUCCESS;
}

int minishell(char **env)
{
    if (main_loop() == -1)
        return FAILURE;
    return SUCCESS;
}
