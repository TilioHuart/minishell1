/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin.h
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

int cd_function(char **arr, UNUSED environment_t *environment,
    UNUSED loop_t *loop);
int env_function(char **arr, environment_t *environment,
    UNUSED loop_t *loop);
int setenv_function(char **arr, UNUSED environment_t *environment,
    UNUSED loop_t *loop);
int unsetenv_function(char **arr, UNUSED environment_t *environment,
    UNUSED loop_t *loop);
int init_builtin(builtin_t *builtin);
int exit_function(UNUSED char **arr, UNUSED environment_t *environment,
    loop_t *loop);

#endif
