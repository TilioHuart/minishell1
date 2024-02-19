/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** transform_env_to_arr.c
*/

#include "environment.h"
#include "my_macros.h"
#include <my.h>
#include <stdio.h>
#include <stdlib.h>

static int assign_str(environment_t *environment, char *str)
{
    size_t a = 0;

    for (size_t i = 0; environment->key[i] != '\0'; i++) {
        str[a] = environment->key[i];
        a += 1;
    }
    str[a] = '=';
    a += 1;
    for (size_t i = 0; environment->value[i] != '\0'; i++) {
        str[a] = environment->value[i];
        a += 1;
    }
    str[a] = '\0';
    return SUCCESS;
}

static char *concatenate_str(environment_t *environment)
{
    char *str = NULL;
    size_t len_key = 0;
    size_t len_value = 0;

    if (environment->key == NULL || environment->value == NULL)
        return NULL;
    len_key = my_strlen(environment->key);
    len_value = my_strlen(environment->value);
    str = malloc(sizeof(char) * (len_key + len_value + 2));
    assign_str(environment, str);
    return str;
}

char **transform_env_to_arr(environment_t *environment)
{
    char **env = NULL;
    environment_t *head = environment;
    size_t count = 0;
    size_t i = 0;

    if (environment == NULL)
        return NULL;
    while (environment->next != NULL) {
        count += 1;
        environment = environment->next;
    }
    environment = head;
    env = malloc(sizeof(char *) * (count + 2));
    env[i + 1] = NULL;
    while (environment != NULL) {
        env[i] = concatenate_str(environment);
        i += 1;
        environment = environment->next;
    }
    return env;
}
