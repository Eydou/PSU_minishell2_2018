/*
** EPITECH PROJECT, 2019
** my_strcmp.
** File description:
** my_strcmp.
*/

#include "my_shell2.h"

int my_strcmp(char *str, char *cmp)
{
    if (my_strlen(str) != my_strlen(cmp))
        return (1);
    for (int i = 0; str[i] && cmp[i] != '\0'; i++) {
        if (str[i] != cmp[i])
            return (1);
    }
    return (0);
}
