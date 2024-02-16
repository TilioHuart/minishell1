/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_function.c
*/

#include "my_macros.h"
#include "environment.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static ssize_t strlen_key(char *part_of_env)
{
    ssize_t i = 0;

    if (part_of_env == NULL)
        return -1;
    for (; part_of_env[i] != '='; i++);
    return i;
}

static ssize_t strlen_value(char *part_of_env)
{
    ssize_t i = strlen_key(part_of_env);
    ssize_t count = 0;

    if (part_of_env == NULL)
        return -1;
    for (; part_of_env[i] != '\0'; i++)
        count += 1;
    return count;
}

static char *assign_key(char const *part_of_env, char *key, size_t *i)
{
    if (part_of_env == NULL || key == NULL)
        return NULL;
    for (; part_of_env[*i] != '='; *i += 1) {
        key[*i] = part_of_env[*i];
    }
    key[*i] = '\0';
    return key;
}

static char *assign_value(char const *part_of_env, char *key, size_t *i)
{
    size_t a = 0;

    if (part_of_env == NULL || key == NULL)
        return NULL;
    for (; part_of_env[*i] != '\0'; *i += 1) {
        key[a] = part_of_env[*i];
        a += 1;
    }
    key[a] = '\0';
    return key;
}

static
int adding_elem_with_setenv(environment_t *environment, char **arr)
{
    environment_t *head = environment;
    environment_t *tmp = malloc(sizeof(environment_t));
    environment_t *tmp2 = NULL;
    char *key = NULL;
    char *value = NULL;
    size_t i = 0;

    if (tmp == NULL || arr == NULL)
        return FAILURE;
    while (environment->next != NULL) {
        if (my_strcmp(environment->next->key, arr[1]) == 0) {
            tmp2 = environment->next->next;
            break;
        }
        environment = environment->next;
    }
    environment->next = tmp;
    tmp->key = my_strdup(arr[1]);
    tmp->value = my_strdup(arr[2]);
    tmp->next = tmp2;
    environment = head;
    return SUCCESS;
}

int setenv_function(char **arr, UNUSED environment_t *environment)
{
    char *str = NULL;
    size_t len1 = 0;
    size_t len2 = 0;

    if (arr == NULL)
        return FAILURE;
    if (arr[1] == NULL)
        return SUCCESS;
    adding_elem_with_setenv(environment, arr);
    return SUCCESS;
}
