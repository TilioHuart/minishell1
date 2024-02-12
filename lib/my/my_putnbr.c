/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <unistd.h>
#include <stdio.h>

void reduce(int *n, int *temp)
{
    if (*n < 0) {
        *n = *n * (-1);
        *temp = *n;
        write(1, "-", 1);
    }
}

int my_putnbr(int n)
{
    int nb = 48;
    int div = 1;
    int temp = n;
    int count = 0;

    reduce(&n, &temp);
    while (temp >= 10) {
        temp /= 10;
        div *= 10;
    }
    while (div > 0) {
        nb = '0' + (n / div);
        write(1, &nb, 1);
        n %= div;
        div /= 10;
        count += 1;
    }
    return count;
}
