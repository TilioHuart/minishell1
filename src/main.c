/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** bsminishell1
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_macros.h"
#include "minishell.h"
#include "my.h"

int main(UNUSED int argc, UNUSED char **argv, char **env)
{
    return minishell(env);
}
