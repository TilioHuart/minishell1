/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** copy_env.c
*/

#include "my_macros.h"
#include "environment.h"
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

static environment_t *create_list_env(char *part_of_env)
{
    environment_t *environment;
    char *key = NULL;
    char *value = NULL;
    size_t i = 0;

    environment = malloc(sizeof(environment_t));
    if (environment == NULL)
        return NULL;
    key = malloc(sizeof(char) * (strlen_key(part_of_env) + 1));
    key = assign_key(part_of_env, key, &i);
    value = malloc(sizeof(char) * (strlen_value(part_of_env) + 1));
    i += 1;
    value = assign_value(part_of_env, value, &i);
    environment->key = key;
    environment->value = value;
    environment->next = NULL;
    return environment;
}

static void adding_values_to_list(environment_t *tmp, char *key, char *value)
{
    tmp->key = key;
    tmp->value = value;
    tmp->next = NULL;
}

static int adding_elem_to_list(environment_t *environment, char *part_of_env)
{
    environment_t *head = environment;
    environment_t *tmp = malloc(sizeof(environment_t));
    char *key = NULL;
    char *value = NULL;
    size_t i = 0;

    if (tmp == NULL || part_of_env == NULL)
        return FAILURE;
    while (environment->next != NULL)
        environment = environment->next;
    environment->next = tmp;
    key = malloc(sizeof(char) * (strlen_key(part_of_env) + 1));
    key = assign_key(part_of_env, key, &i);
    value = malloc(sizeof(char) * (strlen_value(part_of_env) + 1));
    i += 1;
    value = assign_value(part_of_env, value, &i);
    adding_values_to_list(tmp, key, value);
    environment = head;
    return SUCCESS;
}

static int adding_env_to_list(environment_t *environment, char **env)
{
    if (environment == NULL || env == NULL)
        return FAILURE;
    for (size_t i = 1; env[i] != NULL; i++) {
        adding_elem_to_list(environment, env[i]);
    }
    return SUCCESS;
}

environment_t *copy_env(char **env)
{
    environment_t *environment = NULL;

    if (env == NULL || env[0] == NULL)
        return NULL;
    environment = create_list_env(env[0]);
    if (adding_env_to_list(environment, env) == FAILURE)
        return NULL;
    return environment;
}
