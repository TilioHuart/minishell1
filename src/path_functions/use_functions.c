/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** use_functions.c
*/

#include "environment.h"
#include "my.h"
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

static char *check_file_at_root(char **arr)
{
    if (arr == NULL || arr[0] == NULL)
        return NULL;
    if (my_strlen(arr[0]) < 3)
        return NULL;
    if (access(arr[0] + 2, F_OK | X_OK) == 0)
        return my_strdup(arr[0] + 2);
    return NULL;
}

static int file_at_root(char **path, char **arr)
{
    if (*path == NULL)
        *path = check_file_at_root(arr);
    if (*path == NULL)
        return FAILURE;
    return SUCCESS;
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
    if (file_at_root(&path, arr) == FAILURE)
        return FAILURE;
    env = transform_env_to_arr(environment);
    pid = fork();
    if (pid == 0) {
        execve(path, arr, env);
    } else {
        waitpid(-1, &wstatus, 0);
        free(path);
        free_env(&env);
    }
    return SUCCESS;
}
