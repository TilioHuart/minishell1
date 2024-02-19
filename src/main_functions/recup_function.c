/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** recup_function.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_macros.h"
#include "minishell.h"

static int remove_linebreak(char *str)
{
    if (str == NULL)
        return -1;
    for (size_t i = 0; str[i] != '\0'; i += 1)
        if (str[i] == '\n')
            str[i] = '\0';
    return SUCCESS;
}

char **recup_function(int *stop)
{
    char **arr = NULL;
    char *buff = NULL;
    size_t len = 0;

    if (getline(&buff, &len, stdin) == -1) {
        if (if_tty() == SUCCESS) {
            *stop = 1;
            return NULL;
        }
        return NULL;
    }
    remove_linebreak(buff);
    arr = my_str_to_word_array(buff);
    free(buff);
    return arr;
}
