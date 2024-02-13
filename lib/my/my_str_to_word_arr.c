/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static ssize_t my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i += 1);
    return i;
}

static size_t is_not_separator(char c)
{
    if (c != ' ' && c != '\0') {
        return 0;
    } else {
        return 1;
    }
}

static void find_len(char const *str, size_t *len, size_t *y)
{
    if (is_not_separator(str[*y]) == 0)
        *len += 1;
}

static void alloc_str_in_arr(char **arr, size_t const *len, size_t const *i)
{
    if (*len > 0) {
        arr[*i] = malloc(sizeof(char) * (*len + 1));
        if (arr[*i] == NULL)
            return;
        arr[*i][*len] = '\0';
    }
}

static char **create_arr(char const *str)
{
    char **arr = NULL;
    size_t count = 0;
    size_t len = 0;
    size_t y = 0;

    if (str == NULL)
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (is_not_separator(str[i]) == 1)
            count += 1;
    arr = malloc(sizeof(char *) * (count + 2));
    arr[count + 2] = NULL;
    for (size_t i = 0; i < (count + 1); i++) {
        for (; str[y] != ' ' && str[y] != '\0'; y++)
            find_len(str, &len, &y);
        y += 1;
        alloc_str_in_arr(arr, &len, &i);
        len = 0;
    }
    return arr;
}

static ssize_t assign_str_to_arr(char **arr, char const *str)
{
    size_t a = 0;
    size_t y = 0;

    if (arr == NULL && str == NULL)
        return -1;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (is_not_separator(str[i]) == 0 &&
            is_not_separator(str[i + 1]) == 0) {
            arr[a][y] = str[i];
            y += 1;
        }
        if (is_not_separator(str[i]) == 0 &&
            is_not_separator(str[i + 1]) == 1) {
            arr[a][y] = str[i];
            a += 1;
            y = 0;
        }
    }
    return 0;
}

char **my_str_to_word_array(char const *str)
{
    char **arr = NULL;

    if (str == NULL)
        return NULL;
    arr = create_arr(str);
    if (assign_str_to_arr(arr, str) == -1)
        return NULL;
    return arr;
}
