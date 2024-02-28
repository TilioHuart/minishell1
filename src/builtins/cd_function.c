/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** cd_function.c
*/

#include "minishell.h"
#include "my.h"
#include "my_macros.h"
#include "environment.h"
#include <unistd.h>

static int cd_home(environment_t *environment, loop_t *loop)
{
    while (environment->next != NULL) {
        if (my_strcmp(environment->key, "HOME") == 0)
            break;
        environment = environment->next;
    }
    if (my_strcmp(environment->key, "HOME") != 0)
        return FAILURE;
    if (environment->value != NULL)
        if (chdir(environment->value) == -1) {
            write(1, environment->key, my_strlen(environment->key));
            my_putstr(": No such file or directory.\n");
            loop->return_value = 1;
        }
    return SUCCESS;
}

static int case_of_to_many_args(char **arr, loop_t *loop)
{
    if (arr == NULL || loop == NULL)
        return FAILURE;
    for (int i = 0; arr[i] != NULL; i += 1) {
        if (i > 1) {
            write(1, arr[0], my_strlen(arr[0]));
            my_putstr(": Too many arguments.\n");
            loop->return_value = 1;
            return 1;
        }
    }
    return SUCCESS;
}

int cd_function(UNUSED char **arr,
    UNUSED environment_t *environment, loop_t *loop)
{
    if (arr == NULL)
        return FAILURE;
    if (arr[1] == NULL) {
        cd_home(environment, loop);
        return SUCCESS;
    }
    if (my_strcmp(arr[1], "~") == 0) {
        cd_home(environment, loop);
        return SUCCESS;
    }
    if (case_of_to_many_args(arr, loop) == 1)
        return SUCCESS;
    if (chdir(arr[1]) == -1) {
        write(1, arr[1], my_strlen(arr[1]));
        my_putstr(": No such file or directory.\n");
        loop->return_value = 1;
    }
    return SUCCESS;
}
