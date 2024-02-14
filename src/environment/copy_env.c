/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** copy_env.c
*/

#include "my_macros.h"
#include "environment.h"
#include "my.h"
#include <stdlib.h>

static environment_t *create_list_env(char *part_of_env)
{
    environment_t *environment;

    environment = malloc(sizeof(environment_t));
    environment->part_of_env = part_of_env;
    environment->next = NULL;
    return environment;
}

static int adding_elem_to_list(environment_t *environment, char *part_of_env)
{
    environment_t *head = environment;
    environment_t *tmp = malloc(sizeof(environment_t));

    if (tmp == NULL || part_of_env == NULL)
        return FAILURE;
    while (environment->next != NULL)
        environment = environment->next;
    environment->next = tmp;
    tmp->part_of_env = my_strdup(part_of_env);
    tmp->next = NULL;
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
