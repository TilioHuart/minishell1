/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtin.h
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

int cd_function(UNUSED environment_t *environment);
int env_function(environment_t *environment);
int setenv_function(UNUSED environment_t *environment);
int unsetenv_function(UNUSED environment_t *environment);
int init_builtin(builtin_t *builtin);

#endif
