/*
** EPITECH PROJECT, 2019
** my_strcat.
** File description:
** my_strcat.
*/

#include "my_shell2.h"

char *my_strcat(char *str1, char *str2)
{
    char *str3 = my_calloc(sizeof(char) * my_strlen(str1) +
    my_strlen(str2) + 2);
    int i = 0;
    int j = 0;
    int po = 0;

    for (i = 0; str1[i] != '\0'; i++) {
        str3[i] = str1[i];
        po = i;
    }
    po++;
    str3[po] = '/';
    po++;
    for (j = 0; str2[j] != '\0'; j++) {
        str3[po] = str2[j];
        po++;
    }
    return (str3);
}
