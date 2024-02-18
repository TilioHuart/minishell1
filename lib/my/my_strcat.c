/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Write a function that
** concatenates two strings.
*/

int my_strlen_cat(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1);
    return i;
}

char *my_strcpy_cat(char *dest, char const *src)
{
    int y = 0;

    while (src[y] != '\0') {
        dest[y] = src[y];
        y += 1;
    }
    dest[y] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    my_strcpy_cat(dest + my_strlen_cat(dest), src);
    return dest;
}
