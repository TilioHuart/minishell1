/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;
    char c;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i += 1) {
        c = str[i];
        write(1, &c, 1);
    }
    return i;
}
