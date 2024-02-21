/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** which_function.c
*/

#include "environment.h"
#include "my_macros.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static
int assign_function_to_path(char **arr, char *path, size_t *a)
{
    for (size_t y = 0; arr[0][y] != '\0'; y++) {
        path[*a] = arr[0][y];
        *a += 1;
    }
    return SUCCESS;
}

static
char *retrieve_binary(char **arr, char **path_arr, size_t const *i)
{
    size_t len_path = 0;
    size_t len_arr = 0;
    size_t a = 0;
    char *path = NULL;

    len_path = my_strlen(path_arr[*i]);
    len_arr = my_strlen(arr[0]);
    if (path != NULL)
        free(path);
    path = malloc(sizeof(char) * (len_arr + len_path + 2));
    for (size_t y = 0; path_arr[*i][y] != '\0'; y++) {
        path[a] = path_arr[*i][y];
        a += 1;
    }
    path[a] = '/';
    a += 1;
    assign_function_to_path(arr, path, &a);
    path[a] = '\0';
    a = 0;
    return path;
}

static int check_file(char *path)
{
    if (path == NULL) {
        return FAILURE;
    }
    if (access(path, F_OK | X_OK) == 0) {
        return 1;
    }
    return FAILURE;
}

static char *concatenate_path(char **arr, char **path_arr)
{
    char *path = NULL;

    if (arr == NULL || path_arr == NULL || arr[0] == NULL)
        return NULL;
    for (size_t i = 0; path_arr[i] != NULL; i++) {
        path = retrieve_binary(arr, path_arr, &i);
        if (check_file(path) == 1)
            return path;
        free(path);
    }
    return NULL;
}

static char *loop_in_path(char **arr, environment_t *environment)
{
    char *path = NULL;
    char **path_arr = NULL;
    char *file = NULL;

    if (environment == NULL)
        return NULL;
    path = my_strdup(environment->value);
    for (size_t i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':')
            path[i] = ' ';
    }
    path_arr = my_str_to_word_array(path);
    file = concatenate_path(arr, path_arr);
    free(path);
    if (path_arr != NULL) {
        for (size_t i = 0; path_arr[i] != NULL; i += 1)
            free(path_arr[i]);
    free(path_arr);
    }
    return file;
}

char *which_function(char **arr, environment_t *environment)
{
    environment_t *head = environment;
    char *path = NULL;

    if (arr == NULL)
        return NULL;
    while (environment->next != NULL) {
        environment = environment->next;
        if (my_strcmp(environment->key, "PATH") == 0)
            break;
    }
    path = loop_in_path(arr, environment);
    environment = head;
    return path;
}
