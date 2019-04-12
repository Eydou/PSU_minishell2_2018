/*
** EPITECH PROJECT, 2019
** strcut.
** File description:
** strcut.
*/

#include "my_shell2.h"

char *my_strcut(char *buffer, char *binary)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\0')
            return (binary);
        binary[i] = buffer[i];
    }
    return (binary);
}
