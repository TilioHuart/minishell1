/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin.h
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

int cd_function(char **arr, UNUSED environment_t *environment);
int env_function(char **arr, environment_t *environment);
int setenv_function(char **arr, UNUSED environment_t *environment);
int unsetenv_function(char **arr, UNUSED environment_t *environment);
int init_builtin(builtin_t *builtin);

#endif
