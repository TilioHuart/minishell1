/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** display_functions.c
*/

#include <unistd.h>

void display_prompt(void)
{
    write(1, "$> ", 3);
}
