/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.h
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include "environment.h"
int minishell(char **env);

typedef struct builtin {
    char *function;
    int (*pftc) (environment_t *environment);
} builtin_t;

int loop_builtin(builtin_t *builtin, char **arr, environment_t *environment);

#endif
