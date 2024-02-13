/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Write your my.h header file that
** contains the prototypes of
** all the functions exposed by your libmy.a
*/

#ifndef MY_H_
    #define MY_H_

int my_strlen(char const *str);
int my_putstr(char const *str);
char **my_str_to_word_array(char const *str);
int my_putnbr(int n);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);

#endif /* MY_H_ */
