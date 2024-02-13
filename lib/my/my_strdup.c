/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strdup.c
*/

#include "stdlib.h"
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int len = 0;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    str = malloc(sizeof(char) * (len + 1));
    while (src[i] != '\0') {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return str;
}
