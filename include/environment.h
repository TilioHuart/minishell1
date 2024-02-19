/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** environment.h
*/

#ifndef ENVIRONMENT_H_
    #define ENVIRONMENT_H_

typedef struct environment {
    char *key;
    char *value;
    struct environment *next;
} environment_t;

environment_t *copy_env(char **env);
char **transform_env_to_arr(environment_t *environment);

#endif
