/*
** EPITECH PROJECT, 2019
** rm_space.
** File description:
** rm_space.
*/

#include "my_shell2.h"

void str_clean(shell_t *po)
{
    po->buffer = rm_tab(po->buffer);
    po->buffer = rm_low_space(po->buffer);
    po->buffer = rm_up_space(po->buffer);
    po->buffer = rm_space(po->buffer);
}

char *rm_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t') {
            str[i] = ' ';
        }
    return (str);
}

char *rm_space(char *str)
{
    int j = 0;
    char *newstr = my_calloc(sizeof(char) * 1000);

    for (int i = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ') {
            newstr[j] = ' ';
            j++;
            for (; str[i] == ' '; i++);
        }
        newstr[j] = str[i];
    }
    newstr[j] = '\0';
    str = newstr;
    return (str);
}

char *rm_up_space(char * str)
{
    int index = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            index = i;
    }
    str[index + 1] = '\0';
    return (str);
}

char *rm_low_space(char * str)
{
    int index = 0;
    int i = 0;

    while (str[index] == ' ')
        index++;
    if (index != 0) {
        while (str[i + index] != '\0') {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0';
    }
    return (str);
}
