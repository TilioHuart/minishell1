/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell.h
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

int minishell(char **env);

typedef struct builtin {
    char *function;
    int (*pftc) (void);
} builtin_t;

int loop_builtin(builtin_t *builtin, char **arr);

#endif
