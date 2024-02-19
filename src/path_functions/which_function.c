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
int retrieve_binary(char **arr, char **path_arr, char *path, size_t const *i)
{
    size_t len_path = 0;
    size_t len_arr = 0;
    size_t a = 0;

    len_path = my_strlen(path_arr[*i]);
    len_arr = my_strlen(arr[0]);
    if (path != NULL)
        free(path);
    path = malloc(sizeof(char) * (len_arr + len_path + 1));
    for (size_t y = 0; path_arr[*i][y] != '\0'; y++) {
        path[a] = path_arr[*i][y];
        a += 1;
    }
    path[a] = '/';
    a += 1;
    for (size_t y = 0; arr[0][y] != '\0'; y++) {
        path[a] = arr[0][y];
        a += 1;
    }
    path[a] = '\0';
    a = 0;
    printf("path1 = %s\n", path);
    return SUCCESS;
}

static int concatenate_path(char **arr, char **path_arr)
{
    char *path = NULL;

    if (arr == NULL || path_arr == NULL || arr[0] == NULL)
        return FAILURE;
    for (size_t i = 0; path_arr[i] != NULL; i++) {
        retrieve_binary(arr, path_arr, path, &i);
    }
    return SUCCESS;
}

static int loop_in_path(char **arr, environment_t *environment)
{
    char *path = NULL;
    char **path_arr = NULL;

    if (environment == NULL)
        return FAILURE;
    path = my_strdup(environment->value);
    for (size_t i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':')
            path[i] = ' ';
    }
    path_arr = my_str_to_word_array(path);
    concatenate_path(arr, path_arr);
    return SUCCESS;
}

int which_function(char **arr, environment_t *environment)
{
    environment_t *head = environment;

    if (arr == NULL)
        return FAILURE;
    while (environment->next != NULL) {
        environment = environment->next;
        if (my_strcmp(environment->key, "PATH") == 0)
            break;
    }
    loop_in_path(arr, environment);
    environment = head;
    return SUCCESS;
}
