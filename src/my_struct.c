/*
** EPITECH PROJECT, 2019
** my_struct.c
** File description:
** my_struct.c
*/

#include "my_shell2.h"

shell_t *my_struct(shell_t *po)
{
    po = malloc(sizeof(shell_t));
    po->status = 0;
    po->j = 0;
    po->check = 0;
    po->bufsize = 20;
    po->retrn = 0;
    po->buffer = malloc(sizeof(char) * po->bufsize);

    return (po);
}
