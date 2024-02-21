/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** use_functions.c
*/

#include "environment.h"
#include "my_macros.h"
#include "which_function.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void free_env(char ***env)
{
    if (*env != NULL)
        for (size_t i = 0; (*env)[i] != NULL; i += 1)
            free((*env)[i]);
    free(*env);
}

int use_function(char **arr, environment_t *environment)
{
    char *path = NULL;
    char **env = NULL;
    int pid = getpid();
    int wstatus = 0;

    if (arr == NULL || arr[0] == NULL)
        return FAILURE;
    path = which_function(arr, environment);
    if (path == NULL)
        return FAILURE;
    env = transform_env_to_arr(environment);
    pid = fork();
    if (pid == 0) {
        execve(path, arr, env);
    } else {
        waitpid(-1, &wstatus, 0);
    }
    free(path);
    free_env(&env);
    return SUCCESS;
}
