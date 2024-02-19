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
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int use_function(char **arr, environment_t *environment)
{
    char *path = NULL;
    char **env = NULL;
    int pid = getpid();
    int wstatus = 0;

    path = which_function(arr, environment);
    env = transform_env_to_arr(environment);
    if (path == NULL)
        return FAILURE;
    pid = fork();
    if (pid == 0) {
        execve(path, arr, env);
    } else {
        waitpid(-1, &wstatus, 0);
    }
    free(path);
    return SUCCESS;
}
