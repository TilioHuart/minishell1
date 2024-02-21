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

typedef struct loop {
    int stop;
} loop_t;

typedef struct builtin {
    char *function;
    int (*pftc) (char **arr, environment_t *environment, loop_t *loop);
} builtin_t;

int loop_builtin(builtin_t *builtin, char **arr,
    environment_t *environment, loop_t *loop);
int if_tty(void);

#endif
