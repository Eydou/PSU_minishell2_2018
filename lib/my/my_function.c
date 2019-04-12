/*
** EPITECH PROJECT, 2019
** my_function.c
** File description:
** my_function.c
*/

#include "my_shell2.h"
#include <unistd.h>

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    str[0] == '-' ? neg = -1 : neg;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        i = i + 1;
    }
    return (nb * neg);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else {
        if (nb < 10) {
            my_putchar(nb + 48);
        } else {
            my_put_nbr(nb / 10);
            my_put_nbr(nb % 10);
        }
    }
    return (0);
}
