/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macros.h"
#include "display_functions.h"
#include "my.h"
#include "recup_function.h"
#include "minishell.h"
#include "builtin.h"

static int main_loop(void)
{
    char **arr = NULL;
    builtin_t *builtin = malloc(sizeof(builtin_t) * 5);

    while (1) {
        display_prompt();
        arr = recup_function();
        if (arr == NULL || arr[0] == NULL) {
            free(builtin);
            return -1;
        }
        if (my_strcmp(arr[0], "exit") == 0)
            break;
        loop_builtin(builtin, arr);
    }
    free(builtin);
    return SUCCESS;
}

int minishell(char **env)
{
    if (main_loop() == -1)
        return FAILURE_EPITECH;
    return SUCCESS;
}
