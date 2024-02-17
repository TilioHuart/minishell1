/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** bsminishell1
*/

#include <unistd.h>
#include <sys/wait.h>
#include "my_macros.h"
#include "minishell.h"

int main(UNUSED int argc, UNUSED char **argv, char **env)
{
    return minishell(env);
}
